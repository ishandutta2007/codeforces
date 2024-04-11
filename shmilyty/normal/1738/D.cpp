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
int t,n,cnt,b[200001],L[200001],R[200002];
std::vector<int> G[200001];
bool cmp(int x,int y)
{
	return G[x].size()<G[y].size();
}
void dfs(int x)
{
	if(x)
		cout<<x<<" ";
	sort(ALL(G[x]),cmp);
	for(int i:G[x])
		dfs(i);
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	for(int i=0;i<=n;i++)
		G[i].clear();
	L[1]=b[1];
	for(int i=2;i<=n;i++)
		L[i]=min(L[i-1],b[i]);
	R[n+1]=0;
	for(int i=n;i;i--)
		R[i]=max(R[i+1],b[i]);
	int k=0;
	for(int i=0;i<=n;i++)
		if(L[i]>i&&R[i+1]<=i)
		{
			k=i;
			break;
		}
	cout<<k<<'\n';
		{
			// cout<<i<<'\n';
			for(int l=1;l<=n;l++)
			{
				if(b[l]&&b[l]<=n)
					G[b[l]].push_back(l);
				else
					G[0].push_back(l);
			}
			dfs(0);
			cout<<'\n';
			return ;
		}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}