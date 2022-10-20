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

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

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

//map add
template <typename T>
void add(map<T,ll> &cnt,T a,ll n = 1){
    if(cnt.count(a)) cnt[a] += n;
    else cnt[a] = n;
}  

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


//fast-zeta-transform
template <typename T>
vector<T> fast_zeta_trsf(vector<T>& f) {
    int n = f.size();
    vector<T> g = f;
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < n; j++) {
            if ((j>>i) & 1) {
                g[j] += g[j^(1<<i)];
            }
        }
    }
    return g;
}

int main(){
	riano_; mint ans = 0;
    ll N; cin >> N;
    string S; cin >> S;
    ll c = 0;
    rep(i,N){
        if(S[i]=='?') c++;
    }

    auto dp1 = v2ll(N+1,N+1,0);
    auto dp2 = v2ll(N+1,N+1,0);
    auto f = v2m(18,(1<<17),0);
    auto p = v2m(18,1001,1);
    rep(i,1001){
        rep(j,18){
            p[j][i] = pw(j,i);
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=0;j<N;j++){
            if(j+i>N) break;
            if(i==1){
            }
            else if(i==2){
                if(S[j]=='?'&&S[j+1]=='?'){
                    dp2[j][j+i] = 1;
                }
                else if(S[j]=='?'){
                    dp1[j][j+i] = (1<<((int)(S[j+1]-'a')));
                    dp2[j][j+i] = 1;
                }
                else if(S[j+1]=='?'){
                    dp1[j][j+i] = (1<<((int)(S[j]-'a')));
                    dp2[j][j+i] = 1;
                }
                else{
                    if(S[j]==S[j+1]){

                    }
                    else{
                        dp1[j][j+i] = -1;
                    }
                }
            }
            else{
                if(dp1[j+1][j+i-1]==-1){
                    dp1[j][j+i] = -1;
                }
                else{
                    if(S[j]=='?'&&S[j+i-1]=='?'){
                        dp1[j][j+i] = dp1[j+1][j+i-1];
                        dp2[j][j+i] = dp2[j+1][j+i-1]+1;
                    }
                    else if(S[j]=='?'){
                        dp1[j][j+i] = ((1<<((int)(S[j+i-1]-'a')))|dp1[j+1][j+i-1]);
                        dp2[j][j+i] = dp2[j+1][j+i-1]+1;
                    }
                    else if(S[j+i-1]=='?'){
                        dp1[j][j+i] = ((1<<((int)(S[j]-'a')))|dp1[j+1][j+i-1]);
                        dp2[j][j+i] = dp2[j+1][j+i-1]+1;
                    }
                    else{
                        if(S[j]==S[j+i-1]){
                            dp1[j][j+i] = dp1[j+1][j+i-1];
                            dp2[j][j+i] = dp2[j+1][j+i-1];
                        }
                        else{
                            //cout << j << " " << j+i << "\n";
                            dp1[j][j+i] = -1;
                        }
                    }
                }
            }
            if(dp1[j][i+j]==-1) continue;
            rep(k,18){
                f[k][dp1[j][i+j]] += p[k][c-dp2[j][j+i]];
            }
            //cout << j << " " << j+i << " " << dp1[j][i+j] << " " << c-dp2[j][j+i] << "\n";
        }
    }

    auto g = v2m(18,(1<<17),0);
    rep(i,18){
        // if(i==1){
        //     rep(j,4) cout << f[i][j] << " ";
        // }
        // cout << "\n";
        g[i] = fast_zeta_trsf(f[i]);
    }
    //cout << g[0].size() << endl;
    ll Q; cin >> Q;
    rep(i,Q){
        string T; cin >> T;
        ll M = T.size();
        ll tmp = 0;
        rep(j,M){
            tmp += (1<<((int)(T[j]-'a')));
        }
        //cout << M << " " << tmp << endl;
        cout << g[M][tmp] << "\n";
    }
	//cout << ans << endl;
}