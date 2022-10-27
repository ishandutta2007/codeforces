#include <iostream>
#include <vector>
using namespace std;
const int N = 100000 + 10;

int n,m,t,par[N],T;
vector<int> g[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
pair<int,int> p[N];
struct Q {
    int t,x,y;
    void read() {
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d",&x,&y); g[y].push_back(x);
            par[find(x)]=find(y);
        }
        if(t==2){
            scanf("%d",&x);
            p[++T] = make_pair(x,find(x));
        }
        if(t==3){
            scanf("%d%d",&x,&y);
        }

    }
} q[N];


int fa[N][20],dep[N];
void dfs(int u,int p) {
    fa[u][0]=p,dep[u]=dep[p]+1;
    for(auto v: g[u]) {
        if(v==p) continue;
        //printf("%d->%d\n", u,v);
        dfs(v,u);
    }
}

int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    int d=dep[u]-dep[v];

    for(int i=19;i>=0;i--)if(d>>i&1)u=fa[u][i];
    if(u==v){
        return u;
    }
    for(int i=19;i>=0;i--) {
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i],v=fa[v][i];
        }
    }
    return fa[u][0];
}
bool vis[N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1;i<=m;i++) {
        q[i].read();
    }
    for(int i=1;i<=n;i++){
        if(vis[find(i)] == 0){
            dfs(find(i),find(i));vis[find(i)]=1;
        }
    }
    for(int i=1;i<20;i++) for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
    //printf("lca %d\n", lca(3,4)); return 0;
    for(int i=1;i<=m;i++) {
        if(q[i].t == 3) {
            int u = p[q[i].y].second;
            int v = p[q[i].y].first;
            //printf("%d - %d %d\n", u,v, q[i].x);
            if (lca(q[i].x, v) == q[i].x && lca(q[i].x, u) == u)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}