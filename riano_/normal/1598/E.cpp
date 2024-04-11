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


//map add
void add(map<ll,ll> &cnt,ll a){
    if(cnt.count(a)) cnt[a]++;
    else cnt[a] = 1;
}

int main() {
    riano_; ll ans;
    ll N,M,Q; cin >> N >> M >> Q;
    ll dp[N+1][M+1][2];
    rep(i,N+1){
        rep(j,M+1){
            rep(k,2) dp[i][j][k] = 0;
        }
    }
    rep(i,N){
        rep(j,M){
            dp[i+1][j+1][0] = dp[i][j+1][1] + 1;
            dp[i+1][j+1][1] = dp[i+1][j][0] + 1;
        }
    }
    ll sum = 0;
    ll fr = N*M;
    rep(i,N+1){
        rep(j,M+1){
            rep(k,2) sum += dp[i][j][k];
        }
    }
    rep(i,Q){
        ll x,y; cin >> x >> y;
        if(dp[x][y][0]==0){
            fr++;
            ll s1 = dp[x-1][y][1] + 1;
            ll s2 = dp[x][y-1][0] + 1;
            int c = 0;
            int x2 = x,y2 = y;
            while(x2<=N&&y2<=M){
                if((x2!=x||y2!=y)&&dp[x2][y2][0]==0) break;
                dp[x2][y2][c%2] += s1; sum += s1;
                if(c%2==0) y2++;
                else x2++;
                c++;
            }
            c = 0;
            x2 = x; y2 = y;
            while(x2<=N&&y2<=M){
                if((x2!=x||y2!=y)&&dp[x2][y2][0]==0) break;
                dp[x2][y2][1-c%2] += s2; sum += s2;
                if(c%2==0) x2++;
                else y2++;
                c++;
            }
            cout << sum-fr << "\n";
        }
        else{
            fr--;
            ll s1 = dp[x][y][0];
            ll s2 = dp[x][y][1];
            int c = 0;
            int x2 = x,y2 = y;
            while(x2<=N&&y2<=M){
                if((x2!=x||y2!=y)&&dp[x2][y2][0]==0) break;
                dp[x2][y2][c%2] -= s1; sum -= s1;
                if(c%2==0) y2++;
                else x2++;
                c++;
            }
            c = 0;
            x2 = x; y2 = y;
            while(x2<=N&&y2<=M){
                if((x2!=x||y2!=y)&&dp[x2][y2][0]==0) break;
                dp[x2][y2][1-c%2] -= s2; sum -= s2;
                if(c%2==0) x2++;
                else y2++;
                c++;
            }
            cout << sum-fr << "\n";
        }
    }
    
}