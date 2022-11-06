#include<bits/stdc++.h>
#define maxn 800030

using namespace std;
const int E=200000;
int a[maxn],ans,n,k,cnt,o,p[maxn],dis[maxn],lst;
bool is_prime[maxn];
int vis[maxn];
int tt,nxt[maxn],h[maxn],to[maxn];
int tmp,Nxt[maxn],g[maxn],To[maxn];
bool used[maxn];

void add_edge(int u,int v){
    ++tt; to[tt]=v;
    nxt[tt]=h[u]; h[u]=tt;
}

void add_vec(int u,int v){
    ++tmp; To[tmp]=v;
    Nxt[tmp]=g[u]; g[u]=tmp;
}

void dfs(int u){
    vis[u]=o+1; ans=max(ans,dis[u]+1);
    if (dis[u]>dis[lst]) lst=u;
    for (int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if (!used[v]) continue;
        if (vis[v]==o){
            dis[v]=dis[u]+1;
            dfs(v);
        }
    }
}

void work(int u){
    lst=u;
    o=0; dis[u]=0; dfs(u);
    o=1; dis[lst]=0; dfs(lst);
}

int main(){
    for (int i=2;i<maxn;i++) is_prime[i]=1;
    for (int i=2;i<maxn;i++) if (is_prime[i]){
        for (int j=2;j*i<maxn;j++) is_prime[i*j]=0;
    }
    cin >> n;
    for (int i=1;i<=n;i++){
        scanf("%d",&k);
        add_vec(k,i);
    }
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    for (int i=2;i<=E;i++){
        if (!is_prime[i]) continue;
        cnt=0;
        for (int j=1;j*i<=E;j++)
        for (int k=g[i*j];k;k=Nxt[k])
            p[++cnt]=To[k];
        for (int i=1;i<=cnt;i++) used[p[i]]=1;
        for (int i=1;i<=cnt;i++) if (!vis[p[i]]) work(p[i]);
        for (int i=1;i<=cnt;i++) dis[p[i]]=used[p[i]]=vis[p[i]]=0;
    }
    cout << ans << endl;
}