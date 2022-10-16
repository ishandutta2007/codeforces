#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll n;
ll a[N];
ll jia,jian,he;
ll solve(ll x)//x 
{
	ll dn=0;ll up=0;
	for (ll i=1;i<=n;i++) if (a[i]>x) dn+=a[i]-x;else up+=x-a[i];
	if (he>=jia+jian) return jia*up+jian*dn;
	if (dn>up) return up*he+(dn-up)*jian;
	return dn*he+(up-dn)*jia;
}
int main()
{
	cin>>n; cin>>jia>>jian>>he;
	ll maxa=0;
	
	for (ll i=1;i<=n;i++) 
	{
		cin>>a[i];maxa=max(maxa,a[i]);
	}
	ll  ans=solve(maxa);
	//
	ll l=0; ll r=maxa;
	while (r-l>=3)
	{
		ll m1=(l*2+r)/3;ll m2=(l+r*2)/3;
		ll ans1=solve(m1);ll ans2=solve(m2);
		if (ans1<ans2) r=m2;else l=m1;
//		prllf("%d:%d %d:%d\n",m1,ans1,m2,ans2);
	}
	for (ll i=l;i<=r;i++) 
	{
//		cout<<i<<":"<<solve(i)<<endl;
		ans=min(ans,solve(i));
	}
	cout<<ans<<endl; 
}