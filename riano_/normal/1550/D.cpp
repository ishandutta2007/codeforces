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


//Combination2
//10^6
//mod
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
vector<ll> fact;
vector<ll> invf;
ll comb(ll n,ll k){
    if(n<0||k<0||k>n) return 0LL;
    else{
        ll a = fact[n]*invf[k]%mod;
        a = a*invf[n-k]%mod;
        return a;
    }
}
    

int main() {
    riano_; mint ans = 0;
    ll T; cin >> T;
    //main
    //N:max
    fact.assign(200000+1,1LL);
    invf.assign(200000+1,1LL);
    rep(i,200000) fact[i+1] = fact[i]*(i+1)%mod;
    rep(i,200000+1) invf[i] = modinv(fact[i],mod);
    rep(ii,T){
        //cout << "--------" << "\n";
        ll N,L,R; cin >> N >> L >> R;
        ans = 0;
        ll lm = max(1LL,min(R-N,(-1)*L));
        ans += mint((lm-1)*comb(N,N/2));
        if(N%2==1){
            ans += mint((lm-1)*comb(N,N/2+1));
        }
        for(ll i=lm;i<=lm+N;i++){
            //cout << lm << " " << ans << "\n";
            ll k = max(0LL,N+1-(R+1-i));
            ll s = max(0LL,L-1+i);
            //cout << k << " " << s << "\n";
            ans += mint(comb(N-k-s,N/2-k));
            if(N%2==1){
                ans += mint(comb(N-k-s,N/2+1-k));
            }
        }
        cout << ans << "\n";
    }
    //cout << ans << endl;
}