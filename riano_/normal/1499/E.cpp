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
    riano_; mint ans = 0;
    string S,T; cin >> S >> T;
    ll N = S.size(); ll M = T.size();
    mint dp[N+1][M+1][2];
    rep(i,N+1){
        rep(j,M+1){
            if(i!=0){
                dp[i][j][0] = 1;
            }
            else{
                dp[i][j][0] = 0;
            }
            if(j!=0){
                dp[i][j][1] = 1;
            }
            else{
                dp[i][j][1] = 0;
            }
        }
    }
    rep(i,N+1){
        rep(j,M+1){
            rep(k,2){
                if(dp[i][j][k].val==0) continue;
                ans += dp[i][j][k];
                char c;
                if(k==0) c = S[i-1];
                else c = T[j-1];
                if(i<N&&c!=S[i]) dp[i+1][j][0] += dp[i][j][k];
                if(j<M&&c!=T[j]) dp[i][j+1][1] += dp[i][j][k];
            }
            //cout << i << " " << j << " " << ans << endl;
        }
    }
    mint db[M];
    rep(i,M) db[i] = 1;
    rep(i,M){
        ans -= mint(N+1)*(db[i]);
        if(i+1<M&&T[i]!=T[i+1]) db[i+1] += db[i]; 
    }
    mint da[N];
    rep(i,N) da[i] = 1;
    rep(i,N){
        ans -= mint(M+1)*(da[i]);
        if(i+1<N&&S[i]!=S[i+1]) da[i+1] += da[i]; 
    }
    cout << ans << endl;
}