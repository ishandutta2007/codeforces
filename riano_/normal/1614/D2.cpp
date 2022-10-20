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
#define Tp tuple<int,int,int>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr)
using Graph = vector<vector<int>>;

const ll mod = 1e9+7;
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
vector<Pr> factor(int n) {
    // min_factor  sieve() 
    vector<Pr> res; int p=-1,cnt=0;
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

ll num = 1;
vector<ll> res2;
void search(vector<Pr> &p,ll i){
    int N = p.size();
    if(N==i){
        res2.push_back(num); return;
    }
    auto[x,c] = p[i];
    //cout << x << " " << c << endl;
    ll b = 1;
    rep(j,c+1){
        num *= b;
        search(p,i+1);
        num /= b;
        b *= x;
    }
}

vector<ll> div(vector<Pr> p){
    res2.clear();
    int N = p.size();
    search(p,0);
    return res2;
}

int main() {
    riano_; ll ans = 0;
    ll N; cin >> N;
    ll M = 2e7;
    //main
    min_factor = sieve(M+1); //n
    auto cnt = vll(M+1,0);
    rep(i,N){
        ll a; cin >> a;
        auto p = factor(a);
        auto v = div(p);
        for(ll y:v){
            //cout << y << endl;
            cnt[y]++;
        }
    }
    auto dp = vll(M+1,0);
    dp[1] = N;
    // for(int i=1;i<=M-1;i++){
    //     ll cc = 0;
    //     for(int j=i;j<=M;j+=i){
    //         cc += cnt[j];
    //     }
    //     cnt[i] = cc;
    // }
    for(int i=1;i<=M/2;i++){
        for(ll x:primes){
            if(x*i>M) break;
            ll j = i*x;
            chmax(dp[j],dp[i]+(ll)(j-i)*cnt[j]);
        }
    }
    rep(i,M+1){
        chmax(ans,dp[i]);
    }
    cout << ans << endl;
}