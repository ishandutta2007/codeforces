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
int n,m,a[MAXN];
vector<int> G[MAXN],rG[MAXN];
int dist[MAXN],maxi[MAXN],num[MAXN];
bool vis[MAXN];
map<P,int> cnt;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        cnt[P(u,v)]++;
    }
    for(auto p:cnt)
    {
        int u=p.F.F,v=p.F.S,mult=p.S;
        G[u].push_back(v); rG[v].push_back(u); num[u]+=mult;
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++) {dist[i]=INF; } dist[n]=0;
    priority_queue<P,vector<P>,greater<P> >pq;
    pq.push(P(0,n));
    while(pq.size())
    {
        P p=pq.top(); pq.pop();
        int v=p.S,d=p.F;
        if(vis[v]) continue;
        vis[v]=true;
        for(auto to:rG[v])
        {
            if(vis[to]) continue;
            num[to]-=cnt[P(to,v)];
            if(num[to]+d+1<dist[to])
            {
                dist[to]=num[to]+d+1;
                pq.push(P(dist[to],to));
            }
        }
    }
    printf("%d\n",dist[1]);
    return 0;
}