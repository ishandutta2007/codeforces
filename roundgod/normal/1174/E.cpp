#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 1000005
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
int n;
int dp[MAXN][20][2];
int val[20][2],f[20][2];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&n);
    int t=1,cnt=0;
    while(2*t<=n) {t*=2; cnt++;}
    dp[1][cnt][0]=1;
    if(t/2*3<=n) dp[1][cnt-1][1]=1;
    val[0][0]=1; val[0][1]=3;
    f[0][0]=n; f[0][1]=n/3;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=0;j<=1;j++)
        {
            val[i][j]=val[i-1][j]*2;
            f[i][j]=n/val[i][j];
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;(1<<j)<=n;j++)
        {
            for(int k=0;k<2;k++)
            {
                if(!dp[i][j][k]) continue;
                if(f[j][k]>=i) add(dp[i+1][j][k],1LL*(f[j][k]-i)*dp[i][j][k]%MOD);
                if(j>0&&f[j-1][k]>=i) add(dp[i+1][j-1][k],1LL*(f[j-1][k]-f[j][k])*dp[i][j][k]%MOD);
                if(k>0&&f[j][k-1]>=i) add(dp[i+1][j][k-1],1LL*(f[j][k-1]-f[j][k])*dp[i][j][k]%MOD);
            }
        }
    }
    int ans=0;
    for(int j=0;(1<<j)<=n;j++)
        for(int k=0;k<2;k++)
            add(ans,dp[n][j][k]);
    printf("%d\n",ans);
    return 0;
}