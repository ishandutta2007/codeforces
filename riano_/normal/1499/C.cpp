#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
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


int main() {
    riano_; ll ans;
    ll T; cin >> T;
    rep(ii,T){
        ans = 2e18;
        ll N; cin >> N;
        ll cs[N];
        rep(i,N) cin >> cs[i];
        ll m1 = cs[0],m2 = cs[1]; ll c1 = N,c2 = N;
        ll sum = m1*c1+m2*c2;
        ans = min(ans,sum);
        for(int i=2;i<N;i++){
            if(i%2==0){
                if(m1>cs[i]){
                    sum += (c1-1)*(cs[i]-m1);
                    c1--; m1 = cs[i];
                }
                else{
                    sum += (cs[i]-m1);
                    c1--;
                }
            }
            else{
                if(m2>cs[i]){
                    sum += (c2-1)*(cs[i]-m2);
                    c2--; m2 = cs[i];
                }
                else{
                    sum += (cs[i]-m2);
                    c2--;
                }
            }
            ans = min(ans,sum);
        }
        cout << ans << endl;
    }    
    //cout << ans << endl;
}