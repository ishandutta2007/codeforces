#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep2(i,n,k) for(int i=n-1;i>=n-k;i--)
#define vll(n,i) vector<long long>(n,i)
#define v2ll(n,m,i) vector<vector<long long>>(n,vll(m,i))
#define v3ll(n,m,k,i) vector<vector<vector<long long>>>(n,v2ll(m,k,i))
#define v4ll(n,m,k,l,i) vector<vector<vector<vector<long long>>>>(n,v3ll(m,k,l,i))
#define all(v) v.begin(),v.end()
#define chmin(k,m) k = min(k,m)
#define chmax(k,m) k = max(k,m)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr)
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
    modint & operator++(){
        val++;
        if (val == mod) val = 0;
        return *this;
    }
    modint operator++(int){
        modint<mod> res = *this;
        ++*this;
        return res;
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
typedef modint<mod> mint;
mint pw(long long a,long long b,long long m = mod){
    if(a%m==0) return mint(0);
    if(b==0) return mint(1);
    else if(b%2==0){
        long long x = pw(a,b/2,m).val;
        return mint(x*x);
    }
    else{
        long long x = pw(a,b-1,m).val;
        return mint(a*x);
    }
}
mint modinv(long long a, long long m = mod) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    return mint(u);
}
#define vm(n,i) vector<mint>(n,i)
#define v2m(n,m,i) vector<vector<mint>>(n,vm(m,i))
#define v3m(n,m,k,i) vector<vector<vector<mint>>>(n,v2m(m,k,i))
#define v4m(n,m,k,l,i) vector<vector<vector<vector<mint>>>>(n,v3m(m,k,l,i))

int main() {
    riano_; ll ans = 0;
    ll T; cin >> T;
    rep(ii,T){
        ll N,M; cin >> N >> M;
        //Grid(input)
        //grid#
        int H,W,inf;
        inf = 2000000000;
        H = N; W = M;
        int lx,ly;
        char grid[H+2][W+2];
        for(int i=1;i<H+1;i++){
            for(int j=1;j<W+1;j++){
                cin >> grid[i][j];
                if(grid[i][j]=='L'){
                    lx = i,ly = j;
                }
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
        int dp[H+2][W+2];
        vector<Pr> dir = {make_pair(1,0),make_pair(0,1),make_pair(0,-1),make_pair(-1,0)};
        //dp
        for(int i=0;i<=H+1;i++){
            for(int j=0;j<=W+1;j++){
                if(grid[i][j]=='#'){
                    continue;
                }
                int c = 0;
                rep(k,4){
                    auto[dx,dy] = dir[k];
                    if(grid[i+dx][j+dy]!='#') c++;
                }
                dp[i][j] = c;
            }
        }
        //BFSonGrid
    queue<pair<int,int>> go;
    go.push(make_pair(lx,ly));  //
    dp[lx][ly] = 0;
    int x,y,dx,dy;
    pair<int,int> p;
    vector<pair<int,int>> step;
    step.push_back(make_pair(-1,0));
    step.push_back(make_pair(0,-1));
    step.push_back(make_pair(1,0));
    step.push_back(make_pair(0,1));
  
    //
    while(!go.empty()){
        p = go.front();
        go.pop();
        x = p.first;
        y = p.second;
        for(auto d : step){
            //
            dx = d.first; dy = d.second;
            if(grid[x+dx][y+dy]=='.'){
                dp[x+dx][y+dy]--;
                if(dp[x+dx][y+dy]<=1){
                    go.push(make_pair(x+dx,y+dy));
                    grid[x+dx][y+dy] = '+';
                }
            }
        }
    }
        rep(i,H){
            rep(j,W){
                    cout << grid[i+1][j+1];
            }
            cout << "\n";
        }

    }
    //cout << ans << endl;
}