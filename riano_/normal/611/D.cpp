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
using Graph = vector<vector<Tp>>;

const ll mod = 1e9+7;
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


//segment tree
//1-indexed all
class segtree {
public:
    ll n;
    vector<ll> A;
    segtree(ll k){
        n = 1;
        while(n<k){ n *= 2; }
        A=vector<ll>(2*n,2e18);
    }

    //a[i]
    void replace(ll i,ll x){
        int index = n-1+i;
        A[index] = x;
        while(index>1){
            index /= 2;
            A[index] = min(A[2*index],A[2*index+1]);
        }
    }

    //a[i]+a[i+1]++a[j]
    ll sum(ll i,ll j){
        return rangesum(i,j,1,1,n);
    }

    // a,b k c,d(k=1,c=1,d=n)
    ll rangesum(ll a,ll b,ll k,ll c,ll d){
        //
        ll el = 2e18;
        if(d<a||b<c){
            return el;
        }
        else if(a<=c&&d<=b){
            return A[k];
        }
        else{
            //2
            ll p = min(rangesum(a,b,k*2,c,(c+d)/2),rangesum(a,b,k*2+1,(c+d)/2+1,d));
            return p;
        }
    }

};

    //main
    segtree seq(5002);
    //  seq.replace(i,x);
    // 1-indexed !!!!!!

int main() {
    riano_; mint ans = 0;
    ll N; cin >> N;
    string S; cin >> S;
    rep(i,N) S += '0';
    ll M = N/2;
    vector<pair<string,int>> num;
    rep(i,N){
        num.emplace_back(S.substr(i,M),i);
    }
    sort(all(num));
    vector<ll> perm(N);
    rep(i,N){
        auto[T,id] = num[i];
        //cout << T << " " << id << endl;
        perm[id] = i;
        if(i!=N-1){
            string U = num[i+1].first;
            int div = 1;
            rep(j,M){
                if(T[j]!=U[j]) break;
                div++;
            }
            //cout << i+1 << " " << div << endl;
            seq.replace(i+1,div);
        }
    }
    auto dp = v2m(N+2,N+2,0);
    rep(i,N){
        dp[i+1][i+1] = 1;
    }

    // rep(i,N){
    //     cout << perm[i] << endl;
    // }

    rep(i,N-1){
        if(S[i+1]=='0') continue;
        rep(j,N+1){
            if(i+j+1>N) break;
            if(j>i+1) break;
            if(dp[i+1][j]==0) continue;
            if(perm[i-j+1]<perm[i+1]&&seq.sum(perm[i-j+1]+1,perm[i+1])<=j){
                dp[i+1+j][j] += dp[i+1][j];
            }
            else{
                dp[i+j+2][j+1] += dp[i+1][j];
            }
        }
        rep(j,N){
            if(i+3+j>N) break;
            dp[i+3+j][j+2] += dp[i+2+j][j+1];
        }
    }
    rep(i,N+1){
        //if(S[N-i]=='0') continue;
        ans += dp[N][i];
    }
    cout << ans << endl;
}