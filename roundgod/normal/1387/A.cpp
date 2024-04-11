#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<P> G[MAXN];
int n,m;
bool vis[MAXN];
P res[MAXN];
double ans[MAXN];
bool f;
double x;
vector<int> tmp;
vector<int> pos;
void dfs(int v)
{
    vis[v]=true; tmp.push_back(v);
    pos.push_back(-res[v].S*res[v].F);
    for(auto e:G[v])
    {
        int to=e.F;
        if(!vis[to])
        {
            res[to].F=-res[v].F;
            res[to].S=e.S-res[v].S;
            dfs(to);
        }
        else
        {
            P p=P(res[to].F+res[v].F,res[to].S+res[v].S);
            if(p.F==0)
            {
                if(p.S==e.S) continue; else f=false; 
            }
            else
            {
                p.S=e.S-p.S;
                if(x==-INF) x=p.S/(double)p.F;
                else if(x!=p.S/(double)p.F) f=false;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v,x;
        scanf("%d%d%d",&u,&v,&x);
        G[u].push_back(P(v,x)); G[v].push_back(P(u,x));
    }
    f=true;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            tmp.clear(); pos.clear();
            x=-INF;
            res[i]=P(1,0);
            dfs(i);
            if(!f)
            {
                puts("NO");
                return 0;
            }
            if(x==-INF)
            {
                sort(pos.begin(),pos.end());
                x=pos[(int)pos.size()/2];
            }
            for(auto v:tmp) ans[v]=res[v].F*x+res[v].S;
        }
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%.10Lf ",ans[i]);
    return 0;
}