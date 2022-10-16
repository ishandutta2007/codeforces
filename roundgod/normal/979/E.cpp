#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p,color[MAXN],ans;
int dp[MAXN][MAXN][MAXN][MAXN],fact[MAXN],invf[MAXN],two[MAXN],even[MAXN],odd[MAXN];
int pow_mod(int a,int i)
{
	int s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%MOD;
		a=1LL*a*a%MOD;
		i>>=1;
	}
	return s;
}
int comb(int n,int k)
{
	return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
void init()
{
    dp[0][0][0][0]=1;
    two[0]=fact[0]=invf[0]=1;
    for(int i=1;i<=n;i++)
    {
        two[i]=two[i-1]*2%MOD;
        fact[i]=1LL*fact[i-1]*i%MOD;
        invf[i]=pow_mod(fact[i],MOD-2);
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j+=2)
            (even[i]+=comb(i,j))%=MOD;
        for (int j=1;j<=i;j+= 2)
            (odd[i]+=comb(i,j))%=MOD;
    }
}
void find_ans(int ob,int eb,int ow,int ew,int col,int &ret)
{
    if(col!=0&&ew!=0) (ret+=1LL*dp[ob][eb][ow][ew-1]*two[ow+ew-1+eb]%MOD*odd[ob]%MOD)%=MOD;
    if(col!=0&&ow!=0) (ret+=1LL*dp[ob][eb][ow-1][ew]*two[ow-1+ew+eb]%MOD*even[ob]%MOD)%=MOD;
    if(col!=1&&eb!=0) (ret+=1LL*dp[ob][eb-1][ow][ew]*two[ob+eb-1+ew]%MOD*odd[ow]%MOD)%=MOD;
    if(col!=1&&ob!=0) (ret+=1LL*dp[ob-1][eb][ow][ew]*two[ob-1+eb+ew]%MOD*even[ow]%MOD)%=MOD;
}

int main()
{
    scanf("%d%d",&n,&p);
    init();
    for (int i=1;i<=n;i++)
        scanf("%d",&color[i]);
    for (int i=1;i<=n;i++)
        for (int ob=0;ob<=i;ob++)
            for (int eb=0;ob+eb<=i;eb++)
                for (int ow=0;ob+eb+ow<=i;ow++)
                {
                    int ew=i-ob-eb-ow;
                    find_ans(ob,eb,ow,ew,color[i],dp[ob][eb][ow][ew]);
                    if (i==n&&((ob+ow)&1)==p)
                        (ans+=dp[ob][eb][ow][ew])%=MOD;
                }
    printf("%d\n",ans);
    return 0;
}