#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 1005
#define MAXM 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,m,tot;
int d[MAXM],c[MAXM];
int mx[MAXN][MAXN];
int dp[MAXN][MAXN];
int minx[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int solve(int l,int r)
{
    if(l>r||l==r) return 1;
    if(dp[l][r]!=-1) return dp[l][r];
    int v=mx[l][r];
    int lpos=INF,rpos=-INF;
    for(int i=l;i<=r;i++)
    {
        if(c[i]==v)
        {
            lpos=min(lpos,i);
            rpos=max(rpos,i);
        }
    }
    int ways=1;
    int last=lpos;
    for(int i=lpos+1;i<=rpos;i++)
    {
        if(c[i]==v)
        {
            ways=1LL*ways*solve(last+1,i-1)%MOD;
            last=i;
        }
    }
    int lres=0,rres=0;
    for(int i=l;i<=lpos;i++) 
    {
        if(minx[i-1]>v) continue;
        add(lres,1LL*solve(l,i-1)*solve(i,lpos-1)%MOD);
    }
    for(int i=rpos;i<=r;i++) 
    {
        if(minx[i]>v) continue;
        add(rres,1LL*solve(rpos+1,i)*solve(i+1,r)%MOD);
    }
    ways=1LL*ways*lres%MOD*rres%MOD;
    return dp[l][r]=ways;
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    bool f=true;
    for(int color=1;color<=m;color++)
    {
        int lpos=INF,rpos=-INF;
        for(int i=1;i<=n;i++)
        {
            if(d[i]==color)
            {
                lpos=min(lpos,i);
                rpos=max(rpos,i);
            }
        }
        for(int i=lpos;i<=rpos;i++) if(d[i]<color) f=false;
    }
    if(!f)
    {
        puts("0");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]!=d[i-1]) c[++tot]=d[i];
    }
    n=tot;
    for(int i=1;i<=n;i++) minx[i]=-1;
    for(int color=1;color<=m;color++)
    {
        int lpos=INF,rpos=-INF;
        for(int i=1;i<=n;i++)
        {
            if(c[i]==color)
            {
                lpos=min(lpos,i);
                rpos=max(rpos,i);
            }
        }
        for(int i=lpos;i<=rpos-1;i++) minx[i]=max(minx[i],color);
    }
    for(int i=1;i<=n;i++)
    {
        mx[i][i]=c[i];
        for(int j=i+1;j<=n;j++) mx[i][j]=min(mx[i][j-1],c[j]);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(1,n));
    return 0;
}