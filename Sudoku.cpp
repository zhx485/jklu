#include <iostream>
#include<fstream>
#include<string>
#include<cstdio>
int m=0, n=0;
int weizhi[2] = { 0 };
using namespace std;
string k1,k2;
int bp[90][11];
void intxt(string h) {
	int k;
	char filename[10] ; //文件名
	for (k = 0; k < h.length(); k++) //string => char[]
	{
		filename[k] = h[k];
	}
	filename[k] = '\0';
	FILE* fp;
	char StrLine[1024];
	fp = fopen(filename, "a+"); //判断文件是否存在及可读
	int i ,j;
	for (int time = 0; time < n; time++)
	{
		for (i = m*time; i < m*(time+1); i++)
		{
			for (j = 0; j < m; j++)
			{
				fscanf(fp, "%d", &bp[i][j]);
			}
		}
	}
	i = 0;
	fclose(fp);
}

int fuhe(int j,int g,int sk,int jk){
	int gong(int j, int g);
	int flag = 0;
	bp[j][g] = sk;
for (int u = 0; u < m ; u ++)
{
	if (bp[j][g] == bp[j][u] && g != u)//行相等
	{
		flag = 1;
		return (-1);
	}
}

for (int u = 0; u < m; u++)
{
	if (bp[j][g] == bp[u+jk*m][g] && j != (u+jk*m))//列相等
	{
		flag = 1;
		return (-1);
	}
}
if (gong(j, g) == -1) return (-1);//宫符合
return 1;}
int main()
{
	int gong(int j, int g);
	int dfs(int io,int jk);
	char qi[4][8] = {0};
	string h, h1;
	for (int i = 0; i < 4; i++)                 //4种命令
	{
		cin >> qi[i][0] >> qi[i][1];
		switch (qi[i][1])
		{
		case 'i': cin >> k1; continue;
		case 'm': cin >> m; continue;
		case 'n': cin >> n; continue;
		case 'o': cin >> k2; continue;
		default: cout << "error"<<endl; 
			break;
		}
	}
	intxt(k1);//读表盘
	char outname[20];//输出
	for (int y = 0; y < k2.length(); y++)
	{
		outname[y] = k2[y];
	}
	outname[k2.length()] = '\0';
	for (int i = 0; i < n; i++)
	{

		int j, f, g;
		if (dfs(1,i))
		cout << " success"<<endl;
		FILE* fp;
		if ((fp = fopen(outname, "a+")) == NULL) //创建输出文件
		{
			printf("error!");
		}
		for (int il = i*m; il < m*(i+1); il++)
		{
			for (int j = 0; j < m; j++)
				if (j != m - 1)fprintf(fp, "%d ", bp[il][j]);
				else fprintf(fp, "%d\n", bp[il][j]);
		}

	}
	
	return 0;
}
int gong(int j,int g) {
	int x, y;
	if (m == 4)
	{
		x = (j / 2) * 2;
		y = (g / 2) * 2;
		for (int i = x; i < x + 2; i++)
		{
			for (int o = y; o < y + 2; o++)
			{
				if (bp[j][g] == bp[i][o] && (j != i || g != o)) return (-1);
			}
		}
	}
	if (m == 6)
	{
		x = (j / 2) * 2;
		y = (g / 3) * 3;
		for (int i = x; i < x + 2; i++)
		{
			for (int o = y; o < y + 3; o ++)
			{
				if (bp[j][g] == bp[i][o] && (j != i || g != o)) return (-1);
			}
		}
	}
	if (m == 8)
	{
		x = (j / 4) * 4;
		y = (g / 2) * 2;
		for (int i = x; i < x + 4; i++)
		{
			for (int o = y; o < y + 2; o ++)
			{
				if (bp[j][g] == bp[i][o] && (j != i || g != o)) return (-1);
			}
		}
	}
	if (m == 9)
	{
		x = (j / 3) * 3;
		y = (g / 3) * 3;
		for (int i = x; i < x + 3; i++)
		{
			for (int o = y; o < y + 3; o ++)
			{
				if (bp[j][g] == bp[i][o] && (j != i || g != o)) return (-1);
			}
		}
	}
	return (1);
}
int dfs(int io,int jk) {//dfs深度搜索
	int x = (io-1)/m+jk*m;
	int y = ((io-1) % m);
	if (io > m * m )   // 结束了
		return 1;
	if (bp[x][y] != 0) {
		return dfs(io + 1,jk);
	}
	else {
		for (int uo = 1; uo <= m; uo++)
		{
			
			if (fuhe(x, y, uo,jk) == 1) {
				bp[x][y] = uo ;
				if (dfs(io + 1,jk))
					return 1;
			}
			bp[x][y] = 0;
		}
	}
	return 0;
}

