#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep2(i,n,k) for(int i=n-1;i>=n-k;i--)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
#define all(v) v.begin(),v.end()
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

vector<ll> col;
vector<map<ll,ll>> cnt;
vector<ll> sum;
vector<ll> mx;


//map add
void add(map<ll,ll> &cnt,ll a,ll n = 1){
    if(cnt.count(a)) cnt[a] += n;
    else cnt[a] = n;
}


void merge(ll s,ll p){
    if(cnt[s].size()>cnt[p].size()){
        swap(cnt[s],cnt[p]);
        swap(sum[s],sum[p]); swap(mx[s],mx[p]);
    }
    for(auto[a,c]:cnt[s]){
        add(cnt[p],a,c);
        if(cnt[p][a]>mx[p]){
            mx[p] = cnt[p][a]; sum[p] = a;
        }
        else if(cnt[p][a]==mx[p]){
            sum[p] += a;
        }
    }
}

//tree
#define type long long
type el = 0LL;
vector<type> emp = {};
struct tree {
    long long N;
	vector<vector<pair<long long,long long>>> G;
    vector<long long> depth;
    vector<long long> subtree_size;
    vector<long long> deg;
    vector<long long> par;
    vector<int> vis;
    vector<type> dp;
    vector<vector<type>> dp_cand;
    long long len;
    long long euler_time;
    long long limit_len = 2e9;
    vector<long long> from_e1;
    vector<long long> from_e2;
    long long cen,end1,end2,diam;
	tree(long long n) {
        N = n;
		G = vector<vector<pair<long long,long long>>>(N);
        depth = vector<long long>(N,-1);
        par = vector<long long>(N,-1);
        subtree_size = vector<long long>(N,1);
        deg = vector<long long>(N,0);
	}

    //DP : 
    void dp_operation(long long s){
        //
        if(dp_cand[s].size()==0){
            
        }
        //
        else{
            dp[s] = 0;
            for(type x:dp_cand[s]){
                
            }
        }
        //
        if(par[s]!=-1){
            dp_cand[par[s]].push_back(dp[s]);
        }
    }

    //Euler Tour 
    void dfs_(long long s,long long i,bool dp_){
        len++;
        euler_time++;
        cnt[s][col[s]] = 1; mx[s] = 1; sum[s] = col[s];
        
        for(auto[nx,cost]:G[s]){
            if(len>=limit_len) break;
            if(vis[nx]==i) continue;
            depth[nx] = depth[s] + cost;
            vis[nx] = i;
            par[nx] = s;
            dfs_(nx,i,dp_);
        }
        
        dp[s] = sum[s];
        if(par[s]!=-1){
            merge(s,par[s]);
            subtree_size[par[s]] += subtree_size[s];
        }
        if(dp_) dp_operation(s);
        len--;
        
        
    }
	
    //c 
    void unite(long long a,long long b,long long c = 1){
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
        deg[a]++; deg[b]++;
    }

    //lim  dfs_count 
    void dfs(long long rt,bool dp_ = false,long long lim = 2e9,long long dfs_count = 0){
        if(dfs_count==0) vis.assign(N,-1);
        dp.assign(N,el);
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
    tree tr(N+1);
    col.assign(N+1,0);
    sum.assign(N+1,0);
    mx.assign(N+1,0);
    map<ll,ll> em;
    cnt.assign(N+1,em);
    rep(i,N){
        cin >> col[i+1];
    }
    rep(i,N-1){
        ll a,b; cin >> a >> b;
        tr.unite(a,b);
    }
    tr.dfs(1);
    // for(auto[a,c]:cnt[2]){
    //     cout << a << " " << c << endl;
    // }
    rep(i,N) cout << tr.dp[i+1] << " ";
    cout << endl;
}