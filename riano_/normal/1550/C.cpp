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


int main() {
    riano_; ll ans = 0;
    ll T; cin >> T;
    rep(ii,T){
        ll N; cin >> N;
        ans = 0;
        ll a[N];
        rep(i,N) cin >> a[i];
        ans += N+(N-1);
        rep(i,N-2){
            if(a[i]<=a[i+1]&&a[i+1]<=a[i+2]) continue;
            if(a[i]>=a[i+1]&&a[i+1]>=a[i+2]) continue;
            ans++;
        }
        rep(i,N-3){
            if(a[i]<=a[i+1]&&a[i+1]<=a[i+2]) continue;
            if(a[i]>=a[i+1]&&a[i+1]>=a[i+2]) continue;
            if(a[i]<=a[i+1]&&a[i+1]<=a[i+3]) continue;
            if(a[i]>=a[i+1]&&a[i+1]>=a[i+3]) continue;
            if(a[i]<=a[i+2]&&a[i+2]<=a[i+3]) continue;
            if(a[i]>=a[i+2]&&a[i+2]>=a[i+3]) continue;
            if(a[i+1]<=a[i+2]&&a[i+2]<=a[i+3]) continue;
            if(a[i+1]>=a[i+2]&&a[i+2]>=a[i+3]) continue;
            ans++;
        }
        cout << ans << "\n";
    }
    //cout << ans << endl;
}