#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
#define all(v) v.begin(),v.end()
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr);typedef modint<mod> mint
using Graph = vector<vector<ll>>;

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
    riano_; ll ans = 0;
    ll N[4];
    rep(i,4) cin >> N[i];
    ll Nm = max({N[0],N[1],N[2],N[3]});
    vector<vector<ll>> cost(4,vector<ll>(1,0));
    vector<vector<Pr>> dp(4,vector<Pr>(1,make_pair(0LL,0LL)));
    rep(i,4){
        cost[i].assign(N[i],0);
        dp[i].assign(N[i],make_pair(2e18,0));
        rep(j,N[i]){
            cin >> cost[i][j];
        }
    }
    ll M[3];
    set<ll> emp;
    vector<vector<set<ll>>> fbd(4,vector<set<ll>>(Nm+1,emp));
    rep(i,3){
        cin >> M[i];
        rep(j,M[i]){
            ll x,y; cin >> x >> y;
            fbd[i+1][y].insert(x);
        }
    }
    rep(i,N[0]){
        dp[0][i] = make_pair(cost[0][i],i+1);
    }
    sort(all(dp[0]));
    rep(i,3){
        rep(j,N[i+1]){
            int s = 0;
            auto[c,idx] = dp[i][s];
            bool ok = true;
            while(fbd[i+1][j+1].count(idx)){
                s++;
                if(s==dp[i].size()||c>=2e18){
                    ok = false; break;
                }
                c = dp[i][s].first; idx = dp[i][s].second;
            }
            if(!ok){
                dp[i+1][j] = make_pair(2e18,j+1);
                continue;
            }
            dp[i+1][j] = make_pair(min(cost[i+1][j]+(ll)c,(ll)2e18),j+1);
        }
        sort(all(dp[i+1]));
    }
    ans = dp[3][0].first;
    if(ans>=2e18) ans = -1;
    cout << ans << endl;
}