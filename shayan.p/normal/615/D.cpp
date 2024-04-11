#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define F first
#define S second
using namespace std;
const ll mod=1e9+7;
ll tavan(ll a,ll b)
{
	if(b==0) return 1;
	a%=mod;
	return (((b%2)?a:1)*tavan((a*a)%mod,b/2))%mod;
}
map<ll,ll> mp;
ll ans=1,d=1;
int main()
{
	ll n;cin>>n;
	for(ll i=0;i<n;i++) {ll x;cin>>x;mp[x]++;}
	for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++)
	{
		pll p=*it;
		ans=tavan(ans,p.S+1);ans*=tavan(tavan(p.F,(p.S*(p.S+1))/2),d);ans%=mod;
		d*=p.S+1;d%=mod-1;
	}
	cout<<ans;
}