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
int t,n,q,cnt[1000001],a[1000001],ans[1000001],num[1000001];
vector<int> G[1000001];
vector<array<int,3>> qry[1000001];
set<int> s[1000001];
void dfs(int x)
{
	cnt[a[x]]++;
	num[cnt[a[x]]]++;
	if(cnt[a[x]]>1)
		s[cnt[a[x]]-1].erase(a[x]);
	s[cnt[a[x]]].insert(a[x]);
	for(auto i:qry[x])
	{
		int l=i[0],k=i[1];
		if(num[l]<k)
		{
			ans[i[2]]=-1;
			continue;
		}
		int del=num[l]-k,r=n+1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(num[mid]>del)
				l=mid+1;
			else
				r=mid-1;
		}
		ans[i[2]]=*s[l-1].begin();
	}
	for(int i:G[x])
		dfs(i);
	num[cnt[a[x]]]--;
	s[cnt[a[x]]].erase(a[x]);
	if(cnt[a[x]]>1)
		s[cnt[a[x]]-1].insert(a[x]);
	cnt[a[x]]--;
}
void solve()
{
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		G[i].clear();
		qry[i].clear();
	}
	for(int i=2;i<=n;i++)
		G[read()].push_back(i);
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read(),z=read();
		qry[x].push_back({y,z,i});
	}
	dfs(1);
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<" ";
	cout<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}