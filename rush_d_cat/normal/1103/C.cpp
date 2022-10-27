#include <iostream>
#include <vector>
using namespace std;
const int N=250000+10;
int n,m,k,par[N],vis[N],B[N];
vector<int> g[N],tree[N],back[N];

void pre(int u){
    if(vis[u]) return;
    vis[u]=1;
    for(auto v: g[u]) {
        if(v==par[u]) continue;
        if(vis[v]==0){
            tree[u].push_back(v); par[v]=u;
            pre(v);
        } else {
            back[u].push_back(v);
        }
    }   
}

int dep[N];
void dfs(int u,int p){
    dep[u]=dep[p]+1;
    for(auto v:tree[u]){
        dfs(v,u);
    }
}

vector<int> cyl;
void prt(int u){

    int p1 = back[u][0];
    int p2 = back[u][1];
    //printf("u=%d, p1=%d, p2=%d\n", u,p1,p2);
    int x=-1;
    if((dep[u]-dep[p1])%3!=2)
        x=p1;
    if((dep[u]-dep[p2])%3!=2)
        x=p2;
    //printf("x=%d\n", x);
    cyl.clear();
    if(x!=-1){
        while(1){
            cyl.push_back(u);
            if(cyl.size()>N) return;
            if(u==x) break;
            u=par[u];
        }
        printf("%d\n", cyl.size());
        for(auto x: cyl)
            printf("%d ", x);
        printf("\n");
        return;
    }

    if(dep[p2]<dep[p1]) swap(p1,p2);
    cyl.push_back(u);
    u=p2; x=p1;
    while(1){
        cyl.push_back(u);
        if(cyl.size()>N) while(1);
        if(u==x) break;
        u=par[u];
    }
    printf("%d\n", cyl.size());
    for(auto x: cyl)
        printf("%d ", x);
    printf("\n");
    return;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    par[1]=1;
    pre(1);
    dfs(1,1);


    int mx=0,id=0;

    for(int i=1;i<=n;i++){
        if(dep[i]>=mx) {
            mx=dep[i], id=i;
        }
    }

    int leaf=0;
    for(int i=1;i<=n;i++){
        if(tree[i].size()==0) leaf++;
    }

    if(mx-1>=n/k) {
        printf("PATH\n");
        printf("%d\n", mx);
        int now=id;
        for(int i=1;i<=mx;i++){
            printf("%d ", now); now=par[now];
        }
    } else {
        printf("CYCLES\n");
        int tot=0;
        for(int i=1;i<=n;i++){
            if(tree[i].size()==0){
                ++tot; prt(i);
            }
            if(tot==k) break;
        }
    }

}