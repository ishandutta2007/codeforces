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
	vector<int> a(n+1);
	int sum=n;
	multiset<int> q;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		sum+=a[i];
		q.insert(a[i]);
	}
	sort(a.begin()+1,a.end());
	function<void(int)> work=[&](int x) -> void
	{
		auto it=q.upper_bound(m-x);
		if(it==q.begin()) return;
		--it;--sum;
		int y=*it;
		q.erase(it);
		work(y);
	};
	for(int i=n;i>=1;--i)
	{
		if(q.find(a[i])==q.end()) continue;
		auto it=q.find(a[i]);
		q.erase(it);
		work(a[i]);
	}
	cout<<sum<<'\n';

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve();
	return 0;
}