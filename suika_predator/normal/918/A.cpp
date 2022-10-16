#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
int f[233],g[23333];
int main()
{
	f[1]=f[2]=1;g[1]=1;
	for(int i=3;i<=20;i++)f[i]=f[i-1]+f[i-2],g[f[i]]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(g[i])printf("O");
		else printf("o");
	}
	return 0;
}