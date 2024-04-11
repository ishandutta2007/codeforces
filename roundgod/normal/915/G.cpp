#include<bits/stdc++.h>
#define MAXN 2000005
#define MOD 1000000007
using namespace std;
typedef long long ll;
int mu[MAXN];
void getMu(int n)
{
	memset(mu,0,sizeof(mu));
    for(int i=1;i<=n;i++)
    {
        int target=i==1?1:0;
        int delta=target-mu[i];
        mu[i]=delta;
        for(int j=i+i;j<=n;j+=i)
            mu[j]+=delta;
    }
    return;
}
ll pow_mod(ll a,ll i)
{
	ll s=1;
	while(i>0)
	{
		if(i&1) s=(s*a)%MOD;
		a=(a*a)%MOD;
		i=i>>1;
	}
	return s;
}
ll n,k;
ll npow[MAXN],f[MAXN],d[MAXN];
int main()
{
	scanf("%I64d%I64d",&n,&k);
	npow[0]=0;
	for(int i=1;i<=k;i++)
		npow[i]=pow_mod(i,n);
	getMu(k);
	ll ans=0;
	f[1]=1;
	memset(d,0,sizeof(d));
	for(int i=1;i<=k;i++)
		for(int j=i;j<=k;j+=i)
			d[j]=(d[j]+((npow[j/i]-npow[j/i-1])*mu[i]+MOD)%MOD)%MOD;
	for(int i=2;i<=k;i++)
	{
		f[i]=(f[i-1]+d[i])%MOD;
		ans=(ans+(i^f[i]))%MOD;
	}
	printf("%I64d\n",ans);
}