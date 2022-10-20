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
using Graph = vector<vector<Pr>>;

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

int main() {
    riano_; ll ans = 0;
    ll T; cin >> T;
    rep(ii,T){
        ll N,M; cin >> N >> M;
        vector<Tp> ed;
        Graph G(N+1);
        rep(i,N-1){
            ll a,b,c; cin >> a >> b >> c;
            ed.emplace_back(a,b,c);
            if(c!=-1){
                ll v = 0;
                rep(j,31){
                    if((1<<j)&c) v++;
                }
                G[a].emplace_back(b,v%2);
                G[b].emplace_back(a,v%2);
            }
        }
        rep(i,M){
            ll a,b,c; cin >> a >> b >> c;
            if(c!=-1){
                G[a].emplace_back(b,c);
                G[b].emplace_back(a,c);
            }
        }
        //Dijkstra ()
    priority_queue<Pr, vector<Pr>, greater<Pr>> go;
    ll x,y,a,t; ll inf = 2e18;
    ll dist[N+1],par[N+1]; //
    rep(j,N+1){
        dist[j] = inf; par[j] = -1;
    }
    bool bip = true;
    rep(i,N){
    int s = i+1;
    if(dist[s]!=inf) continue;
    go.push(make_pair(0,s)); dist[s] = 0; //:s
    Pr p;
    while(!go.empty()){
        p = go.top(); go.pop();
        x = p.first; y = p.second;
        if(x>dist[y]){
            continue;
        }
        for(auto q:G[y]){ //G[y]:Graph
            a = q.first; t = q.second;
            if(dist[a]==inf){
                dist[a] = x+t;
                par[a] = y;
                go.push(make_pair(x+t,a));
            }
            else{
                if((dist[a]+x+t)%2==1){
                    bip = false;
                }
            }
        }
    }
    }
    if(!bip){
        cout << "NO" << "\n"; continue;
    }
    cout << "YES" << "\n";
        rep(i,N-1){
            auto[a,b,c] = ed[i];
            if(c!=-1){
                cout << a << " " << b << " " << c << "\n";
            }
            else{
                cout << a << " " << b << " " << (dist[a]+dist[b])%2 << "\n";
            }
        }
        //cout << ans << "\n";
    }
}