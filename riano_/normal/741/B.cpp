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


//Unionfind
struct unionfind {
	//-1
	//id
	  vector<long long> r;
      vector<bool> lp;
	  unionfind(long long N) {
		    r = vector<long long>(N, -1);
            lp = vector<bool>(N,false);
	  }
	  long long root(long long x) {
		    if (r[x] < 0) return x;
		    return r[x] = root(r[x]);
	  }
	  bool unite(long long x, long long y) {
		    x = root(x);
		    y = root(y);
		    if (x == y){
                lp[x] = true;
                return false;
            }
		    if (r[x] > r[y]) swap(x, y);
		    r[x] += r[y];
		    r[y] = x;
            lp[x] = (lp[x]||lp[y]);
		    return true;
	  }
	  long long size(long long x) {
		    return max(-r[root(x)],0LL);
	  }
  
  // 2x, ytrue
    bool same(long long x, long long y) { 
        long long rx = root(x);
        long long ry = root(y);
        return rx == ry;
    }
 
    bool loop(ll x){
        return lp[root(x)];
    }
 
    //
    void eval(ll i,ll x){
        r[i] = (-1)*x;
    }
};


int main() {
    riano_; ll ans = 0;
    ll N,M,W; cin >> N >> M >> W;
    //main 
    unionfind uf(N+1);
    ll w[N],b[N];
    rep(i,N){
        cin >> w[i];
    }
    rep(i,N){
        cin >> b[i];
    }
    rep(i,M){
        ll a,c; cin >> a >> c; a--; c--;
        uf.unite(a,c);
    }
    vector<vector<Pr>> op(N);
    vector<vector<Pr>> hs(N);
    rep(i,N){
        hs[uf.root(i)].push_back(make_pair(w[i],b[i]));
    }
    rep(i,N){
        if(hs[i].size()!=0){
            op[i].push_back(make_pair(0LL,0LL));
            ll ws = 0,bs = 0;
            rep(j,hs[i].size()){
                auto[wn,bn] = hs[i][j];
                op[i].push_back(make_pair(wn,bn));
                ws += wn; bs += bn;
            }
            op[i].push_back(make_pair(ws,bs));
        }
    }
    ll dp[N+1][W+1];
    rep(i,N+1){
        rep(j,W+1) dp[i][j] = 0;
    }
    rep(i,N){
        rep(j,W+1){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            if(op[i].size()!=0){
                ll k = op[i].size();
                rep(l,k){
                    auto[wn,bn] = op[i][l];
                    if(j+wn<=W){
                        dp[i+1][j+wn] = max(dp[i+1][j+wn],dp[i][j]+bn);
                    }
                }
            }
        }
    }
    rep(i,W+1){
        ans = max(ans,dp[N][i]);
    }

    cout << ans << endl;
}