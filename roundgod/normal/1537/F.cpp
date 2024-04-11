#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first 
#define S second
#define x1 daksida 
#define y1 daskdsia
#define x2 doakdos
#define y2 dakoda
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN],b[MAXN];
int col[MAXN];
vector<int> G[MAXN];
bool cyc;
ll odd,even;
void dfs(int v,int p,int c)
{
    if(c==1) odd+=b[v]-a[v]; else even+=b[v]-a[v];
    col[v]=c;
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(!col[to]) dfs(to,v,-c);
        else if(col[to]==c) cyc=true;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        bool f=true;
        for(int i=1;i<=n;i++) col[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(!col[i])
            {
                cyc=false;
                even=odd=0;
                dfs(i,0,1);
                if(cyc)
                {
                    if((even+odd)&1) f=false;
                }
                else
                {
                    if(even!=odd) f=false;
                }
            }
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}