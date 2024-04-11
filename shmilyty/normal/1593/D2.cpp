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
int t,n,a[41],fa[2000001],sz[2000001];
vector<pair<int,int> > v[2000001];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	int num=0;
	for(int i=1;i<=n;i++)
		if(i==n||a[i]!=a[i+1])
		{
			if(num+1>=n/2)
			{
				puts("-1");
				return ;
			}
			num=0;
		}
		else
			num++;
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
		{
			int d=abs(a[i]-a[l]);
			for(int j=1;j*j<=d;j++)
				if(d%j==0)
				{
					v[j].push_back({i,l});
					if(j*j!=d)
						v[d/j].push_back({i,l});
				}
		}
	for(int i=2e6;i>=1;i--)
	{
		for(int l=1;l<=n;l++)
			fa[l]=l;
		for(int l=1;l<=n;l++)
			sz[l]=1;
		bool ok=1;
		for(auto l:v[i])
		{
			if(find(l.first)==find(l.second))
				continue;
			sz[find(l.first)]+=sz[find(l.second)];
			fa[find(l.second)]=find(l.first);
		}
		for(int l=1;l<=n;l++)
			if(sz[find(l)]>=n/2)
			{
				cout<<i<<endl;
				ok=0;
				break;
			}
		if(!ok)
			break;
	}
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
		{
			int d=abs(a[i]-a[l]);
			for(int j=1;j*j<=d;j++)
				if(d%j==0)
				{
					v[j].clear();
					if(j*j!=d)
						v[d/j].clear();
				}
		}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}