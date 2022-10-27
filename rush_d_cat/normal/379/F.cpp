#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define ll long long
#define mp make_pair
#define X first
#define Y second
#define ll long long
const int N=1000008;
int n,m,a[N][2],f[N][21],dep[N];
int lca(int x,int y)
{
	int i,k;
	if(dep[x]>dep[y]){k=x;x=y;y=k;}
	for(i=20;i>=0;i--)if(dep[y]-(1<<i)>=dep[x])y=f[y][i];
	if(x==y)return x;
	for(i=20;i>=0;i--)if(f[x][i]!=f[y][i]){x=f[x][i];y=f[y][i];}
	return f[x][0];
}
int dis(int x,int y)
{
	int k=lca(x,y);
	return dep[x]+dep[y]-2*dep[k];
}
int main(void)
{
	int i,j,k,x,y,z,p;
	f[1][0]=0;f[2][0]=f[3][0]=f[4][0]=1;
	dep[1]=1;dep[2]=dep[3]=dep[4]=2;
	scanf("%d",&m);n=4;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&k);
		a[i][0]=n+1;a[i][1]=n+2;
		dep[n+1]=dep[n+2]=dep[k]+1;
		f[++n][0]=k;f[++n][0]=k;
	}
	for(i=1;i<=20;i++)for(j=1;j<=n;j++)f[j][i]=f[f[j][i-1]][i-1];
	x=2;y=3;z=2;
	for(i=1;i<=m;i++)
	{
		p=dis(x,a[i][0]);if(p>z){z=p;y=a[i][0];}
		p=dis(y,a[i][1]);if(p>z){z=p;x=a[i][1];}
		printf("%d\n",z);
	}
	return 0;
}