#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,a[MAXN],b[MAXN];
ll dp[MAXN];
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
	scanf("%I64d%I64d",&n,&m);
	for(ll i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	for(ll i=0;i<n;i++)
		scanf("%I64d",&b[i]);
	for(ll i=n-1;i>=0;i--)
	{
		if(a[i]!=0&&b[i]!=0) 
		{
			if(a[i]==b[i]) dp[i]=i==n-1?0:dp[i+1];
			else dp[i]=a[i]<b[i]?0:1;
		}
		else if(a[i]==0&&b[i]==0)
		{
			if(i==n-1) dp[i]=(m-1)*mod_inverse(2*m,MOD)%MOD;
			else dp[i]=((m-1)*mod_inverse(2*m,MOD)%MOD+mod_inverse(m,MOD)*dp[i+1])%MOD;
		}
		else if(a[i]==0)
		{
			if(i==n-1) dp[i]=(m-b[i])*mod_inverse(m,MOD)%MOD;
			else dp[i]=((m-b[i])*mod_inverse(m,MOD)+mod_inverse(m,MOD)*dp[i+1])%MOD;
		}
		else if(b[i]==0)
		{
			if(i==n-1) dp[i]=(a[i]-1)*mod_inverse(m,MOD)%MOD;
			else dp[i]=((a[i]-1)*mod_inverse(m,MOD)+mod_inverse(m,MOD)*dp[i+1])%MOD;
		}
	}
	printf("%I64d\n",dp[0]);
	return 0;
}