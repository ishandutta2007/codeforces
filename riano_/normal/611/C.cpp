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
using Graph = vector<vector<Tp>>;

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


//2
//2d acum-sum
vector<vector<ll>> acum(vector<vector<ll>> &a){
    ll N = a.size()+1;
    ll M = a[0].size()+1;
    vector<vector<ll>> res(N,vector<ll>(M,0));
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
ll sum2d(ll a1,ll b1,ll a2,ll b2,vector<vector<ll>> &v){
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
    

int main() {
    riano_; ll ans = 0;
    ll H,W; cin >> H >> W;
    char g[H][W];
    rep(i,H){
        rep(j,W) cin >> g[i][j];
    }
    auto yoko = v2ll(H,W,0);
    rep(i,H){
        rep(j,W-1){
            if(g[i][j]=='.'&&g[i][j+1]=='.'){
                yoko[i][j+1] = 1;
            }
        }
    }
    auto tate = v2ll(H,W,0);
    rep(i,H-1){
        rep(j,W){
            if(g[i][j]=='.'&&g[i+1][j]=='.'){
                tate[i+1][j] = 1;
            }
        }
    }
    auto vy = acum(yoko);
    auto vt = acum(tate);


    ll Q; cin >> Q;
    rep(i,Q){
        ll r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2;
        //cout << sum2d(r1,c1+1,r2,c2,vy) << " " << sum2d(r1+1,c1,r2,c2,vt) << endl;
        cout << sum2d(r1,c1+1,r2,c2,vy)+sum2d(r1+1,c1,r2,c2,vt) << "\n";
    }

    // ll N; string S,T; cin >> N >> S >> T;
    // if(T=="week"){
    //     if(N>=2&&N<=4){
    //         cout << 52 << endl;
    //     }
    //     else{
    //         cout << 53 << endl;
    //     }
    // }
    // else{
    //     if(N==31){
    //         cout << 7 << endl;
    //     }
    //     else if(N==30){
    //         cout << 11 << endl;
    //     }
    //     else{
    //         cout << 12 << endl;
    //     }
    // }
}