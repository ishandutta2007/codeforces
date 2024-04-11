#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep2(i,n,k) for(int i=n-1;i>=n-k;i--)
#define vll(n,i) vector<long long>(n,i)
#define v2ll(n,m,i) vector<vector<long long>>(n,vll(m,i))
#define v3ll(n,m,k,i) vector<vector<vector<long long>>>(n,v2ll(m,k,i))
#define v4ll(n,m,k,l,i) vector<vector<vector<vector<long long>>>>(n,v3ll(m,k,l,i))
#define all(v) v.begin(),v.end()
#define chmin(k,m) k = min(k,m)
#define chmax(k,m) k = max(k,m)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr)
using Graph = vector<vector<int>>;

const ll mod = 998244353;
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
    modint & operator++(){
        val++;
        if (val == mod) val = 0;
        return *this;
    }
    modint operator++(int){
        modint<mod> res = *this;
        ++*this;
        return res;
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
typedef modint<mod> mint;
mint pw(long long a,long long b,long long m = mod){
    if(a%m==0) return mint(0);
    if(b==0) return mint(1);
    else if(b%2==0){
        long long x = pw(a,b/2,m).val;
        return mint(x*x);
    }
    else{
        long long x = pw(a,b-1,m).val;
        return mint(a*x);
    }
}
mint modinv(long long a, long long m = mod) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    return mint(u);
}
#define vm(n,i) vector<mint>(n,i)
#define v2m(n,m,i) vector<vector<mint>>(n,vm(m,i))
#define v3m(n,m,k,i) vector<vector<vector<mint>>>(n,v2m(m,k,i))
#define v4m(n,m,k,l,i) vector<vector<vector<vector<mint>>>>(n,v3m(m,k,l,i))


//dfs
//s: i:dfs t:
vector<int> vis; int t;
vector<int> depth;
vector<int> par;

// DP
vector<Pr> dp;
vector<vector<Pr>> dp_cand;
set<Pr> can;

//L
int L = 2e9;

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
        dp[s] = make_pair(0,s);
    }
    else{
        Pr tmp = make_pair(0,0);
        for(auto x:dp_cand[s]){
            //
            chmax(tmp,x);
        }
        dp[s] = tmp;
    }
    if(par[s]!=-1){
        dp_cand[par[s]].push_back(make_pair(dp[s].first+1,dp[s].second)); //
    }
    can.insert(dp[s]);
    // cout << s << endl;
    // cout << dp[s].first << " " << dp[s].second << endl;
}

vector<bool> ban(2e5+1,false);
ll rem = 0;

void erase1(ll s){
    ban[s] = true;
    rem--;
    //cout << s << " " << rem << endl;
    can.erase(dp[s]);
    if(par[s]!=-1&&!ban[par[s]]){
        erase1(par[s]);
    }
}

int main() {
    riano_; ll ans = -2e18;
    ll N,K; cin >> N >> K; rem = N;
    Graph G(N+1);
    rep(i,N-1){
        ll a,b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //main
    vis.assign(N+1,-1);
    depth.assign(N+1,-1);
    par.assign(N+1,-1);
    int s = 1;
    vis[s] = 0; depth[s] = 0; t = -1; //s:
    // DP
    dp.assign(N+1,make_pair(0,0));
    dp_cand.assign(N+1,vector<Pr>(0));
    dfs(G,s,0); //s: 0:dfs
    rep(i,K){
        if(!can.empty()){
            auto itr = can.end(); itr--;
            auto[d,st] = *itr;
            //cout << st << endl;
            erase1(st);
        }
        ll tmp = -2e18;
        if((i+1)-rem>=0) tmp = ((i+1)-rem)*(N-(i+1)-rem);
        else{
            ll k = (N)/2;
            chmin(k,rem);
            //chmax(k,0LL);
            tmp = ((i+1)-k)*(N-(i+1)-k);
        }
        chmax(ans,tmp);
        // cout << "---" << endl;
        // cout << i+1 << " " << rem << endl;
    }
    cout << ans << endl;
}