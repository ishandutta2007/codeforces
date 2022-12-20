// LUOGU_RID: 96180825
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
const int mod=1e9+7;
void solve()
{
	int n;
	cin>>n;
	vector<int> rd(n+1),f(n+1);
	vector<string> s(n+1);
	iota(f.begin(),f.end(),0);
	vector<vector<int> >eg(n+1);
	function<int(int)> find=[&](int k) -> int
	{
		return f[k]==k?k:f[k]=find(f[k]);
	};
	int tot=n;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i];
		for(int j=1;j<=n;++j)
		{
			if(s[i][j-1]=='1')
			{
				++rd[i];
				eg[i].emplace_back(j);
				if(find(i)!=find(j)) f[find(j)]=find(i),--tot;
			}
		}
	}
	if(tot==1)
	{
		cout<<0<<'\n';
		return;
	}
	vector<int> rt;
	for(int i=1;i<=n;++i)
	{
		if(find(i)==i) rt.emplace_back(i);
	}
	vector<bool> vis(n+1);
	vector<int> num1(n+1),num2(n+1);
	function<void(int,int)> dfs=[&](int now,int rt) -> void
	{
		vis[now]=1;
		++num1[rt];
		for(int t:eg[now])
		{
			++num2[rt];
			if(vis[t]) continue;
			dfs(t,rt);
		}
	};
	tot=0;
	for(int x:rt)
	{
		dfs(x,x);
		int sum=num1[x];
		if(num2[x]==sum*(sum-1)&&sum>1) ++tot;
		else
		{
			cout<<1<<'\n';
			int ret=-1,minn=n+n;
			for(int y=1;y<=n;++y) if(find(y)==x)
			{
				if(rd[y]<minn) minn=rd[y],ret=y;
			}
			cout<<ret<<'\n';
			return;
		}
	}
	if(tot==2)
	{
		int ret=-1,minn=n+n;
		for(int y=1;y<=n;++y) if(find(y)==y)
		{
			if(num1[y]<minn) minn=num1[y],ret=y;
		}
		cout<<num1[ret]<<'\n';
		for(int i=1;i<=n;++i) if(find(i)==ret&&i!=ret)
		{
			cout<<i<<' ';
		}
		cout<<ret<<'\n';
	}
	else
	{
		cout<<2<<'\n';
		cout<<1<<' ';
		for(int i=2;i<=n;++i) if(find(i)!=find(1))
		{
			cout<<i<<' ';break;
		}
		cout<<'\n';
		return;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}