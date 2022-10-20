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

//Graph
struct graph {
    long long N;
	vector<vector<tuple<long long,long long,int>>> G;
    vector<long long> par_v;
    vector<long long> par_e;
    int edge_count = 0;
    
	graph(long long n) {
        N = n;
		G = vector<vector<tuple<long long,long long,int>>>(N);
        par_v = vector<long long>(N,-1);
        par_e = vector<long long>(N,-1);
	}

    void unite(long long a,long long b,long long cost = 1,bool directed = false){
        G[a].emplace_back(b,cost,edge_count);
        if(!directed) G[b].emplace_back(a,cost,edge_count);
        edge_count++;
    }
};

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
void out(vector<ll> &v){
    for(ll x:v) cout << x << " ";
    cout << "\n"; return;
}


//segment tree
//1-indexed all
class segtree {
public:
    ll n;
    vector<ll> A;
    segtree(ll k){
        n = 1;
        while(n<k){ n *= 2; }
        A=vector<ll>(2*n,0);
    }

    //a[i]x
    void add(ll i,ll x){
        int index = n-1+i;
        A[index] += x;
        while(index>1){
            index /= 2;
            A[index] = max(A[2*index],A[2*index+1]);
        }
    }

    //a[i]
    void replace(ll i,ll x){
        int index = n-1+i;
        A[index] = x;
        while(index>1){
            index /= 2;
            A[index] = max(A[2*index],A[2*index+1]);
        }
    }

    //a[i]+a[i+1]++a[j]
    ll sum(ll i,ll j){
        if(j<i) return 0;
        return rangesum(i,j,1,1,n);
    }

    // a,b k c,d(k=1,c=1,d=n)
    ll rangesum(ll a,ll b,ll k,ll c,ll d){
        //
        ll el = 0;
        if(d<a||b<c){
            return el;
        }
        else if(a<=c&&d<=b){
            return A[k];
        }
        else{
            //2
            ll p = max(rangesum(a,b,k*2,c,(c+d)/2),rangesum(a,b,k*2+1,(c+d)/2+1,d));
            return p;
        }
    }

};

    
int main() {
    riano_; ll ans = 0;
    ll N,M,K,T; cin >> N;
    //main
    segtree seq(N+2);
    rep(i,N+1){
        seq.replace(i+1,i+1);
    }
    //  seq.replace(i,x);
    // 1-indexed !!!!!!
    vector<ll> f(N+1,2e18),l(N+1,-1);
    rep(i,N){
        ll a; cin >> a;
        chmin(f[a],(ll)i+1); chmax(l[a],(ll)i+1);
    }
    vector<Pr> p;
    rep(i,N){
        if(f[i+1]<l[i+1]) p.emplace_back(l[i+1],f[i+1]);
    }
    sort(all(p)); reverse(all(p));
    ll mx = 0; ll rm = N+1;
    rep(i,p.size()){
        auto[e,s] = p[i];
        //cout << s << " " << e << endl;
        while(e<=rm){
            chmax(mx,seq.sum(rm,rm)-rm); rm--;
        }
        // cout << mx << endl;
        // rep(j,6){
        //     cout << seq.sum(j+1,j+1) << " ";
        // }
        // cout << endl;
        ll m = seq.sum(s+1,e-1)-(s+1);
        chmax(m,mx+(e-s-1));
        //cout << m << endl;
        seq.replace(s,m+s);
        //cout << ans << endl;
    }
    rep(i,N+1){
        chmax(ans,seq.sum(i+1,i+1)-(ll)(i+1));
    }

    cout << ans << endl;
}