#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
using namespace std;
#define ll long long
#define mp make_pair
#define X first
#define Y second
const int N=100008;
int n,m,tot,f[N];
string b[N],c[N];
struct aa{int a[27];}a[N*20];
void insert(int k,int x,int y)
{
	if(y==(int)c[x].length()){a[k].a[0]=x;return;}
	int p;
	if(a[k].a[p=c[x][y]-'a'+1]==0){a[k].a[p]=++tot;}
	insert(a[k].a[p],x,y+1);
	return;
}
int dfs(int x)
{
	if(x==0)return 0;
	dfs(x-b[f[x]].size());
	cout<<b[f[x]]<<' ';
	return 0;
}
int main(void)
{
	int i,j,k,p;
	std::ios::sync_with_stdio(false);
	cin>>n>>b[0]>>m;
	for(i=1;i<=m;i++)
	{
		cin>>b[i];c[i]=string("");
		for(j=b[i].length()-1;j>=0;j--)
		if('a'<=b[i][j]&&b[i][j]<='z')c[i]+=b[i][j];
		else c[i]+=b[i][j]+('a'-'A');
	}
	tot=0;
	for(i=1;i<=m;i++)insert(0,i,0);
	f[0]=1;
	for(i=0;i<n;i++)if(f[i])
	{
		k=0;
		for(j=i+1;j<=n;j++)
		{
			if(a[k].a[p=b[0][j-1]-'a'+1])k=a[k].a[p];
			else break;
			if(a[k].a[0])f[j]=a[k].a[0];
		}
	}
	dfs(n);
	return 0;
}