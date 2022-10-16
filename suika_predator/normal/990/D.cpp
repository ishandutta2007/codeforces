#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,a,b,r;
int mp[2333][2333];
inline void addedge(int u,int v){if(u!=v)mp[u][v]=mp[v][u]=1;}
inline void reverse()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
				mp[i][j]^=1;
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	if(a>=2&&b>=2)return printf("NO\n"),0;
	if(a>n||b>n)return printf("NO\n"),0;
	if(n==1)return printf("YES\n0\n"),0;
	if(n<=3&&b==1&&a==1)return printf("NO\n"),0;
	if(n==2)
	{
		if(a==1)return printf("YES\n01\n10\n"),0;
		else return printf("YES\n00\n00\n"),0;
	}
	if(a!=1)swap(a,b),r=1;
	for(int i=1;i<n;i++)addedge(i,i+1);
	if(n>=3)
	{
		for(int i=2;i<=b;i++)
		{
			for(int j=1;j<=n;j++)
			{
				addedge(i,j);
			}
		}
	}
	if(r)reverse();
	printf("YES\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d",mp[i][j]);
		}
		printf("\n");
	}
	return 0;
}