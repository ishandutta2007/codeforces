#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<vector<int>> G(n+5);
	for(int i=2;i<=n;i++)
	{
		int p;
		cin>>p;
		G[i].push_back(p);
		G[p].push_back(i);
	}
	vector<int> sz(n+5),mxson(n+5);
	long long tot=0;
	function<void(int,int)> dfs=[&](int u,int p)
	{
		sz[u]=1;
		mxson[u]=0;
		for(auto v:G[u])
		{
			if(v!=p)
			{
				dfs(v,u);
				sz[u]+=sz[v];
				if(sz[v]>sz[mxson[u]])
				{
					mxson[u]=v;
				}
			}
		}
		tot+=sz[u];
	};
	dfs(1,0);
	int cur=1;
	while(sz[mxson[cur]]>=n/2)cur=mxson[cur];
	tot=0;
	dfs(cur,0);
	map<int,int> tr;
	for(auto v:G[cur])
	{
		tr[sz[v]]++;
	}
	bitset<1000001> b;
	b[0]=1;
//	for(int i=1;i<=n;i++)cerr<<"sz "<<i<<' '<<sz[i]<<endl;
//	cerr<<tot<<endl;
	for(auto [x,y]:tr)
	{
//		cerr<<"QAQ "<<x<<' '<<y<<endl;
		for(int i=1;y!=0;i*=2)
		{
			int sub=min(i,y);
			b|=b<<(sub*x);
			y-=sub;
		}
	}
	long long mx=0;
	for(int i=0;i<=n;i++)
	{
		if(b[i])
		{
//			cerr<<"split "<<i<<endl;
			mx=max(mx,1ll*i*(n-1-i));
		}
	}
	cout<<tot+mx<<endl;
	return 0;
}