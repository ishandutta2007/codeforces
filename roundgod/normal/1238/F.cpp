#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,n,ans;
vector<int> G[MAXN];
int f[MAXN];
vector<int> res[MAXN];
void dfs(int v,int p)
{
    f[v]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        res[v].push_back(f[to]);
    }
    if((int)res[v].size())
    {
        sort(res[v].begin(),res[v].end(),greater<int>());
        if((int)res[v].size()>1) ans=max(ans,res[v][0]+res[v][1]+1+(int)G[v].size()-2);
        f[v]+=(int)res[v].size()-1;
        f[v]+=res[v][0];
    }
    ans=max(ans,f[v]);
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear(),res[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        ans=0;
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}