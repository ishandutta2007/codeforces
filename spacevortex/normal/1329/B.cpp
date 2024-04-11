#include<bits/stdc++.h>
#define upd(a,b) a=add(a,b)
#define rdc(a,b) a=sub(a,b)
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
ll i;
ll n,ans;
int main()
{
	ll T;
	cin>>T;
	while(T--)
	{
		cin>>n>>Mod;
		ans=1;
		for(i=0;(1ll<<(i+1))-1<=n;i++)
		{
			ans=mul(ans,((1ll<<i)+1));
		}
		n-=(1ll<<i)-1;
		//printf("N%d\n",n);
		ans=mul(ans,n+1);
		ans=sub(ans,1);
		printf("%lld\n",ans);
	}
	return 0;
}