#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
vector <int> h[maxn];
int _,n,m,a,b,ban,p,q;
bool vis[maxn];
void dfs(int u){
    vis[u]=1;
    for (auto v:h[u]) if (v!=ban&&!vis[v]) dfs(v);
}
void solve(){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for (int i=1;i<=n;i++) h[i].clear();
    for (int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        h[u].pb(v); h[v].pb(u);
    }
    p=0; q=0;
    for (int i=1;i<=n;i++) vis[i]=0;
    ban=a; dfs(b);
    for (int i=1;i<=n;i++) p+=!vis[i];
    for (int i=1;i<=n;i++) vis[i]=0;
    ban=b; dfs(a);
    for (int i=1;i<=n;i++) q+=!vis[i];
    printf("%lld\n",1ll*(p-1)*(q-1));
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
    return 0;
}