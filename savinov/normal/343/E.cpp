#include<cstdio>
#include<algorithm>
#include<vector>

#define rep(i,l,r) for (int i=l; i<=r; ++i)
#define pb push_back

using namespace std;

typedef vector<int> VI;

const int N=220,M=1010;
const int INF=1e9;

int n,m,c[N][N],ans,an[N];

struct edge{
    int to,nx,rs,rs0;
} ee[M*4];
int eq[N],en=1,vis[N],V,hei[N],que[N],ql,qr,S,T;

void link(int u,int v,int w){
    ee[++en]=(edge){v,eq[u],w,w},eq[u]=en;
    ee[++en]=(edge){u,eq[v],0,0},eq[v]=en;
}
bool bnic(){
    vis[T]=++V;
    hei[T]=0;
    for (que[ql=qr=1]=T; ql<=qr; ql++){
        int u=que[ql];
        for (int j=eq[u],v; v=ee[j].to,j; j=ee[j].nx)
            if (ee[j^1].rs && vis[v]!=V){
                vis[v]=V;
                hei[v]=hei[u]+1;
                que[++qr]=v;
                if (v==S) return 1;
            }
    }
    return 0;
}
int dinic(int u,int p){
    if (u==T || !p) return p;
    int flow=0;
    for (int j=eq[u],v; v=ee[j].to,j; j=ee[j].nx)
        if (ee[j].rs && vis[v]==V && hei[v]==hei[u]-1){
            int f=dinic(v,min(p,ee[j].rs));
            p-=f,flow+=f;
            ee[j].rs-=f,ee[j^1].rs+=f;
            if (!p) return flow;
        }
    hei[u]=INF;
    return flow;
}
int runflow(){
    rep(i,1,en) ee[i].rs=ee[i].rs0;
    int ret=0;
    while (bnic())
        ret+=dinic(S,INF);
    bnic();
    return ret;
}
void prepare(VI vs){
    if (vs.size()==1) return;
    S=vs[0];
    T=vs[1];
    int tmp=runflow();
    rep(u,1,n) rep(v,1,n)
        if((vis[u]==V) ^ (vis[v]==V)){
            c[u][v]=min(c[u][v],tmp);
        }
    VI vl,vr;
    rep(i,0,vs.size()-1){
        int u=vs[i];
        if (vis[u]==V) vl.pb(u);
        else vr.pb(u);
    }
    prepare(vl);
    prepare(vr);
}
void solve(VI vs){
    if (vs.size()==1) {
        an[++an[0]]=vs[0];
        return;
    }
    S=vs[0];
    int bst=INF;
    rep(i,1,vs.size()-1){
        int tmp=c[S][vs[i]];
        if (tmp<bst) bst=tmp,T=vs[i];
    }
    ans+=runflow();

    VI vl,vr;
    rep(i,0,vs.size()-1){
        int u=vs[i];
        if (vis[u]==V) vl.pb(u);
        else vr.pb(u);
    }
    solve(vl);
    solve(vr);
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        link(u,v,w);
        link(v,u,w);
    }
    rep(u,1,n) rep(v,1,n) c[u][v]=INF;
    VI all;
    rep(i,1,n) all.pb(i);
    prepare(all);
    solve(all);

    printf("%d\n",ans);
    rep(i,1,n) printf("%d ",an[i]);
}