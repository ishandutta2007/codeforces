#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define next sakidsao
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,q,a[MAXN];
int next[MAXN][20];
int dp[MAXN][20];
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int j=0;j<20;j++) next[n+1][j]=n+1,dp[n+1][j]=n+1;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<20;j++)
        {
            if(a[i]&(1<<j)) next[i][j]=i;
            else next[i][j]=next[i+1][j];
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<20;j++)
        {
            if(a[i]&(1<<j)) dp[i][j]=i;
            else
            {
                dp[i][j]=n+1;
                for(int k=0;k<20;k++) 
                    if(a[i]&(1<<k)) dp[i][j]=min(dp[i][j],dp[next[i+1][k]][j]);
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        bool f=false;
        for(int k=0;k<20;k++)
        {
            if(a[y]&(1<<k))
            {
                if(dp[x][k]<=y)
                {
                    f=true;
                    break;
                }
            }
        }
        if(f) puts("Shi"); else puts("Fou");
    }
    return 0;
}