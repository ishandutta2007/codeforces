#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr);typedef modint<mod> mint
using Graph = vector<vector<int>>;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
    riano_; 
    ll N; cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    ll invsum = 0,ans = 0;
    vector<vector<ll>> br;
    vector<vector<ll>> nx; nx.push_back(a);
    for(int i=30;i>=0;i--){
        ll k = (1<<i);
        ll inv = 0,c0 = 0,c1 = 0,all = 0;
        br = nx; nx.clear();
        for(auto v:br){
            vector<ll> b,c;
            c0 = 0; c1 = 0;
            for(ll s:v){
                if((s&k)==0){
                    c0++; inv += c1;
                    b.push_back(s);
                }
                else{
                    c1++;
                    c.push_back(s);
                }
            }
            if(b.size()!=0){
                nx.push_back(b);
            }
            if(c.size()!=0){
                nx.push_back(c);
            }
            all += c0*c1;
        }
        
        if(inv*2>all){
            ans += k;
            inv = all - inv;
        }
        invsum += inv;
    }
    cout << invsum << " " << ans << "\n";
}