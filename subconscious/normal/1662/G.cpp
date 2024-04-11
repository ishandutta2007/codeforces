#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int N=1e6+5;
int n;
vi g[N];
ll siz[N],par[N];
void dfs(int x){
    siz[x]=par[x]=1;
    for(int v:g[x]){
        dfs(v);
        siz[x]+=siz[v];
        par[x]+=par[v]+siz[v];
    }
}
ll ans;
bitset<N>s;
priority_queue<int,vector<int>,greater<int>>pq;
ll sol(vector<int>&v){
    if(v.size()==0)return 0;
    sort(v.begin(),v.end());
    if(v.back()*2>=n-1)return (ll)v.back()*(n-1-v.back());
    s.reset();
    s[0]=1;
    for(int x:v)pq.push(x);
    while(!pq.empty()){
        int x=pq.top(),cnt=0;
        while(!pq.empty()&&pq.top()==x)++cnt,pq.pop();
        while(cnt>=3)pq.push(x*2),cnt-=2;
        rep(i,cnt)s|=s<<x;
    }
    ll ret=0;
    for(int i=0;i<=n-1;++i)if(s[i])ret=max(ret,(ll)i*(n-1-i));
    return ret;
}
void dfs2(int x,ll sz,ll pr){
    vi vec;
    vec.pb(sz);
    ll now=1+pr+sz;
    for(int v:g[x])now+=par[v]+siz[v],vec.pb(siz[v]);
    //printf("%d %lld\n",x,now);
    ans=max(ans,now+sol(vec));
    for(int v:g[x])dfs2(v,n-siz[v],now-par[v]-siz[v]);
}
int main() {
    scanf("%d",&n);
    rep(i,n-1){
        int x;scanf("%d",&x);
        g[x].pb(i+1);
    }
    dfs(1);
    ans=0;
    dfs2(1,0,0);
    printf("%lld\n",ans);
    return 0;
}