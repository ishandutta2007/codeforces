#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m,sw;
int board[233333],tmp[233333];
inline int f(int x,int y)
{
	return x*m-m+y;
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n==1&&m==1)return printf("YES\n1\n"),0;
	if(n>m)swap(n,m),sw=1;
	if((n==1&&m<=3)||(n==2&&m<=3))return printf("NO\n"),0;
	if(sw)swap(n,m);
	printf("YES\n");
	if(n==1&&m==4)
	{
		printf("2 4 1 3\n");
		return 0;
	}
	if(n==4&&m==1)
	{
		printf("2\n4\n1\n3\n");
		return 0;
	}
	if(n==2&&m==4)
	{
		printf("5 4 7 2\n3 6 1 8\n");
		return 0;
	}
	if(n==4&&m==2)
	{
		printf("2 5\n7 4\n6 1\n3 8\n");
		return 0;
	}
	if(n==3&&m==3)
	{
		printf("1 3 4\n5 7 6\n9 2 8\n");
		return 0;
	}
	if(n==3&&m==4)
	{
		printf("1 3 5 7\n9 11 2 4\n6 8 10 12\n");
		return 0;
	}
	if(n==4&&m==4)
	{
		printf("1 3 5 7\n9 11 13 15\n2 4 6 8\n10 12 14 16\n");
		return 0;
	}
	if(n==4&&m==3)
	{
		printf("1 3 5\n7 9 11\n2 4 6\n8 10 12\n");
		return 0;
	}
	if(n<=m)
	{
		for(int i=1;i<=n;i++)
		{
			int cur=0;
			for(int j=1;j<=m;j+=2)board[f(i,++cur)]=f(i,j);
			for(int j=2;j<=m;j+=2)board[f(i,++cur)]=f(i,j);
			if(i%2)
			{
				for(int j=1;j<=m;j++)tmp[f(i,j)]=board[f(i,j)];
				for(int j=1;j<=m;j++)board[f(i,j%m+1)]=tmp[f(i,j)];
			}
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			int cur=0;
			for(int j=1;j<=n;j+=2)board[f(++cur,i)]=f(j,i);
			for(int j=2;j<=n;j+=2)board[f(++cur,i)]=f(j,i);
			if(i%2)
			{
				for(int j=1;j<=n;j++)tmp[f(j,i)]=board[f(j,i)];
				for(int j=1;j<=n;j++)board[f(j%n+1,i)]=tmp[f(j,i)];
			}
		}
	}
	/*if(sw)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				tmp[f(j,i)]=board[f(i,j)];
			}
		}
		swap(n,m);
	}
	else*/
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				tmp[f(i,j)]=board[f(i,j)];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d ",board[f(i,j)]);
		}
		printf("\n");
	}
	return 0;
}