#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int t,n,k,m,dp[MAXN],cnt[MAXN],sum[MAXN];
int ans;
int l[MAXN],r[MAXN],x[MAXN];
int pre[MAXN];
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&l[i],&r[i],&x[i]);
    ans=1;
    for(int i=0;i<k;i++)
    {
        memset(pre,0,sizeof(pre));
        memset(cnt,0,sizeof(cnt));
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=m;j++) 
        {
            if((x[j]>>i)&1)
            {
                cnt[l[j]]++; cnt[r[j]+1]--;
            }
            else
            {
                pre[r[j]+1]=max(pre[r[j]+1],l[j]);
            }
        }
        for(int j=1;j<=n+1;j++) pre[j]=max(pre[j],pre[j-1]);
        dp[0]=sum[0]=1;
        for(int j=1;j<=n+1;j++)
        {
            cnt[j]+=cnt[j-1];
            if(cnt[j]) dp[j]=0;
            else 
            {
                dp[j]=sum[j-1];
                if(pre[j]) dec(dp[j],sum[pre[j]-1]);
            }
            sum[j]=sum[j-1]; add(sum[j],dp[j]);
        }
        ans=1LL*ans*dp[n+1]%MOD;
    }
    printf("%d\n",ans);
    return 0;
}