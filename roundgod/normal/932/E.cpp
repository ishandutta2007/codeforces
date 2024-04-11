#include<bits/stdc++.h>
#define MAXK 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,st[MAXK][MAXK];
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
int main()
{
	scanf("%I64d%I64d",&n,&k);
	memset(st,0,sizeof(st));
	st[0][0]=1;
	for(ll i=1;i<=k;i++)
	{
		st[i][0]=0;
		for(ll j=1;j<=i;j++)
			st[i][j]=(j*st[i-1][j]+st[i-1][j-1])%MOD;
	}
	ll res=1,ans=0;
	for(ll j=0;j<=k;j++)
	{
		ans=(ans+(pow_mod(2,n-j)*res)%MOD*st[k][j]%MOD)%MOD;
		res=res*(n-j)%MOD;
	}
	printf("%I64d\n",ans);
	return 0;
}