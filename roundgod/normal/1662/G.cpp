#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1000005;
typedef bitset<maxn> bs;
bs A;
ll ans;
int n,sz[maxn],cnt[maxn];
vector<int> G[maxn];
void dfs(int u,int fa){
    sz[u]=1;
    for (auto v:G[u]){
        if (v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int Go(int u,int fa){
    for (auto v:G[u]){
        if (v==fa) continue;
        if (sz[v]>n/2) return Go(v,u);
    }
    return u;
}
void work(int x,int cnt){
    A|=A<<x;
    int y=1,res=cnt-1;
    while (y*2-1<res){
        y<<=1;
        A|=A<<(x*y);
        res-=y;
    }
    if (res) A|=A<<(x*res);
}
int main(){
    cin >> n;
    for (int i=2;i<=n;i++){
        int x;scanf("%d",&x);
        G[x].pb(i); G[i].pb(x);
    }
    dfs(1,0);
    int r=Go(1,0);
    dfs(r,0);
    for (int i=1;i<=n;i++) ans+=sz[i];
    for (auto x:G[r]) cnt[sz[x]]++;
    A.reset(); A[0]=1;
    for (int i=1;i<=n-1;i++) if (cnt[i]) work(i,cnt[i]);
    int best=0;
    for (int i=1;i<=(n-1)/2;i++) if (A[i]) best=i;
    ans+=1ll*best*(n-1-best);
    printf("%lld\n",ans);
    return 0;
}