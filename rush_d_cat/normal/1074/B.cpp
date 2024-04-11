#include <iostream>
#include <vector>
using namespace std;
const int N = 1002;
int t,n,vis[N],flag[N],par[N];
vector<int> g[N];
int a[N],b[N];
void dfs(int u,int p){
    par[u]=p;
    for(auto v:g[u]){
        if(v==p)continue;
        dfs(v,u);
    }
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            g[i].clear(); vis[i]=0; flag[i]=0;
        }
        for(int i=2;i<=n;i++){
            int u,v; scanf("%d%d",&u,&v);
            g[u].push_back(v); g[v].push_back(u);
        }
        int k1; scanf("%d",&k1);
        for(int i=1;i<=k1;i++) {
            scanf("%d",&a[i]); vis[a[i]]=1;
        }
        int k2; scanf("%d",&k2);
        for(int i=1;i<=k2;i++) {
            scanf("%d",&b[i]); flag[b[i]]=1;
        }
        dfs(a[1],0);
        printf("B %d\n",b[1]); fflush(stdout);
        int pos; scanf("%d",&pos);
        if(vis[pos]==1) {
            printf("C %d\n", pos); fflush(stdout);
        } else {
            while(pos && vis[pos]==0) pos=par[pos];
            printf("A %d\n", pos); fflush(stdout);
            scanf("%d",&pos);
            if(flag[pos]==1) {
                printf("B %d\n", pos); fflush(stdout);
                scanf("%d",&pos);
                printf("C %d\n", pos); fflush(stdout);
            } else {
                printf("C -1\n"); fflush(stdout);
            }
        }   

    }
}