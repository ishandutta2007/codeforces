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
    

    
// 
ll gcd(ll x,ll y){
    ll r=1;
    if(x<0) x *= -1;
    if(y<0) y *= -1;
    if(x<=y) swap(x,y);
    if(y==0) r=0;
    while(r>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

// 
// "gcd"
ll lcm(ll x,ll y){
    ll a = gcd(x,y);
    return (x/a)*y;
}

vector<ll> conv(ll N){
    vector<ll> res;
    while(N>0){
        res.push_back(N%3); N /= 3;
    }
    res.push_back(0LL);
    return res;
}

ll ret(vector<ll> v){
    ll res = 0;
    ll base = 1;
    rep(i,v.size()){
        res += v[i]*base; base *= 3;
    }
    return res;
}

int main() {
    riano_; ll ans = 2e9;
    ll T; cin >> T;
    rep(ii,T){
        ll N; cin >> N;
        vector<ll> v = conv(N);
        ll M = v.size();
        ll s = -1;
        for(ll i=M-1;i>=0;i--){
            if(v[i]==2){
                v[i] = 0;
                s = i;
                for(ll j=i+1;j<M;j++){
                    if(v[j]==1){
                        v[j] = 0;
                    }
                    else{
                        v[j] = 1;
                        break;
                    }
                }
                break;
            }
        }
        for(ll i=s;i>=0;i--){
            v[i] = 0;
        }
        cout << ret(v) << "\n";
    }
    
}