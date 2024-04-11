#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr);typedef modint<mod> mint
using Graph = vector<vector<int>>;

const ll mod = 1000000007;
template<uint64_t mod>
struct modint{
    uint64_t val;
    constexpr modint(const int64_t val_=0) noexcept:val((val_%int64_t(mod)+int64_t(mod))%int64_t(mod)){}
    constexpr modint operator-() const noexcept{
        return modint(*this)=mod-val;
    }
    constexpr modint operator+(const modint rhs) const noexcept{
        return modint(*this)+=rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept{
        return modint(*this)-=rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept{
        return modint(*this)*=rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept{
        return modint(*this)/=rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept{
        val+=rhs.val;
        val-=((val>=mod)?mod:0);
        return (*this);
    }
    constexpr modint &operator-=(const modint rhs) noexcept{
        val+=((val<rhs.val)?mod:0);
        val-=rhs.val;
        return (*this);
    }
    constexpr modint &operator*=(const modint rhs) noexcept{
        val=val*rhs.val%mod;
        return (*this);
    }
    constexpr modint &operator/=(modint rhs) noexcept{
        uint64_t ex=mod-2;
        modint now=1;
        while(ex){
            now*=((ex&1)?rhs:1);
            rhs*=rhs,ex>>=1;
        }
        return (*this)*=now;
    }
    constexpr bool operator==(const modint rhs) noexcept{
        return val==rhs.val;
    }
    constexpr bool operator!=(const modint rhs) noexcept{
        return val!=rhs.val;
    }
    friend constexpr ostream &operator<<(ostream& os,const modint x) noexcept{
        return os<<(x.val);
    }
    friend constexpr istream &operator>>(istream& is,modint& x) noexcept{
        uint64_t t;
        is>>t,x=t;
        return is;
    }
};

//tree diameter
//
int tree_d1,tree_d2;
vector<int> depth1_treediameter;
vector<int> depth2_treediameter;
void dfs1_treediameter(Graph &G, int s){
    for(int nx:G[s]){
        if(depth1_treediameter[nx]>=0) continue;
        depth1_treediameter[nx] = depth1_treediameter[s] + 1;
        dfs1_treediameter(G,nx);
    }
}
void dfs2_treediameter(Graph &G, int s){
    for(int nx:G[s]){
        if(depth2_treediameter[nx]>=0) continue;
        depth2_treediameter[nx] = depth2_treediameter[s] + 1;
        dfs2_treediameter(G,nx);
    }
}


//dfs
//s: i:dfs t:
vector<int> vis; int t;
vector<int> depth;
vector<int> par;

// DP
vector<ll> dp;
vector<vector<ll>> dp_cand;

//L
int L = 2e9;
bool safe = true;

void dfs(Graph &G, int s,int i){
    t++;
    for(int nx:G[s]){
        if(t>=L) break;
        if(vis[nx]==i) continue;
        depth[nx] = depth[s] + 1;
        vis[nx] = i;
        par[nx] = s;
        dfs(G,nx,i);
    }
    t--;
    //DP
    if(dp_cand[s].size()==0){
        // dp 
        dp[s] = depth[s];
    }
    else{
        ll tmp = 0;
        set<ll> dd;
        for(ll x:dp_cand[s]){
            //
            tmp = x;
            dd.insert(x);
        }
        dp[s] = tmp;
        if(s!=i&&dd.size()>1){
            safe = false;
        }
    }
    if(par[s]!=-1){
        dp_cand[par[s]].push_back(dp[s]); //
    }
}
    

int main() {
    riano_; ll ans = 0;
    ll N; cin >> N;
    Graph G(N+1);
    ll cnt[N+1];
    rep(i,N+1) cnt[i] = 0;
    rep(i,N-1){
        ll a,b; cin >> a >> b; cnt[a]++; cnt[b]++;
        G[a].push_back(b); G[b].push_back(a);
    }
    //main
    //N:size
    depth1_treediameter.assign(N+1,-1);
    depth2_treediameter.assign(N+1,-1);
    depth1_treediameter[1] = 0;
    dfs1_treediameter(G,1);
    int temp_diam = 0;
    for(int i=1;i<=N;i++){
        if(temp_diam<depth1_treediameter[i]){
            temp_diam = depth1_treediameter[i]; tree_d1 = i;
        }
    }
    depth2_treediameter[tree_d1] = 0;
    dfs2_treediameter(G,tree_d1);
    int tree_diam = 0;
    for(int i=1;i<=N;i++){
        if(tree_diam<depth2_treediameter[i]){
            tree_diam = depth2_treediameter[i]; tree_d2 = i;
        }
    }
    depth1_treediameter.assign(N+1,-1);
    depth1_treediameter[tree_d2] = 0;
    dfs1_treediameter(G,tree_d2);

    set<ll> dep;

    rep(i,N){
        //cout << i+1 << endl;
        //cout << cnt[i+1] << endl;
        if(cnt[i+1]!=1) continue;
        //cout << i+1 << endl;
        //cout << depth1_treediameter[i+1] << " " << depth2_treediameter[i+1] << endl;
        if(depth1_treediameter[i+1]==tree_diam&&depth2_treediameter[i+1]<=tree_diam) continue;
        if(depth1_treediameter[i+1]<=tree_diam&&depth2_treediameter[i+1]==tree_diam) continue;
        //cout << i+1 << endl;
        dep.insert(depth1_treediameter[i+1]);
        dep.insert(depth2_treediameter[i+1]);
    }
    if(dep.size()>1){
        cout << -1 << endl; return 0;
    }
    if(dep.size()==0){
        ans = tree_diam;
        while(ans%2==0){
            ans /= 2;
        }
        cout << ans << endl; return 0;
    }
    if(dep.size()==1){
        auto itr = dep.begin();
        ans = *itr;
        while(ans%2==0){
            ans /= 2;
        }
        ll cen = -1;
        rep(i,N){
            if(depth1_treediameter[i+1]==tree_diam/2&&depth2_treediameter[i+1]==tree_diam/2){
                cen = i+1; break;
            }
        }
        //main
        vis.assign(N+1,-1);
        depth.assign(N+1,-1);
        par.assign(N+1,-1);
        int s = cen;
        vis[s] = cen; depth[s] = 0; t = -1; //s:
        // DP
        dp.assign(N+1,-1);
        dp_cand.assign(N+1,vector<ll>());
        dfs(G,s,cen); //s: 0:dfs
        if(!safe){
            cout << -1 << endl; return 0;
        }
        cout << ans << endl; return 0;
        }

    //cout << ans << endl;
}