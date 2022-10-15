#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,n,r;
int dp[MAXN][MAXLOGN+1];
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
int main()
{
	int p=sieve(1000000);
	for(int i=1;i<=20;i++) dp[0][i]=2;
	dp[0][0]=1;
	for(int i=1;i<=1000000;i++)
		for(int j=0;j<=20;j++)
			if(j==0) dp[i][j]=dp[i-1][j]; else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&r,&n);
		int t=n,ans=1,cnt;
		for(int i=0;i<p;i++)
		{
			cnt=0;
			if(is_prime[t]) {ans=1LL*ans*dp[r][1]%MOD; break;}
			if(t==1) break;
			while(t%prime[i]==0) {t=t/prime[i]; cnt++;}
			if(cnt) ans=1LL*ans*dp[r][cnt]%MOD;
		}
		printf("%d\n",ans);
	}
	return 0;
}