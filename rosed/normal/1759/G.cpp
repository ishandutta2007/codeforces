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
	int n;cin>>n;
	vector<int> a(n+1),f(n+2);
	iota(f.begin(),f.end(),0);
	vector<int> p(n+1);
	function<int(int)> find=[&](int k) -> int
	{
		return f[k]==k?k:f[k]=find(f[k]);
	};
	bool flag=1;
	for(int i=1;i<=n/2;++i)
	{
		cin>>a[2*i];
		if(p[a[2*i]]) flag=0;
		p[a[2*i]]=2*i;
		f[find(a[2*i])]=find(a[2*i]-1);
	}
	if(!flag)
	{
		cout<<"-1\n";return;
	}
	for(int i=n/2;i>=1;--i)
	{
		int x=find(a[2*i]),y=a[2*i];
		// cout<<x<<' '<<y<<"!!"<<endl;
		if(!x)
		{
			cout<<"-1\n";return;
		}
		a[2*i-1]=x;
		f[find(x)]=find(x-1);
	}
	for(int i=1;i<=n;++i) cout<<a[i]<<' ';
		cout<<'\n';
}
signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}