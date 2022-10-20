#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
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
    riano_; //ll ans = 0;
    ll N; cin >> N;
    vector<vector<ll>> a(N);
    vector<ll> eq(N);
    rep(i,N){
        a[i].push_back((ll)(-2e9));
        ll c; cin >> c;
        rep(j,c){
            ll b; cin >> b;
            a[i].push_back(b);
        }
        eq[i] = c;
    }
    set<vector<ll>> ban;
    ll M; cin >> M;
    rep(i,M){
        vector<ll> bs;
        rep(j,N){
            ll b; cin >> b;
            bs.push_back(b);
        }
        ban.insert(bs);
    }
    if(!ban.count(eq)){
        rep(i,N){
            cout << eq[i] << " ";
        }
        cout << endl; return 0;
    }
    //cout << "--------" << endl;
    ll mx = 0;
    vector<ll> ans;
    for(auto v:ban){
        ll p = 0;
        rep(i,N){
            p += a[i][v[i]];
        }
        rep(i,N){
            v[i]--;
            if(ban.count(v)){
                v[i]++;
                continue;
            }
            p -= a[i][v[i]+1]-a[i][v[i]];
            if(p>mx){
                ans = v; mx = p;
            }
            p += a[i][v[i]+1]-a[i][v[i]];
            v[i]++;
        }
    }
    rep(i,N){
        cout << ans[i] << " ";
    }
    cout << endl;
    //cout << ans << endl;
}