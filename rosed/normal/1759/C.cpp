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
	int l,r,x;
	int a,b;
	cin>>l>>r>>x;
	cin>>a>>b;
	if(a==b)
	{
		cout<<0<<'\n';
		return;
	}
	if(abs(a-b)>=x)
	{
		cout<<1<<'\n';
		return;
	}
	if(a>b) swap(a,b);
	if(a-x>=l)
	{
		cout<<2<<'\n';
		return;
	}
	if(r-a>=x&&r-b>=x)
	{
		cout<<2<<'\n';
		return;
	}
	if(r-a>=x&&r-l>=x&&b-l>=x)
	{
		cout<<3<<'\n';
		return;
	}
	cout<<-1<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}