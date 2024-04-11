#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
using namespace std;
typedef long long ll;
const ll Mod=1e9+7;
ll mul(const ll a,const ll b){return (a%Mod)*(b%Mod)%Mod;}
ll power(ll x,ll cs)
{
	ll ras=1;
	while(cs)
	{
		if(cs&1ll) ras=mul(ras,x);
		cs>>=1;x=mul(x,x);
	}
	return ras;
}
ll ans=1,n;
void solve(ll x)
{
	ll w=x;
	if(w>n) return ;
	while(1)
	{
		ans=mul(ans,power(x,n/w));
		if(w>n/x) break;
		w*=x;
	}
}
int main()
{
	ll x;
	cin>>x>>n;
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i!=0) continue ;
		solve(i);
		while(x%i==0) x/=i;
	}
	if(x>1) solve(x);
	cout<<ans;
	return 0;
}