#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int dp[MAXN];
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
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n==1) {puts("0"); continue;}
        int inv=pow_mod(1LL*n*(n-1)/2%MOD,MOD-2);
        int cnt=0,cntzero=0;
        for(int i=1;i<=n;i++) if(a[i]==0) cnt++; 
        dp[cnt]=0;
        for(int i=1;i<=cnt;i++) if(a[i]==0) cntzero++;
        for(int i=cnt-1;i>=0;i--)
        {
            int prob=1LL*(cnt-i)*(cnt-i)%MOD*inv%MOD;
            int mult=pow_mod(prob,MOD-2)%MOD;
            dp[i]=1;
            add(dp[i],1LL*prob*dp[i+1]%MOD);
            dp[i]=1LL*dp[i]*mult%MOD;
        }
        printf("%d\n",dp[cntzero]);
    }
    return 0;
}