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
	if(n&1)
	{
		for(int i=1;i<=n;++i) cout<<1<<' ';
			cout<<'\n';
	}
	else
	{
		for(int i=1;i<=n-2;++i) cout<<2<<' ';
		cout<<1<<' '<<3<<'\n';
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