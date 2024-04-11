#include <bits/stdc++.h>
using namespace std;
#define ll int
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


//fast-zeta-transform
template <typename T>
vector<T> fast_zeta_trsf(vector<T>& f) {
    int n = f.size();
    vector<T> g = f;
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                g[j | i] += g[j];
            }
        }
    }
    return g;
}

int main() {
    riano_; long long ans = 0;
    ll N; cin >> N;
    auto cc = v2ll(N,26,0);
    rep(i,N){
        string S; cin >> S;
        rep(j,S.size()){
            ll a = S[j]-'a';
            cc[i][a]++;
        }
    }
    auto f = vm((1<<N),0);
    auto con = v2ll((1<<(min(N,13))),26,1e5);
    auto con2 = v2ll((1<<(max(0,N-13))),26,1e5);
    rep(i,(1<<(min(N,13)))){
        rep(j,min(N,13)){
            if(i&(1<<j)){
                rep(k,26){
                    chmin(con[i][k],cc[j][k]);
                }
            }
        }
    }
    rep(i,(1<<(max(0,N-13)))){
        rep(j,max(0,N-13)){
            if(i&(1<<j)){
                rep(k,26){
                    chmin(con2[i][k],cc[13+j][k]);
                }
            }
        }
    }
    rep(tmp,(1<<N)){
        if(tmp==0) continue;
        auto cn = vll(26,1e5);
        ll c = 0;
        rep(i,26){
            cn[i] = min(con[tmp%(1<<13)][i],con2[tmp/(1<<13)][i]);
        }
        rep(i,26){
            if(tmp&(1<<i)) c++;
        }
        // cout << tmp << " " << tmp%(1<<(N-1)) << endl;
        // rep(i,26){
        //     cout << con[tmp%(1<<(N-1))][i] << " ";
        // }
        // cout << endl;
        mint ptn = 1;
        rep(i,26) ptn *= mint(cn[i]+1);
        if(c%2==0) ptn *= mint(-1);
        f[tmp] = ptn;
        //cout << f[tmp] << endl;
    }
    auto g = fast_zeta_trsf(f);
    rep(tmp,(1<<N)){
        long long cf;
        long long c = 0,s = 0;
        rep(i,N){
            if(tmp&(1<<i)){
                s += (i+1);
                c++;
            }
        }
        cf = c*s;
        ans ^= (g[tmp].val*cf);
    }

    cout << ans << endl;
}