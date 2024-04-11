#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 2522520 + 10;

int id(int x,int r) {
    return 2520*x + r;
}
int n;
int a[1002];

int par[N];
int find(int x) {
    return par[x]==x?x:par[x]=find(par[x]);
}
vector<int> g[1002];
vector<int> st;

int nex(int u){
//printf("nex %d\n", u);
    int x=u/2520;
    int r=u%2520;
//printf("x=%d, r=%d, id=%d\n", x,r,r%(int)g[x].size());
    int nx=g[x][r%(int)g[x].size()];
    int nr=(r+a[nx])%2520;
//printf("nx=%d, nr=%d\n", nx,nr);
//printf("--------------------------\n");
    return id(nx,nr);
}
bool vis[1002]; int ans[N],res[N];
int getlen(int u) {
//printf("getlen %d\n", u);
    vector<int> v;
    int t=nex(u);
//printf("u=%d, t=%d\n", u,t);
    vis[u/2520]=1; v.push_back(u/2520);
    while(t!=u){
        if(vis[t/2520]==0){
            vis[t/2520]=1; v.push_back(t/2520);
        }
        t=nex(t);
    }
    for(auto x: v) {
        vis[x]=0;
    }
//printf("finishied\n");
    return (int)v.size();
}

int main() {
    for(int i=1;i<N;i++) par[i]=i;
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        a[i]=(a[i]%2520 + 2520) % 2520;
    }
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        for(int j=0;j<x;j++){
            int y; scanf("%d",&y);
            g[i].push_back(y);
        }
    }
    for(int i=1;i<=n;i++){
        for(int r=0;r<2520;r++){
            int u=id(i,r);
            int j=g[i][r%(int)g[i].size()];
            int nr = (r + a[j]) % 2520;
            if(find(u) == find(id(j,nr))) {
                ans[find(u)] = getlen(u);
            } else {
                par[find(u)] = find(id(j,nr));
            }
        }
    }
    for(int i=0;i<N;i++) if(ans[i]) res[find(i)] = ans[i];
    int q; scanf("%d", &q);

//getlen(id(3,2519));
    while(q--) {
        int u,k; scanf("%d%d",&u,&k);
        k=(k%2520+2520)%2520; k=(k+a[u])%2520;
        //getlen(id(u,k));
        printf("%d\n", res[find(id(u,k))]);
    }
}