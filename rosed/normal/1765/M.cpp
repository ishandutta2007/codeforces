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
	int n;
	cin>>n;
	int x=1;
	for(int i=2;i*i<=n;++i)
	{
		if(n%i==0)
		{
			x=n/i;
			break;
		}
	}
	cout<<x<<' '<<n-x<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}