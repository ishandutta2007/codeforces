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
int t,n,m,fa[200002],a[200001],tag[200001];
vector<int> G[200001];
array<int,2> q[200001];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void mark(int x)
{
	fa[find(x)]=find(x+1);
	for(int i:G[x])
		if(!(--tag[i]))
		{
			int y=find(q[i][0]);
			while(y<=q[i][1])
			{
				mark(y);
				y=find(y);
			}
		}
}
void solve()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		a[i]-=read();
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	for(int i=0;i<=n+1;i++)
		fa[i]=i;
	for(int i=0;i<=n;i++)
		G[i].clear();
	for(int i=1;i<=m;i++)
	{
		int x=read()-1,y=read();
		G[x].push_back(i);
		G[y].push_back(i);
		q[i]={x,y};
		tag[i]=2;
	}
	for(int i=0;i<=n;i++)
		if(!a[i])
			mark(i);
	if(find(0)!=find(n+1))
		puts("No");
	else
		puts("Yes");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}