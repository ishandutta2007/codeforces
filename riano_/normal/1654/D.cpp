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

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

//Graph
struct graph {
    long long N;
	vector<vector<tuple<long long,long long,int>>> G;
    vector<long long> par_v;
    vector<long long> par_e;
    int edge_count = 0;
    
	graph(long long n) {
        N = n;
		G = vector<vector<tuple<long long,long long,int>>>(N);
        par_v = vector<long long>(N,-1);
        par_e = vector<long long>(N,-1);
	}

    void unite(long long a,long long b,long long cost = 1,bool directed = false){
        G[a].emplace_back(b,cost,edge_count);
        if(!directed) G[b].emplace_back(a,cost,edge_count);
        edge_count++;
    }
};

//map add
template <typename T>
void add(map<T,ll> &cnt,T a,ll n = 1){
    if(cnt.count(a)) cnt[a] += n;
    else cnt[a] = n;
}  

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
void out(vector<ll> &v){
    for(ll x:v) cout << x << " ";
    cout << "\n"; return;
}


vector<vector<pair<int,int>>> pf;
// //dfs
// //s: i:dfs t:
vector<int> vis; int t;
vector<int> depth;
mint ans;
mint now;
// //L
int L = 2e9;

void dfs(vector<vector<Tp>> &g, int s,int i,vector<int> &ps,vector<int> &ms){
    t++;
    ans += now;
    // cout << s << " " << now << endl;
    // rep(i,5){
    //     cout << ms[i] << " ";
    // }
    // cout << endl;
    for(auto[nx,org,rat]:g[s]){
        if(vis[nx]==i) continue;
        vis[nx] = i;
        for(auto p:pf[rat]){
            int x = p.first; int y = p.second; //xy
            ps[x] += y;
        }
        for(auto p:pf[org]){
            int x = p.first; int y = p.second; //xy
            ps[x] -= y; chmin(ms[x],ps[x]);
        }
        now *= rat; now /= org;
        dfs(g,nx,i,ps,ms);
        for(auto p:pf[rat]){
            int x = p.first; int y = p.second; //xy
            ps[x] -= y;
        }
        for(auto p:pf[org]){
            int x = p.first; int y = p.second; //xy
            ps[x] += y; //chmin(ms[x],ps[x]);
        }
        now *= org; now /= rat;
    }
    t--;
}


//
// nminfactor
vector<int> min_factor;
vector<ll> primes;
vector<int> sieve(int n) {
    vector<int> res(n+1);
    iota(res.begin(), res.end(), 0);
    for (int i = 2; i*i <= n; ++i) {
        if (res[i] < i) continue;
        for (int j = i*i; j <= n; j += i) {
            if (res[j] == j) res[j] = i;
        }
    }
    for(int i=2;i<=n;i++){
        if(res[i]==i){
            primes.push_back(i);
        }
    }
    return res;
}

// n("sieve")
// (p1,n1),(p2,n2),...
vector<pair<int,int>> factor(int n) {
    // min_factor  sieve() 
    vector<pair<int,int>> res; int p=-1,cnt=0;
    while (n > 1) {
        if(min_factor[n]!=p&&cnt>0){
            res.push_back(make_pair(p,cnt));
            p = min_factor[n]; cnt = 1;
        }
        else if(min_factor[n]!=p){
            p = min_factor[n]; cnt = 1;
        }
        else cnt++;
        n /= min_factor[n];
        // 
    }
    if(p!=-1) res.push_back(make_pair(p,cnt));
    return res;
}
    


int main(){
	riano_; //ll ans = 0;
    ll T; cin >> T;
    //main
    min_factor = sieve(2e5+1); //n
    //primes 
    
    rep(i,2e5+1){
        pf.push_back(factor(i));
    }
    
    
    rep(ii,T){
        ll N; cin >> N; 
        vector<vector<Tp>> G(N+1);
        vector<int> ps(N+1,0);
        vector<int> ms(N+1,0);
        mint all = 1;
        rep(i,N-1){
            ll a,b,c,d; cin >> a >> b >> c >> d;
            for(auto p:pf[c]){
                int x = p.first; int y = p.second; //xy
                ps[x] += y; ms[x] += y;
            }
            for(auto p:pf[d]){
                int x = p.first; int y = p.second; //xy
                ps[x] += y; ms[x] += y;
            }
            all *= mint(c*d);
            G[a].emplace_back(b,c,d); G[b].emplace_back(a,d,c);
        }
        //main
        vis.assign(N+1,-1);
        depth.assign(N+1,-1);
        int s = 1;
        vis[s] = 0; depth[s] = 0; t = -1; //s:
        ans = 0; now = all;
        dfs(G,s,0,ps,ms); //s: 0:dfs
        //cout << ans << "\n";
        rep(i,N+1){
            if(ms[i]==0) continue;
            //cout << i << " " << ms[i] << endl;
            ans /= pw(i,ms[i]);
        }
        
        cout << ans << "\n";
    }
    //cout << ans << "\n";
}