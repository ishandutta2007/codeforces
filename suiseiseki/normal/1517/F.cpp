#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=300;
const int Mod=998244353;
const int inv_2=(Mod+1)>>1;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
    arrive[++tot]=to;
    nxt[tot]=head[from];
    head[from]=tot;
}
int f[Maxn+5][Maxn+5],g[Maxn+5][Maxn+5];
int max_d[Maxn+5];
int n,r;
void work_dfs(int u,int fa){
    static int tmp_f[Maxn+5],tmp_g[Maxn+5];
    f[u][0]=1,g[u][0]=1;
    max_d[u]=0;
    for(int i=head[u];i;i=nxt[i]){
        int v=arrive[i];
        if(v==fa){
            continue;
        }
        work_dfs(v,u);
        for(int j=0;j<=std::max(max_d[u],max_d[v]+1);j++){
            tmp_f[j]=tmp_g[j]=0;
        }
        for(int t_1=0;t_1<=max_d[u];t_1++){
            for(int t_2=0;t_2<=max_d[v];t_2++){
                tmp_f[std::min(t_1,t_2+1)]=(tmp_f[std::min(t_1,t_2+1)]+1ll*f[u][t_1]*f[v][t_2])%Mod;
                if(t_1+t_2+1<=r){
                    tmp_f[t_1]=(tmp_f[t_1]+1ll*f[u][t_1]*g[v][t_2])%Mod;
                }
                else{
                    tmp_g[t_2+1]=(tmp_g[t_2+1]+1ll*f[u][t_1]*g[v][t_2])%Mod;
                }
                if(t_1+t_2+1<=r){
                    tmp_f[t_2+1]=(tmp_f[t_2+1]+1ll*g[u][t_1]*f[v][t_2])%Mod;
                }
                else{
                    tmp_g[t_1]=(tmp_g[t_1]+1ll*g[u][t_1]*f[v][t_2])%Mod;
                }
                tmp_g[std::max(t_1,t_2+1)]=(tmp_g[std::max(t_1,t_2+1)]+1ll*g[u][t_1]*g[v][t_2])%Mod;
            }
        }
        max_d[u]=std::max(max_d[u],max_d[v]+1);
        for(int j=0;j<=max_d[u];j++){
            f[u][j]=tmp_f[j];
            g[u][j]=tmp_g[j];
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v),add_edge(v,u);
    }
    int lst=0,ans=0;
    for(int i=1;i<=n;i++){
        r=i;
        memset(f,0,sizeof f),memset(g,0,sizeof g);
        work_dfs(1,0);
        int now=0;
        for(int j=0;j<=n;j++){
            now=(now+f[1][j])%Mod;
        }
        ans=(ans+1ll*(now-lst+Mod)*(i-1))%Mod;
        lst=now;
    }
    ans=(ans-1+n)%Mod;
    for(int i=1;i<=n;i++){
        ans=1ll*ans*inv_2%Mod;
    }
    printf("%d\n",ans);
    return 0;
}