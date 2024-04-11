#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define MAXV 3005
#define MAXE 20005
#define MAXK 100005
#define INF 1000000000
#define mp make_pair
using namespace std;
typedef pair<int,int> P;
int V,E,k;
set< pair < P , int > > s;
vector<int> G[MAXV];
queue<P> que;
int d[MAXV][MAXV];
int prev[MAXV][MAXV];
int ans[MAXV];
int main()
{
    scanf("%d %d %d",&V,&E,&k);
    for(int i=0;i<E;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    s.clear();
    for(int i=0;i<k;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        s.insert(mp(mp(x,y),z));
    }
    que.push(P(0,1));
    for(int i=0;i<=V;i++)
        for(int j=0;j<=V;j++)
            d[i][j]=INF;
    d[0][1]=0;
     while (!que.empty())
    {
        P p=que.front();
        int u=p.first;
        int v=p.second;
        que.pop();
        for (int i=0;i<G[v].size();i++)
        {
            int w=G[v][i];
            if (v!=w&&d[v][w]==INF&&!s.count(mp(mp(u,v),w)))
            {
                prev[v][w]=u;
                d[v][w]=d[u][v]+1;
                que.push(P(v,w));
            }
        }
    }
    int t=1;
    for (int i=2;i<V;i++)
        if (d[i][V]<d[t][V]) t=i;
     if (d[t][V]==INF)
     {
         printf("-1\n");
         return 0;
     }
    ans[0]=V;ans[1]=t;int j=1;
    while (ans[j]!=1)
    {
        ans[j+1]=prev[ans[j]][ans[j-1]];
        j++;
    }
    printf("%d\n",j);
    for (int i=j;i>0;i--) printf("%d ",ans[i]); printf("%d\n",ans[0]);
    return 0;
}