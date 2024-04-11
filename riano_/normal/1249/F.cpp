#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr);typedef modint<mod> mint
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


//squared tree dp
ll N,K;
//#define type vector<ll>
vector<ll> el; //dp
vector<vector<ll>> dp(2001); //
vector<vector<vector<ll>>> cand(2001);

vector<ll> a(201);

//dfs  merge
vector<int> vis;
vector<int> par;
void dfs(Graph &G, int s,int ii){
    
    //cout << s << endl;
    for(int nx:G[s]){
        if(vis[nx]==ii) continue;
        par[nx] = s;
        vis[nx] = ii;
        dfs(G,nx,ii);
    }

    if(cand[s].size()==0){
        dp[s] = el;
    }
    else{
        ll L = cand[s].size();
        //cout<< L << endl;
        dp[s] = el;
        for(ll i=0;i<=K;i++){
            if(i*2>=K){
                ll sum = 0;
                rep(j,L){
                    sum += cand[s][j][i];
                }
                dp[s][i] = sum;
            }
            else{
                ll mx = 0;
                rep(j,L){
                    ll sum = cand[s][j][i];
                    rep(k,L){
                        if(j==k) continue;
                        //cout << s << " " << k << " " << K-i << endl;
                        sum += cand[s][k][K-i];
                    }
                    mx = max(mx,sum);
                }
                dp[s][i] = mx;
            }
        }
    }

    dp[s][0] = dp[s][K]+a[s];  
    for(ll i=K;i>=1;i--){
        dp[s][i] = max(dp[s][i],dp[s][i-1]);
    }
    for(ll i=K;i>=1;i--){
        dp[s][i-1] = max(dp[s][i],dp[s][i-1]);
    }

    // cout << par[s] << " " << s << endl;
    // for(ll x:dp[s]){
    //     cout << x << " ";
    // }
    // cout << endl;
    //if(par[s]!=0) cand[par[s]].push_back(dp[s]);
    if(par[s]!=0) cand[par[s]].push_back(dp[s]);
}
    

int main() {
    riano_; //ll ans = 2e9;
    cin >> N >> K; K++;
    rep(i,N) cin >> a[i+1];
    //main
    Graph G(N+1);
    rep(i,N-1){
        ll a,b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    el.assign(K+1,0LL);

    int s = 1,ii = 0; //
    vis.assign(N+1,-1);
    par.assign(N+1,-1);
    vis[s] = 0; par[s] = 0;
    dfs(G,s,ii);

    cout << dp[1][0] << endl;
}