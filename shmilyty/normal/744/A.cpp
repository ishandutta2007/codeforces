#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,m,k,maxd,maxe,sumd,sume,ans,c[1001],fa[1001],sz[1001],e[1001];
pair<int,int> p[100001];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int calc(int x,int y)
{
	return (x-1)*x/2-y;
}
signed main()
{
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=k;i++)
		c[i]=read();
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		p[i].first=read();
		p[i].second=read();
		fa[find(p[i].first)]=find(p[i].second);
	}
	for(int i=1;i<=n;i++)
		sz[find(i)]++;
	for(int i=1;i<=m;i++)
		e[find(p[i].first)]++;
	for(int i=1;i<=k;i++)
	{
		sumd+=sz[find(c[i])];
		sume+=e[find(c[i])];
		ans+=calc(sz[find(c[i])],e[find(c[i])]);
		maxd=max(maxd,sz[find(c[i])]);
		maxe=max(maxe,sz[find(c[i])]);
	}
	ans+=calc(n-sumd,m-sume);
	cout<<ans+(n-sumd)*maxd;
	return 0;
}