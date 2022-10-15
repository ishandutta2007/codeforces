#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
vector<P> G[MAXN];
int tot,ansv[MAXN],anse[MAXN],res[MAXN];
void dfs(int v,int p)
{
    for(auto e:G[v])
    {
        int to=e.F,id=e.S;
        if(to==p) continue;
        if(res[v]==n)
        {
            ++tot;
            anse[id]=n+tot; 
            ansv[to]=tot;
            res[to]=0;
        }
        else
        {
            ++tot;
            anse[id]=tot;
            ansv[to]=n+tot;
            res[to]=n;
        }
        dfs(to,v);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        tot=0;
        int p;
        scanf("%d",&p);
        n=(1<<p);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(P(v,i)); G[v].push_back(P(u,i));
        }
        res[1]=ansv[1]=n;
        printf("%d\n",1);
        dfs(1,0);
        for(int i=1;i<=n;i++) printf("%d%c",ansv[i],i==n?'\n':' ');
        for(int i=0;i<n-1;i++) printf("%d%c",anse[i],i==n-2?'\n':' ');
    }
    return 0;
}