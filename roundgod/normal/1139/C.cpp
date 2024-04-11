#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
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
int n,k,cnt,ans;
vector<int> G[MAXN];
bool vis[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
void dfs(int v)
{
    vis[v]=true; cnt++;
    for(auto to:G[v])
        if(!vis[to]) dfs(to);
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(w==0)
        {
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    ans=pow_mod(n,k);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) 
        {
            cnt=0;
            dfs(i);
            dec(ans,pow_mod(cnt,k));
        }
    }
    printf("%d\n",ans);
    return 0;
}