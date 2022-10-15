#include<bits/stdc++.h>
#define MAXN 250005
#define MAXLOGN 18
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,p;
int fact[MAXN],invf[MAXN];
int f[(1<<18)],dp[19][(1<<18)];
void add(int &a,int b) {a+=b; if(a>=p) a-=p;}
void dec(int &a,int b) {a-=b; if(a<0) a+=p;}
int pow_mod(int a,int i)
{
	int s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%p;
		a=1LL*a*a%p;
		i>>=1;
	}
	return s;
}
int comb(int n,int k)
{
	if(n<k) return 0;
	return 1LL*fact[n]*invf[k]%p*invf[n-k]%p;
}
int main()
{
	scanf("%d%d%d",&n,&k,&p);
	fact[0]=invf[0]=1;
	for(int i=1;i<=250000;i++) fact[i]=1LL*fact[i-1]*i%p;
	invf[250000]=pow_mod(fact[250000],p-2);
	for(int i=249999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%p;
	if(n&1) {printf("%d\n",pow_mod(k,n)); return 0;}
	for(int mask=0;mask<(1<<18);mask++) if((n&mask)==mask) f[mask]=invf[mask]; else f[mask]=0;
	int num=__builtin_popcount(n);
	dp[0][0]=1;
 	for(int i=0;i<num;i++)
 	{
 		for(int mask=0;mask<(1<<18);mask++)
 		{
 			if(!dp[i][mask]) continue;
 			if(mask==n) continue;
 			int nmask=(n^mask),lbit=__builtin_ffs(nmask)-1;
 			nmask^=(1<<lbit);
 			int sub=nmask;
		    do
		    {
		        add(dp[i+1][mask^sub^(1<<lbit)],1LL*dp[i][mask]*f[sub^(1<<lbit)]%p);
		        sub=(sub-1)&nmask;
		    }while(sub!=nmask);
 		}
 	}
 	int ans=pow_mod(k,n);
 	for(int i=1;i<=num;i++) 
 	{
 		dec(ans,1LL*dp[i][n]*comb(k,i)%p*fact[i]%p*fact[n]%p);
 	}
 	printf("%d\n",ans);
	return 0;
}