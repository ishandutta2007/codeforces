#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int t,n,k,x;
int dp[MAXN][MAXN][11],dp2[MAXN][MAXN][11];
int mod_fact[MAXN],inv[MAXN];
int odd[MAXN],even[MAXN];
int pow_mod(int a,int i)
{
    if(i==0) return 1;
    int s=1;
    while(i>0)
     {
         if(i&1) s=(1LL*s*a)%MOD;
         a=(1LL*a*a)%MOD;
         i>>=1;
     }
     return s;
}
int comb(int x,int y)
{
	if(x==0) return (y==0);
	return 1LL*mod_fact[x+y-1]*inv[x-1]%MOD;
}
int main()
{
	mod_fact[0]=1;
	for(int i=1;i<=2000;i++)
		mod_fact[i]=(1LL*mod_fact[i-1]*i)%MOD;
	for(int i=0;i<=2000;i++)
		inv[i]=pow_mod(mod_fact[i],MOD-2);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=10;k++)
					dp[i][j][k]=dp2[i][j][k]=0;
		int t1=0,t2=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			int cnt=0,num=x%11;
			while(x>0)
			{
				cnt++;
				x/=10;
			}
			if(cnt&1) odd[t1++]=num; else even[t2++]=num;
		}
		if(t1==0)
		{
			int s=0;
			for(int i=0;i<t2;i++)
				s=(s+even[i])%11;
			if(s==0) printf("%d\n",mod_fact[n]); else puts("0");
			continue;
		}
		int lb=(t1+1)/2,rb=t1/2;
		dp[0][0][0]=1;
		for(int i=0;i<t1;i++)
		{
			for(int j=0;j<=i;j++)
			{
				for(int k=0;k<=10;k++)
				{
					dp[i+1][j+1][(k+odd[i])%11]=(dp[i+1][j+1][(k+odd[i])%11]+dp[i][j][k])%MOD; 
					dp[i+1][j][(k+11-odd[i])%11]=(dp[i+1][j][(k+11-odd[i])%11]+dp[i][j][k])%MOD; 
				}
			}
		}
		dp2[0][0][0]=1;
		for(int i=0;i<t2;i++)
		{
			for(int j=0;j<=i;j++)
			{
				for(int k=0;k<=10;k++)
				{
					dp2[i+1][j+1][(k+even[i])%11]=(dp2[i+1][j+1][(k+even[i])%11]+dp2[i][j][k])%MOD; 
					dp2[i+1][j][(k+11-even[i])%11]=(dp2[i+1][j][(k+11-even[i])%11]+dp2[i][j][k])%MOD; 
				}
			}
		}
		int ans=0;
		for(int i=0;i<=t2;i++)
		{
			for(int j=0;j<=10;j++)
			{
				int s=1LL*dp[t1][lb][j]*dp2[t2][i][(11-j)%11]%MOD;
				s=1LL*s*comb(lb,i)%MOD;
				s=1LL*s*comb(rb+1,t2-i)%MOD;
				ans=(ans+s)%MOD;
			}
		}
		ans=1LL*ans*mod_fact[lb]%MOD;
		ans=1LL*ans*mod_fact[rb]%MOD;
		printf("%d\n",ans);
	}
	return 0;
}