#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,d[MAXN][MAXN];
vector<int> G[MAXN];
bool vis[MAXN];
double p[MAXN];
double pp[MAXN];
void floyd_warshall()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=(i==j?0:INF);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        d[u][v]=d[v][u]=1;
        G[u].push_back(v); G[v].push_back(u);
    }
    floyd_warshall();
    double ans=0.0;
    for(int i=1;i<=n;i++)
    {
        double res=0.0;
        for(int j=0;j<=n-1;j++)
        {
            vector<int> canreach,canreach2;
            for(int k=1;k<=n;k++)
                if(d[i][k]==j)
                    canreach.push_back(k);
            if(!canreach.size())continue;
            double prob=(int)canreach.size()/(double)n;
            double cur=1.0/n;
            memset(vis,false,sizeof(vis));
            memset(p,0,sizeof(p));
            for(auto v:canreach)
                for(auto to:G[v])
                {
                    if(!vis[to]) canreach2.push_back(to);
                    vis[to]=true;
                    p[to]+=1.0/(n*(int)G[v].size());
                }
            for(int k=1;k<=n;k++)
            {
                double tmp=0.0;
                for(auto to:canreach2) pp[d[k][to]]=max(pp[d[k][to]],p[to]);
                for(auto to:canreach2)
                {
                    tmp+=pp[d[k][to]];
                    pp[d[k][to]]=0.0;
                }
                cur=max(cur,tmp);
            }
            res+=cur;
        }
        ans=max(ans,res);
    }
    printf("%.10f\n",ans);
    return 0;
}