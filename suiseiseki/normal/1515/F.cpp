#include <cstdio>
typedef long long ll;
const int Maxn=300000;
ll sum;
ll a[Maxn+5];
int n,m,k;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],id[Maxn<<1|5],tot;
void add_edge(int from,int to,int t){
    arrive[++tot]=to;
    nxt[tot]=head[from];
    id[tot]=t;
    head[from]=tot;
}
bool vis[Maxn+5];
int lis[Maxn+5],f_lis_len,t_lis_len;
void init_dfs(int u){
    vis[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        int v=arrive[i];
        if(vis[v]){
            continue;
        }
        init_dfs(v);
        if(a[u]+a[v]>=k){
            a[u]+=a[v]-k;
            lis[++f_lis_len]=id[i];
        }
        else{
            lis[--t_lis_len]=id[i];
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v,i),add_edge(v,u,i);
    }
    if(sum<1ll*(n-1)*k){
        puts("NO");
        return 0;
    }
    else{
        puts("YES");
        f_lis_len=0,t_lis_len=n;
        init_dfs(1);
        for(int i=1;i<n;i++){
            printf("%d\n",lis[i]);
        }
    }
    return 0;
}