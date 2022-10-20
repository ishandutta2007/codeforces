#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
#define all(v) v.begin(),v.end()
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr);typedef modint<mod> mint
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
    ll N; cin >> N;
    string S[N];
    rep(i,N) cin >> S[i];
    ll lim[N];
    vector<vector<int>> cnt(N,vector<int>(200001,0));
    ll dif[N];
    rep(i,N){
        int M = S[i].size();
        ll sc = 0;
        ll mn = 0;
        rep(j,M){
            if(S[i][j]=='(') sc++;
            else{
                sc--; mn = min(mn,sc);
                if(sc<=0){
                    if((-1)*sc+1<=200000&&cnt[i][(-1)*sc+1]==0){
                        cnt[i][(-1)*sc]++;
                    }
                }
            }
        }
        lim[i] = (-1)*mn;
        dif[i] = sc;
    }
    ll dp[(1<<N)][2];
    ll scr[(1<<N)];
    rep(i,(1<<N)){
        rep(j,2) dp[i][j] = -2e9;
        ll s = 0;
        rep(j,N){
            if((1<<j)&i) s += dif[j];
        }
        scr[i] = s;
    }
    dp[0][0] = 0; dp[0][1] = 0;
    rep(i,(1<<N)){
        rep(j,N){
            if(((1<<j)&i)==0) continue;
            ll tmp = i^(1<<j);
            if(lim[j]>scr[tmp]){
                if(0<=scr[tmp]&&scr[tmp]<=200000) dp[i][1] = max(dp[i][1],dp[tmp][0]+(ll)cnt[j][scr[tmp]]);
            }
            else{
                if(0<=scr[tmp]&&scr[tmp]<=200000) dp[i][0] = max(dp[i][0],dp[tmp][0]+(ll)cnt[j][scr[tmp]]);
            }
        }
    }
    rep(i,(1<<N)){
        rep(j,2) ans = max(ans,dp[i][j]);
    }
    cout << ans << endl;
}