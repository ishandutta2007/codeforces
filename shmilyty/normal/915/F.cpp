#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
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
array<int,3> e[1000000];
int n,ans,a[1000001],sz[1000001],fa[1000001];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		e[i]={max(a[x],a[y]),x,y};
	}
	sort(e+1,e+n);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		sz[i]=1; 
	}
	for(int i=1;i<n;i++)
	{
		int x=e[i][1],y=e[i][2];
		ans+=e[i][0]*sz[find(x)]*sz[find(y)];
		sz[find(x)]+=sz[find(y)];
		fa[find(y)]=find(x);
	}
	for(int i=1;i<n;i++)
		e[i][0]=-min(a[e[i][1]],a[e[i][2]]);
	sort(e+1,e+n);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		sz[i]=1;
	}
	for(int i=1;i<n;i++)
	{
		int x=e[i][1],y=e[i][2];
		ans+=e[i][0]*sz[find(x)]*sz[find(y)]; 
		sz[find(x)]+=sz[find(y)];
		fa[find(y)]=find(x);
	}
	cout<<ans;
	return 0;
}