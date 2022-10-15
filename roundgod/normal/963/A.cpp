#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000009
#define F first
#define S second
using namespace std;
typedef long long ll;
ll n,a,b,k,ans;
ll pow_mod(ll a,ll i)
{
    if(i==0) return 1;
     ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%MOD;
         a=(a*a)%MOD;
         i>>=1;
     }
     return s;
}
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    ll d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
string str;
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&k);
	cin>>str;
	ll s=0;
	for(int i=0;i<k;i++)
	{
		if(str[i]=='+') s=(s+pow_mod(a,n-i)*pow_mod(b,i)%MOD)%MOD;
		else s=(s-pow_mod(a,n-i)*pow_mod(b,i)%MOD+MOD)%MOD;
	}
	ll d=pow_mod(b,k)*pow_mod(mod_inverse(a,MOD),k)%MOD;
	ll ans;
	int t=(n+1)/k;
	if(d==1) ans=t*s%MOD; else ans=(s*((pow_mod(d,t)-1+MOD)%MOD)%MOD)*mod_inverse(d-1,MOD)%MOD;
	printf("%I64d\n",ans);
	return 0;
}