#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=2e5+5;
const ll inf=1e18;
int T,n,k;
vi g[N];
int dep[N],to[N];
void dfs(int x,int fa){
    dep[x]=1,to[x]=x;
    for(int v:g[x])if(v!=fa){
        dfs(v,x);
        if(dep[v]+1>dep[x])dep[x]=dep[v]+1,to[x]=v;
    }
}
bool in[N];
set<pair<int,int>>pq;
void sol(int x){
    in[x]=0;
    for(int v:g[x])if(in[v]){
        if(v==to[x])sol(v);
        else pq.insert(mp(dep[v],v));
    }
}
int main(){
    {
        scanf("%d%d",&n,&k);
        rep(i,n)g[i].clear();
        rep(i,n-1){
            int x,y;scanf("%d%d",&x,&y);
            g[x].pb(y),g[y].pb(x);
        }
        int le=0;
        for(int i=2;i<=n;++i)
            if(g[i].size()==1)++le;
        dfs(1,0);
        pq.insert(mp(dep[1],1));
        int cnt=0;
        rep(i,n)in[i]=1;
        rep(now,k){
            if(pq.size()==0)break;
            auto it=(--pq.end());
            int x=it->nd;
            cnt+=it->st;
            pq.erase(it);
            sol(x);
        }
        ll ans=0;
        if(cnt==n){
            ans=-inf;
            for(int i=le;i<=k;++i)
                ans=max(ans,(ll)(n-i)*i);
        }else{
            ans=inf;
            for(int i=0;i<=n-cnt;++i)
                ans=min(ans,(ll)(n-k-i)*(k-i));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*


*/