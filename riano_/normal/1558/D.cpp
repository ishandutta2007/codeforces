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
#define Tp tuple<int,int,int>
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


//Combination2
//10^6
//mod
vector<ll> fact;
vector<ll> invf;
ll comb(ll n,ll k){
    if(n<0||k<0||k>n) return 0LL;
    else{
        ll a = fact[n]*invf[k]%mod;
        a = a*invf[n-k]%mod;
        return a;
    }
}


//binary indexed tree
//1-indexed
class BIT {
public:
    ll n;
    vector<ll> a;
    BIT(ll k){
        n=k; a=vector<ll>(n+1,0);
    }

    //a[i]x
    void add(ll i,ll x){
        if(i==0) return;
        for(ll k=i;k<=n;k+=(k & -k)){
            a[k]+=x;
        }
    }

    //a[i]+a[i+1]++a[j]
    ll sum(ll i,ll j){
        return sum_sub(j)-sum_sub(i-1);
    }

    //a[0]+a[1]++a[i]
    ll sum_sub(ll i){
        ll s=0;
        if(i==0) return s;
        for(ll k=i;k>0;k-=(k & -k)){
            s+=a[k];
        }
        return s;
    }

    //a[0]+a[1]++a[i]>=xi(ka[k]>=0)
    ll lower_bound(ll x){
        if(x<=0){
            //x00
            return 0;
        }else{
            ll i=0;ll r=1;
            //
            //n(BIT)
            while(r<n) r=r<<1;
            //
            for(int len=r;len>0;len=len>>1) {
                //
                if(i+len<n && a[i+len]<x){
                    x-=a[i+len];
                    i+=len;
                }
            }
            return i+1;
        }
    }
};
  //main BIT seq(N);
  //  seq.add(a,b);
  //

int main() {
    riano_; ll ans = 0;
    //main
    //N:max
    ll N = 4e5+1;
    fact.assign(N+1,1LL);
    invf.assign(N+1,1LL);
    rep(i,N) fact[i+1] = fact[i]*(i+1)%mod;
    rep(i,N+1) invf[i] = modinv(fact[i],mod).val;
    ll T; cin >> T;
    BIT seq(2e5+2);
    rep(ii,T){
        ll M; cin >> N >> M;
        ll cnt = 0;
        set<ll> ones;
        vector<Pr> rev;
        rep(i,M){
            ll x,y; cin >> x >> y;
            rev.push_back(make_pair(x,y));
        }
        reverse(all(rev));
        ll up = N+1;
        ll bd = N+1;
        rep(i,M){
            ll x = rev[i].first; ll y = rev[i].second;
            ll s = up-x-1; up = x;
            // binary search
            //"r"
            ll l,r;
            // l = 1; r = N+1; //
            // while(l<r){
            //     ll c = (l+r)/2;
            //     //c
            //     ll br = N-c+1-seq.sum(c,N);
            //     if(br>s){//c"l"
            //         l = c+1;
            //     }
            //     else r = c;
            // }
            // bd = l;
            l = 1; r = N+1; //
            while(l<r){
                ll c = (l+r)/2;
                //c
                ll br = c-seq.sum(1,c);
                if(br<y){//c"l"
                    l = c+1;
                }
                else r = c;
            }
            ll pl = l;
            seq.add(pl,1); ones.insert(pl);
            if(seq.sum(pl+1,pl+1)==0){
                cnt++;
            }
            //cout << cnt << endl;
        }
        ans = comb(N+N-1-cnt,N-1-cnt);
        for(ll z:ones){
            seq.add(z,-1);
        }
        cout << ans%mod << "\n";
    }
    
}