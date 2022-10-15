#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll fact[MAXN];
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
int main()
{
	fact[0]=1;
	for(ll i=1;i<MAXN;i++)
		fact[i]=fact[i-1]*i%MOD;
	scanf("%I64d",&n);
	ll maxi=-1;
	for(ll i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		maxi=max(maxi,a[i]);
	}
	ll cnt=0,res=0;
	sort(a,a+n);
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		//printf("%I64d %I64d %I64d\n",a[i],res,cnt);
		if(i==0||a[i]==a[i-1])
		{
			res++;
		}
		else {cnt+=res; res=1;}
		//printf("%I64d %I64d %I64d\n",a[i],res,cnt);
		if(a[i]!=maxi) ans=(ans+(a[i]*(fact[n]*mod_inverse(n-cnt,MOD)%MOD)%MOD))%MOD;
	}
	printf("%I64d\n",ans);
	return 0;
}