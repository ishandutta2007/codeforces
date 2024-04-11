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

ll solve(vector<ll> a,ll N,ll k){
    ll ans = 0;
    vector<ll> up(N+1,2e18),lw(N+1,-2e18);
    up[0] = 0,lw[0] = 0; up[N] = 0,lw[N] = 0;
    rep(i,N){
        if(a[i]!=0){
            chmin(up[i+1],up[i]+a[i]);
            chmax(lw[i+1],lw[i]+a[i]);
        }
        else{
            chmin(up[i+1],up[i]+k);
            chmax(lw[i+1],lw[i]-k);
        }
    }
    rrep(i,N){
        if(a[i]!=0){
            chmin(up[i],up[i+1]-a[i]);
            chmax(lw[i],lw[i+1]-a[i]);
        }
        else{
            chmin(up[i],up[i+1]+k);
            chmax(lw[i],lw[i+1]-k);
        }
    }

    // out(up);
    // out(lw);

    bool ok = true;
    rep(i,N+1){
        if(up[i]<lw[i]) ok = false;
    }
    if(!ok){
        return -1;
    }
    ll mn,mx;
    for(int i=1;i<N;i++){
        mn = lw[i]; mx = lw[i];
        ll x = lw[i];
        //cout << mx << endl;
        rep(j,i){
            chmax(mx,lw[j]); chmin(mn,lw[j]);
        }
        //cout << mx << endl;
        for(int j=i;j<N;j++){
            if(a[j]==0) x = min(up[j+1],x+k);
            else x += a[j];
            chmax(mx,x); chmin(mn,x);
            //cout << x << " ";
        }
        chmax(ans,mx-mn+1);

        //cout << endl;
        //cout << mx << " " << mn << endl;

        mn = up[i]; mx = up[i];
        x = up[i];
        rep(j,i){
            chmax(mx,up[j]); chmin(mn,up[j]);
        }
        for(int j=i;j<N;j++){
            if(a[j]==0) x = max(lw[j+1],x-k);
            else x += a[j];
            chmin(mn,x); chmax(mx,x);
            //cout << x << " ";
        }
        chmax(ans,mx-mn+1);


        //cout << endl;
        //cout << mx << " " << mn << endl;

        //cout << ans << endl;
    }
    return ans;
}


//Dijkstra
vector<ll> dijkstra(graph &g,int s){
    ll N = g.G.size();
    priority_queue<Pr, vector<Pr>, greater<Pr>> go;
    ll x,y,a,t,l; ll inf = 2e18;
    vector<ll> dist(N,inf);
    go.push(make_pair(0,s)); dist[s] = 0;
    Pr p;
    while(!go.empty()){
        p = go.top(); go.pop();
        x = p.first; y = p.second;
        if(x>dist[y]) continue;
        for(auto q:g.G[y]){
            a = get<0>(q); t = get<1>(q); l = get<2>(q);
            if(x+t<dist[a]){
                dist[a] = x+t;
                g.par_v[a] = y;
                g.par_e[a] = l;
                go.push(make_pair(x+t,a));
            }
        }
    }
    return dist;
}


int main(){
	riano_; ll ans = 0;
    ll N,k; cin >> N >> k;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    
    ans = solve(a,N,k);
    
    if(ans==-1){
        cout << -1 << endl; return 0;
    }
    ans = 0;

    graph g(N+1);
    rep(i,N){
        if(a[i]==0){
            g.unite(i,i+1,k,true);
            g.unite(i+1,i,k,true);
        }
        else{
            g.unite(i,i+1,(-1)*a[i],true);
            g.unite(i+1,i,a[i],true);
        }
    }
    g.unite(0,N,0,true); g.unite(N,0,0,true); 

    rep(i,N+1){
        auto v = dijkstra(g,i);
        rep(j,N+1) chmax(ans,v[j]+1);
        //rep(j,N+1) cout << v[j] << " ";
        // cout << endl;
    }

    cout << ans << endl;
}