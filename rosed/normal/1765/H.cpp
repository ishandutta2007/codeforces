#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
void solve()
{
	int n,m;
	cin>>n>>m;
	typedef array<int,2> pr;
	vector<int> a(n+1);
	vector<int> ans(n+1);
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	vector<vector<int> > eg(n+1);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		eg[y].emplace_back(x);
	}
	for(int s=1;s<=n;++s)
	{
		vector<int> deg(n+1);
		for(int x=1;x<=n;++x)
		{
			for(int t:eg[x]) ++deg[t];
		}
		priority_queue<pr> q;
		for(int x=1;x<=n;++x)
		{
			if(deg[x]==0&&x!=s) q.push(pr{a[x],x});
		}
		for(int i=n;i>=1;--i)
		{
			if(q.empty()||q.top()[0]<i)
			{
				ans[s]=i;break;
			}
			int now=q.top()[1];
			q.pop();
			for(int t:eg[now])
			{
				--deg[t];
				if(deg[t]==0&&t!=s) q.push(pr{a[t],t});
			}
		}
	}
	for(int i=1;i<=n;++i) cout<<ans[i]<<' ';

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve();
	return 0;
}