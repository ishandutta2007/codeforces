#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 50000+10;
typedef long long LL;
int n,k,sz[N],mx[N],conquered[N];
vector<int> g[N],miao,nod;
void dfs_miao(int u,int p){
    sz[u]=1,mx[u]=0; miao.push_back(u);
    for(auto v: g[u]) {
        if(v==p||conquered[v])continue;
        dfs_miao(v,u);
        sz[u]+=sz[v]; mx[u]=max(mx[u],sz[v]);
    }
}
int getroot(int u){
    miao.clear(); dfs_miao(u,u);
    int minsize=N, root=0;
    for(auto x: miao) {
        mx[x] = max(mx[x], sz[u]-sz[x]);
        if(mx[x]<minsize) minsize=mx[x],root=x;
    }
    return root;
}
void dfs_init(int u,int p,int dep){
    nod.push_back(dep); 
    for(auto v: g[u]) {
        if(v==p||conquered[v])continue;
        dfs_init(v,u,dep+1);
    }
}
int cnt[502]; LL ans=0;
void Excalibur(int u,int p,int dep){
    memset(cnt,0,sizeof(cnt));
    cnt[0] ++; LL tmp=0;
    for(auto v: g[u]) {
        if(v==p||conquered[v])continue;
        nod.clear();
        dfs_init(v,u,1);
        for(auto x:nod){
            if(k-x>=0)tmp += cnt[k-x];
        }
        for(auto x:nod) {
            if(x<=k)cnt[x] ++;
        }
    }
    ans += tmp;
}
void divide_and_conquered(int u) {
    u=getroot(u); conquered[u]=1;
    Excalibur(u,u,0);
    for(auto v:g[u]) {
        if(conquered[v])continue;
        divide_and_conquered(v);
    }
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    divide_and_conquered(1);
    cout << ans << endl;
}