#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
int n,maxx,a[200001],f[200001],son[200001];
vector<int> G[200001]; 
void dfs(int x,int fa)
{
	int mx1=0,mx2=0;
	for(int i:G[x])
		if(i!=fa)
		{
			dfs(i,x);
			if(mx1<=son[i])
			{
				mx2=mx1;
				mx1=son[i];
			}
			else
				mx2=max(mx2,son[i]);
			f[x]+=f[i];
		}
	if(!fa)
		f[x]+=2*a[x]-mx1-mx2;
	else
	{
		f[x]+=max(0ll,a[x]-mx1);
		son[x]=max(mx1,a[x]);
	}
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		if(a[i]>a[maxx])
			maxx=i;
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(maxx,0);
	cout<<f[maxx];
	return 0;
}