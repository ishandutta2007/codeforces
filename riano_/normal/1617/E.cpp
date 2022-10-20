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


//tree
#define type long long
type el = 0;
vector<type> emp = {};
struct tree {
    long long N;
	vector<vector<pair<long long,long long>>> G;
    vector<long long> depth;
    // vector<long long> subtree_size; //
    // vector<long long> deg;
    // vector<long long> par;
    vector<int> vis;
    vector<type> dp; //DP
    vector<vector<type>> dp_cand;
    long long len;
    long long euler_time;
    long long limit_len = 2e9;
    vector<long long> from_e1; //
    vector<long long> from_e2; //
    long long cen,end1,end2,diam; //
    vector<vector<type>> fr; 
    vector<vector<type>> bc;
    vector<type> from_par;
    vector<type> reroot_dp; //DP
	tree(long long n) {
        N = n;
		G = vector<vector<pair<long long,long long>>>(N);
        depth = vector<long long>(N,-1);
        // par = vector<long long>(N,-1);
        // subtree_size = vector<long long>(N,1);
        // deg = vector<long long>(N,0);
	}
 
    //DP : 
    void dp_operation(long long s){
        //
        if(dp_cand[s].size()==0){
            dp[s] = el;
        }
        //
        else{
            
        }
        //
        // if(par[s]!=-1){
        //     dp_cand[par[s]].push_back(dp[s]);
        // }
    }
 
    //Euler Tour 
    void dfs_(long long s,long long i,bool dp_){
        len++;
        euler_time++;
        
        for(auto[nx,cost]:G[s]){
            if(len>=limit_len) break;
            if(vis[nx]==i) continue;
            depth[nx] = depth[s] + cost;
            vis[nx] = i;
            //par[nx] = s;
            dfs_(nx,i,dp_);
        }
        // if(par[s]!=-1){
        //     subtree_size[par[s]] += subtree_size[s];
        // }
        if(dp_) dp_operation(s);
        len--;
        
    }
	
    //c 
    void unite(long long a,long long b,long long c = 1){
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
        //deg[a]++; deg[b]++;
    }
 
    //lim  dfs_count 
    void dfs(long long rt,bool dp_ = false,long long lim = 2e9,long long dfs_count = 0){
        if(dfs_count==0) vis.assign(N,-1);
        if(dp_){
            dp.assign(N,el);
            dp_cand.assign(N,emp);
        }
        limit_len = lim;
        euler_time = -1;
        len = -1;
        vis[rt] = dfs_count; depth[rt] = 0;
        dfs_(rt,dfs_count,dp_);
    }
 
    long long diameter(void){
        dfs(1);
        from_e2 = depth;
        long long mx = -1;
        for(int i=0;i<N;i++){
            if(from_e2[i]>mx){
                end1 = i; mx = from_e2[i];
            }
        }
        dfs(end1);
        from_e1 = depth;
        mx = -1;
        for(int i=0;i<N;i++){
            if(from_e1[i]>mx){
                end2 = i; mx = from_e1[i];
            }
        }
        dfs(end2);
        from_e2 = depth;
        diam = mx;
        center();
        return diam;
    }
    long long center(void){
        for(int i=0;i<N;i++){
            if(from_e1[i]==from_e2[i]&&from_e2[i]==diam/2){
                cen = i; break;
            }
        }
        return cen;
    }
    vector<long long> adj(long long i){
        vector<long long> res;
        for(auto[x,c]:G[i]){
            res.push_back(x);
        }
        return res;
    }
    
};
    

int main() {
    riano_; ll ans = 0;
    ll N; cin >> N;
    //main
    tree tr(N*35);
    map<ll,ll> vtx;
    vector<ll> cont;
    map<ll,ll> idx;
    map<ll,ll> nx;
    ll id = 0;
    set<ll> num;
    rep(i,N){
        ll a; cin >> a;
        idx[a] = i+1;
        num.insert(a);
        // while(!vtx.count(a)){
        //     //cout << a << endl;
            
        //     vtx[a] = id; cont.push_back(a);
        //     id++;
        //     if(a==0) break;
        //     rep(j,31){
        //         if((1LL<<j)>=a){
        //             a = (1LL<<j)-a; break;
        //         }
        //     }
        //     if(!vtx.count(a)){
        //         tr.unite(id-1,id);
        //     }
        //     else{
        //         tr.unite(id-1,vtx[a]);
        //     }
        // }
    }
    while(num.size()>1){
        auto itr = num.end(); itr--;
        ll a = *itr; ll b;
        vtx[a] = id; id++; cont.push_back(a);
        rep(j,31){
            if((1LL<<j)>=a){
                b = (1LL<<j)-a; break;
            }
        }
        nx[a] = b;
        num.insert(b);
        num.erase(a);
    }
    auto itr2 = num.end(); itr2--; ll aa = *itr2;
    vtx[aa] = id; cont.push_back(aa);
    for(auto[x,n]:nx){
        tr.unite(vtx[x],vtx[n]);
    } 
    ans = tr.diameter();
    ll x = idx[cont[tr.end1]], y = idx[cont[tr.end2]];
    cout << x << " " << y << " " << ans << endl;
    //cout << ans << endl;
}