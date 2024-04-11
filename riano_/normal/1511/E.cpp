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


// abm
long long pw(long long a,long long b,long long m){
    if(b==0) return 1;
    else if(b%2==0){
        long long x = pw(a,b/2,m);
        return (x*x)%m;
    }
    else{
        long long x = pw(a,b-1,m);
        return (a*x)%m;
    }
}



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

int main() {
    riano_; mint ans = 0;
    //Grid(input)
    //grid#
    int H,W,N,M,inf;
    inf = 2000000000;
    cin >> H >> W;
    char grid[H+2][W+2];
    int l[H+2][W+2],u[H+2][W+2];
    for(int i=1;i<H+1;i++){
        for(int j=1;j<W+1;j++){
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<H+2;i++){
        grid[i][0]='#';
        grid[i][W+1]='#';
    }
    for(int i=0;i<W+2;i++){
        grid[0][i]='#';
        grid[H+1][i]='#';
    }
    //dp
    for(int i=0;i<=H+1;i++){
        for(int j=0;j<=W+1;j++){
            l[i][j] = 0;
            u[i][j] = 0;
        }
    }
    ll w = 0;
    rep(i,H){
        rep(j,W){
            if(grid[i+1][j+1]=='o'){
                w++;
                l[i+1][j+1] = l[i+1][j] + 1;
                u[i+1][j+1] = u[i][j+1] + 1;
            }
        }
    }

    // rep(i,H){
    //     rep(j,W){
    //         cout << l[i+1][j+1] << " ";
    //     }
    //     cout << endl;
    // }
    // rep(i,H){
    //     rep(j,W){
    //         cout << u[i+1][j+1] << " ";
    //     }
    //     cout << endl;
    // }
    ll cnt[300002];
    mint cc = 0; mint d = mint(1)/mint(4);
    cnt[1] = 0; cnt[0] = 0;
    rep(i,300000){
        cc += d;
        cnt[i+2] = cc.val;
        d /= mint(-2);
    }
    rep(i,H){
        rep(j,W){
            //cout << l[i+1][j+1] << " " << u[i+1][j+1] << endl;
            ans += mint(cnt[l[i+1][j+1]])*mint(pw(2LL,w,mod));
            ans += mint(cnt[u[i+1][j+1]])*mint(pw(2LL,w,mod));
            //cout << ans << endl;
        }
    }
    //ans *= mint(pw(2LL,w,mod));
    cout << ans << endl;
}