#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const int MAXN = (int)3e5 + 500;
const ll INF = (ll)1e18;

struct edge{
    int to, c, id;
    edge(int _to, int _c, int _id){to=_to, c=_c, id=_id;}
};

int n,m;
int u,v,w,s;
int pedge[MAXN], elen[MAXN];
ll dist[MAXN];
vector<edge> G[MAXN];
priority_queue<P, vector<P>, greater<P> > pque;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(edge(v,w,i));
        G[v].push_back(edge(u,w,i));
    }
    scanf("%d", &s);
    fill(dist, dist+MAXN, INF);
    dist[s] = 0;
    pque.push(P(0,s));
    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        ll dis = p.first, i = p.second;
        if(dis > dist[i]) continue;
        for(edge e : G[i]){
            if(dist[e.to] < dis + e.c) continue;
            if(dist[e.to] == dis + e.c && elen[e.to] < e.c) continue;
            pedge[e.to] = e.id, elen[e.to] = e.c;
            if(dist[e.to] != dis + e.c) pque.push(P(dis + e.c, e.to));
            dist[e.to] = dis + e.c;

        }
    }
    ll tw = 0;
    for(int i = 1; i <= n; i++) if(i != s) tw += elen[i];
    printf("%I64d\n", tw);
    for(int i = 1; i <= n; i++){
        if(i != s) printf("%d ", pedge[i]);
    }
}