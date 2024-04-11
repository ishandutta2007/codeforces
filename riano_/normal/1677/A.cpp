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


//2
//2d acum-sum
vector<vector<int>> acum(vector<vector<int>> &a){
    ll N = a.size()+1;
    ll M = a[0].size()+1;
    vector<vector<int>> res(N,vector<int>(M,0));
    rep(i,N-1){
        rep(j,M-1){
            res[i+1][j+1] = res[i+1][j] + a[i][j];
        }
    }
    rep(i,N-1){
        rep(j,M-1){
            res[i+1][j+1] += res[i][j+1];
        }
    }
    return res;
}
// input:1-indexed
int sum2d(ll a1,ll b1,ll a2,ll b2,vector<vector<int>> &v){
    int N = v.size();
    int M = v[0].size();
    if(a1<1) a1 = 1;
    if(a1>N) a1 = N;
    if(a2<0) a2 = 0;
    if(a2>N-1) a2 = N-1;
    if(b1<1) b1 = 1;
    if(b1>M) b1 = M;
    if(b2<0) b2 = 0;
    if(b2>M-1) b2 = M-1;
    ll res = 0;
    res = v[a2][b2] - v[a1-1][b2] - v[a2][b1-1] + v[a1-1][b1-1];
    return res;
}
    
int main(){
	riano_; ll ans = 0;
    ll N,T;
    cin >> T;
    rep(ii,T){
        cin >> N; ans = 0;
        ll a[N];
        rep(i,N) cin >> a[i];
        vector<vector<int>> b(N,vector<int> (N,0));
        rep(i,N){
            rep(j,N){
                if(i<j&&a[i]>a[j]) b[i][j]++;
            }
        }
        auto v = acum(b);
        for(int i=1;i<=N;i++){
            ll sum = 0;
            for(int j=i+1;j<=N;j++){
                if(a[i-1]<a[j-1]&&i<j) ans += sum;
                sum -= (ll)sum2d(i+1,j+1,j,j+1,v);
                sum += (ll)sum2d(j,j+1,j,N,v);
            }
        }
        cout << ans << "\n";
    }
    //auto v = acum(a);

}