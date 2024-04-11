#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,x,dp[MAXN][MAXN][MAXN],f[MAXN],p[MAXN];
string str;
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
	scanf("%I64d%I64d",&n,&x);
	memset(dp,0,sizeof(dp));
	memset(f,0,sizeof(f));
	memset(p,0,sizeof(p));
	cin>>str;
	for(ll i=0;i<n;i++)
	{
		dp[0][i][i]=str[i]=='0'?1:0;
		dp[1][i][i]=str[i]=='1'?1:0;
	}
	f[0]=f[1]=1;
	for(ll i=2;i<MAXN;i++)
		f[i]=(f[i-1]+f[i-2])%(MOD-1);
	for(ll i=0;i<MAXN;i++)
		p[i]=pow_mod(2,f[i]);
	for(ll i=2;i<=x;i++)
	{
		for(ll len=1;len<=n;len++)
		{
			for(ll l=0;l+len-1<n;l++)
			{
				ll r=l+len-1;
				for(ll k=l;k+1<=r;k++)
					dp[i][l][r]=(dp[i][l][r]+dp[i-1][l][k]*dp[i-2][k+1][r])%MOD;
				if(l==0) dp[i][l][r]=(dp[i][l][r]+dp[i-2][l][r]*p[i-1])%MOD; else dp[i][l][r]=(dp[i][l][r]+dp[i-2][l][r])%MOD;
				if(r==n-1) dp[i][l][r]=(dp[i][l][r]+dp[i-1][l][r]*p[i-2])%MOD; else dp[i][l][r]=(dp[i][l][r]+dp[i-1][l][r])%MOD;
			}
		}
	}
	printf("%I64d\n",dp[x][0][n-1]);
	return 0;
}