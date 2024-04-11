#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const LL inf=1e14;
const int N=3000+10;
int t,n,m;
LL b[N],w[N];
LL f[N][N], g[N][N], sz[N], tf[N], tg[N];
vector<int> G[N];
void dfs(int u,int p){
    sz[u]=1;
    f[u][1]=0;
    g[u][1]=(w[u]-b[u]);
    for(auto v: G[u]){
        if(v==p)continue;
        dfs(v,u);
        for(int i=0;i<=sz[u]+sz[v];i++)tf[i]=tg[i]=-inf;
        /*
        for(int i=1;i<=sz[u];i++) {
            printf("u=%d,i=%d,[%lld, %lld]\n", u,i,f[u][i],g[u][i]);
        }
        for(int i=1;i<=sz[v];i++) {
            printf("v=%d,i=%d,{%lld, %lld}\n", v,i,f[v][i],g[v][i]);
        }
        */
        for(int i=1;i<=sz[u];i++)for(int j=1;j<=sz[v];j++){
            LL nex = f[u][i] + f[v][j];
            if(nex >= tf[i+j-1]){
                if(nex == tf[i+j-1]) {
                    if(g[u][i]+g[v][j]>tg[i+j-1]){
                        tg[i+j-1]=g[u][i]+g[v][j];
                    }
                } else {
                    tg[i+j-1]=g[u][i]+g[v][j];
                }
                tf[i+j-1]=nex;
                /*
                if (i + j - 1 == 2) {
                    printf("$ nex = %lld (%d,%d) (%d,%d) %lld\n", nex, u,i,v,j, tg[i+j-1]);
                }
                */
                //printf("%d = %lld\n", i+j-1,nex);
            }
        }
        for(int i=1;i<=sz[u];i++)for(int j=1;j<=sz[v];j++){
            LL nex = f[u][i] + f[v][j] + (g[v][j]>0?1:0);
            if(nex >= tf[i+j]){
                if(nex == tf[i+j]) {
                    if(g[u][i]>tg[i+j]){
                        tg[i+j]=g[u][i];
                    }
                } else {
                    tg[i+j]=g[u][i];
                }
                /*
                if(i+j==2) {
                    printf("$ nex = %lld\n", nex);
                }
                */
                tf[i+j]=nex;
            }
        }
        for(int i=0;i<=sz[u]+sz[v];i++){
            f[u][i]=tf[i], g[u][i]=tg[i];
        }
        /*
        if(u==2)
        for(int i=1;i<=sz[u]+sz[v];i++){
            printf("# f[%d][%d] = (%lld, %lld)\n", u,i,f[u][i], g[u][i]);
        } 
        */
        sz[u]+=sz[v];
    }
    
    for(int i=1;i<=sz[u];i++){
        //printf("f[%d][%d] = (%lld, %lld)\n", u,i,f[u][i], g[u][i]);
    } 
    
    
}
int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
        for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
        for(int i=1;i<=n;i++){
            G[i].clear(); 
            for(int j=0;j<=n;j++){
                f[i][j]=g[i][j]=-inf;
            }
        }
        for(int i=1;i<n;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,1);
        printf("%lld\n", f[1][m] + (g[1][m]>0?1:0));
    }
}