#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s,t;
vector<int> G[MAXN],rG[MAXN];
int dist[MAXN],cnt[MAXN];
deque<P> que;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); rG[v].push_back(u);
    }
    scanf("%d%d",&s,&t);
    for(int i=1;i<=n;i++) dist[i]=INF;
    dist[t]=0;
    que.push_back(P(t,0));
    while(que.size())
    {
        P p=que.front(); que.pop_front();
        int v=p.F,d=p.S;
        if(d>dist[v]) continue;
        for(auto to:rG[v])
        {
            if(dist[to]>dist[v]+1)
            {
                dist[to]=dist[v]+1;
                cnt[to]=1;
                que.push_back(P(to,dist[to]));
            }
            else if(dist[to]==dist[v]+1) cnt[to]++;
            else continue;
            if(cnt[to]==(int)G[to].size())
            {
                dist[to]=dist[v];
                que.push_front(P(to,dist[to]));
            }
        }
    }
    if(dist[s]==INF) puts("-1"); else printf("%d\n",dist[s]);
    return 0;
}