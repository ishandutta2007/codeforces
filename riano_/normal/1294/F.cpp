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

    

int main() {
    riano_; ll ans = 0;
    ll N; cin >> N;
    Graph G(N+1);
    rep(i,N-1){
        ll a,b; cin >> a >> b;
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
    //tree_d1 and tree_d2 are vert. tree_diam = dist of them

    //BFS ()
    queue<int> go; ll dist[N+1]; // ll par[N+1];
    rep(i,N+1){
        dist[i] = 2000000000;
    }
    rep(i,N){
        if(depth1_treediameter[i+1]+depth2_treediameter[i+1]==tree_diam){
            go.push(i+1); dist[i+1] = 0;
        }
    }
    while(!go.empty()){
        int s = go.front(); go.pop();
        for(int x:G[s]){
            if(dist[x]<=dist[s]+1) continue;
            dist[x] = dist[s] + 1;
            //par[x] = s;
            go.push(x);
        }
    }
    int dd = 0,c = -1;
    rep(i,N){
        if(dd<dist[i+1]){
            dd = dist[i+1]; c = i+1;
        }
    }
    if(c<0){
        rep(i,N){
            if(i+1!=tree_d1&&i+1!=tree_d2){
                c = i+1; break;
            }
        }
    }
    ans = dd + tree_diam;
    cout << ans << endl;
    cout << tree_d1 << " " << tree_d2 << " " << c << endl;
}