#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
using namespace std;
typedef long long ll;
ll Mod;
ll add(ll a,const ll b){a+=b;if(a>=Mod)a-=Mod;return a;}
ll sub(ll a,const ll b){a-=b;if(a<0)a+=Mod;return a;}
ll mul(const ll a,const ll b){return (ll)a*b%Mod;}
ll power(ll x,ll cs)
{
	ll ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
const ll N=3e5+50;
ll n;
ll ans=0;
ll zp[N];
int main()
{
	ll i,w=1;
	cin>>n>>Mod;
	zp[0]=1;
	for(i=1;i<=n;i++) zp[i]=mul(zp[i-1],i);
	for(i=1;i<=n;i++)
	{
		w=mul(w,i);
		ans=add(ans,mul(mul(zp[i],zp[n-i]),mul(n-i+1,n-i+1)));
	}
	cout<<ans;
	return 0;
}