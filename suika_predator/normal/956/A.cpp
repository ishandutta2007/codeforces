#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
char a[233][233];
int ln[233];
inline bool cmp(int x,int y)
{
	for(int i=1;i<=m;i++)
		if(a[x][i]!=a[y][i])
		{
			printf("No\n");
			return false;
		}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf(" %s",a[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='#'&&!ln[j])ln[j]=i;
			else if(a[i][j]=='#'&&!cmp(i,ln[j]))return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='#'&&!ln[j])ln[j]=i;
			else if(a[i][j]=='#'&&!cmp(i,ln[j]))return 0;
		}
	}
	printf("Yes\n");
	return 0;
}