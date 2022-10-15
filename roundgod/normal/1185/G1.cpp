#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 55
#define MAXM 2505
#define MAGIC 6005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,T,t[MAXN],g[MAXN],cnt[4];
int dp[MAXN][MAXN][MAXN][4];
int fact[MAXN];
int f[2][MAXM][MAGIC];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int solve(int i,int j,int k,int last)
{
    if(i==0&&j==0&&k==0) return 1;
    if(dp[i][j][k][last]!=-1) return dp[i][j][k][last];
    int &val=dp[i][j][k][last];
    val=0;
    int sum=i+j+k;
    if(i>(sum+1)/2||j>(sum+1)/2||k>(sum+1)/2) return 0;
    if(last!=1&&i>=1) add(val,solve(i-1,j,k,1));
    if(last!=2&&j>=1) add(val,solve(i,j-1,k,2));
    if(last!=3&&k>=1) add(val,solve(i,j,k-1,3));
    return val;
}
int get_id(int x,int y,int z)
{
    return x*(cnt[2]+1)*(cnt[3]+1)+y*(cnt[3]+1)+z;
}
int main()
{
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&t[i],&g[i]);
        cnt[g[i]]++;
    }
    memset(dp,-1,sizeof(dp));
    fact[0]=1;
    for(int i=1;i<=50;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    memset(f,0,sizeof(f));
    f[0][0][0]=1;
    int cnti=0,cntj=0,cntk=0,curw=0;
    for(int tot=0;tot<n;tot++)
    {
        int now=tot&1,nxt=now^1;
        memset(f[nxt],0,sizeof(f[nxt]));
        for(int w=0;w<=min(T,curw);w++)
        {
            for(int i=0;i<=cnti;i++)
            {
                for(int j=0;j<=cntj;j++)
                {
                    for(int k=0;k<=cntk;k++)
                    {
                        int id=get_id(i,j,k);
                        if(!f[now][w][id]) continue;
                        int val=f[now][w][id];
                        add(f[nxt][w][id],val);
                        if(g[tot+1]==1&&w+t[tot+1]<=T) add(f[nxt][w+t[tot+1]][get_id(i+1,j,k)],val);
                        if(g[tot+1]==2&&w+t[tot+1]<=T) add(f[nxt][w+t[tot+1]][get_id(i,j+1,k)],val);
                        if(g[tot+1]==3&&w+t[tot+1]<=T) add(f[nxt][w+t[tot+1]][get_id(i,j,k+1)],val);
                    }
                }
            }
        }
        cnti+=(g[tot+1]==1);
        cntj+=(g[tot+1]==2);
        cntk+=(g[tot+1]==3);
        curw+=t[tot+1];
    }
    int ans=0;
    for(int i=0;i<=cnt[1];i++)
        for(int j=0;j<=cnt[2];j++)
            for(int k=0;k<=cnt[3];k++)
                add(ans,1LL*f[n&1][T][get_id(i,j,k)]*solve(i,j,k,0)%MOD*fact[i]%MOD*fact[j]%MOD*fact[k]%MOD);
    printf("%d\n",ans);
    return 0;
}