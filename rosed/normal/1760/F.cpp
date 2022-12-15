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
	int n,c,d;
	cin>>n>>c>>d;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	
	auto check=[&](int x) -> bool
	{
		priority_queue<int> q;
		for(int i=1;i<=n;++i) q.push(a[i]);
		vector<vector<int>> b(d+1);
		int ans=0;
		for(int i=1;i<=d;++i)
		{
			for(int y:b[i]) q.push(y);
			if(q.empty()) continue;
			ans+=q.top();
			if(i+x+1<=d) b[i+x+1].emplace_back(q.top());
			q.pop();
		}
		return ans>=c;
	};
	int l=0,r=d+1;
	while(l<=r)
	{
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	if(l-1<0) cout<<"Impossible\n";
	else if(l-1>d) cout<<"Infinity\n";
	else cout<<l-1<<'\n'; 
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}