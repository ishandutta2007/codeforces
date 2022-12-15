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
	int a,b,d;
	cin>>a>>b>>d;
	int c=a|b;
	if(lowbit(c)<lowbit(d))
	{
		cout<<"-1\n";
		return;
	}
	int x=0;
	int k=__lg(lowbit(d));
	for(int i=0;i<30;++i) if(((c>>i)&1)&&((x>>i)&1)==0)
	{
		x+=(d<<(i-k));
	}
	cout<<x<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}