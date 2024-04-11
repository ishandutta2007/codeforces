#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define res(i,n) for(int i=0;i<n;++i)
#define eb emplace_back
#define mp make_pair
#define x0 fuckcjb
#define y0 fuckcxb
#define x1 fuckxjb
#define y1 fuckcjx
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=505+5,M=3e5+5,mod=1e9+7;
const ld eps=1e-9;
int n,m;
vector<int>g0,g1;
int x0[N],y0[N],x1[N],y1[N];

const long long inf = 2147483647ll*1000000ll;
struct EDGE { int adj, next; long long w; } edge[M];
int top, gh[N], nrl[N],S,T;
void addedge(int x, int y, long long w) {
    //printf("%d %d %lld\n",x,y,w);
    edge[++top].adj = y;
    edge[top].w = w;
    edge[top].next = gh[x];
    gh[x] = top;
    edge[++top].adj = x;
    edge[top].w = 0;
    edge[top].next = gh[y];
    gh[y] = top;
}
int dist[N], q[N];
int bfs() {
    memset(dist, 0, sizeof(dist));
    q[1] = S; int head = 0, tail = 1; dist[S] = 1;
    while (head != tail) {
        int x = q[++head];
        for (int p=gh[x]; p; p=edge[p].next)
            if (edge[p].w && !dist[edge[p].adj]) {
                dist[edge[p].adj] = dist[x] + 1;
                q[++tail] = edge[p].adj;
            }
    }
    return dist[T];
}
long long dinic(int x, long long delta) {
    if (x==T) return delta;
    for (int& p=nrl[x]; p && delta; p=edge[p].next)
        if (edge[p].w && dist[x]+1 == dist[edge[p].adj]) {
            long long dd = dinic(edge[p].adj, min(delta, edge[p].w));
            if (!dd) continue;
            edge[p].w -= dd;
            edge[p^1].w += dd;
            return dd;
        }
    return 0;
}
long long work() {
    long long ans = 0;
    while (bfs()) {
        memcpy(nrl, gh, sizeof(gh));
        long long t; while (t = dinic(S, inf)) ans += t;
    }
    return ans;
}


int main(){
    top=1;
    scanf("%d%d",&n,&m);
    rep(i,m){
        scanf("%d%d%d%d",x0+i,y0+i,x1+i,y1+i);++x1[i],++y1[i];
        g0.eb(x0[i]),g0.eb(x1[i]);
        g1.eb(y0[i]),g1.eb(y1[i]);
    }
    sort(g0.begin(),g0.end());
    g0.resize(unique(g0.begin(),g0.end())-g0.begin());
    sort(g1.begin(),g1.end());
    g1.resize(unique(g1.begin(),g1.end())-g1.begin());
    //for(int p:g0)printf("%d ",p);puts("");
    //for(int p:g1)printf("%d ",p);puts("");
    int u=g0.size(),v=g1.size();
    S=205,T=206;
    for(int i=0;i+1<u;++i)
        for(int j=0;j+1<v;++j)
            rep(k,m)if(x0[k]<=g0[i]&&g0[i+1]<=x1[k]&&y0[k]<=g1[j]&&g1[j+1]<=y1[k]){
                addedge(i+1,u+j+1,inf);
            }

    for(int i=0;i+1<u;++i)addedge(S,i+1,g0[i+1]-g0[i]);
    for(int j=0;j+1<v;++j)addedge(u+j+1,T,g1[j+1]-g1[j]);
        printf("%lld\n",work());
    return 0;
}