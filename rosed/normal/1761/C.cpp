#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
void solve()
{
	int n;
	cin>>n;
	vector<vector<int> > eg(n+1);
	vector<int> rd(n+1);
	for(int i=1;i<=n;++i)
	{
		string s;cin>>s;
		for(int j=1;j<=n;++j)
		{
			if(s[j-1]=='1')
			{
				++rd[j];
				eg[i].emplace_back(j);
			}
		}
	}
	queue<int> q;
	vector<set<int> > dp(n+1);
	for(int i=1;i<=n;++i)
	{
		dp[i].insert(i);
		if(rd[i]==0) 
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int now=q.front();
		// cout<<now<<"!!"<<endl;
		q.pop();
		for(int t:eg[now])
		{
			auto it=dp[now].begin();
			while(it!=dp[now].end())
			{
				dp[t].insert((*it));
				++it;
			}
			if(!--rd[t])
			{
				q.push(t);
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		int x=dp[i].size();
		cout<<x<<' ';
		for(int x:dp[i]) cout<<x<<' ';
		cout<<'\n';
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