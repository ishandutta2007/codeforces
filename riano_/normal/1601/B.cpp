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
#define vm(n,i) vector<mint>(n,i)
#define v2m(n,m,i) vector<vector<mint>>(n,vm(m,i))
#define v3m(n,m,k,i) vector<vector<vector<mint>>>(n,v2m(m,k,i))
#define v4m(n,m,k,l,i) vector<vector<vector<vector<mint>>>>(n,v3m(m,k,l,i))


int main() {
    riano_; ll ans = 0;
    ll N; cin >> N;
    ll aa[N],b[N];
    Graph G(2*N+1);
    rep(i,N){
        cin >> aa[i];
        G[N+i+1].push_back(make_pair(i+1-aa[i],1));
    }
    rep(i,N){
        cin >> b[i];
        G[i+1].push_back(make_pair(N+i+1+b[i],0));
    }
    rep(i,N){
        G[i].push_back(make_pair(i+1,0));
    }
    //Dijkstra ()
    priority_queue<Pr, vector<Pr>, greater<Pr>> go;
    ll x,y,a,t; ll inf = 2e18;
    ll dist[2*N+1],par[2*N+1]; //
    rep(j,2*N+1){
        dist[j] = inf; par[j] = -1;
    }
    go.push(make_pair(0,2*N)); dist[2*N] = 0; //:s
    Pr p;
    while(!go.empty()){
        p = go.top(); go.pop();
        x = p.first; y = p.second;
        if(x>dist[y]) continue;
        for(auto q:G[y]){ //G[y]:Graph
            a = q.first; t = q.second;
            if(x+t<dist[a]){
                dist[a] = x+t;
                par[a] = y;
                go.push(make_pair(x+t,a));
            }
        }
    }
    if(dist[0]==inf){
        cout << -1 << endl; return 0;
    }
    cout << dist[0] << endl;
    //
    //
    // map 
    int now = 0; //
    vector<ll> path;
    while(now!=-1){
        path.push_back(now);
        now = par[now];
    }
    reverse(path.begin(),path.end());
    int L = path.size();
    rep(i,L){
        if(i<L-1&&path[i+1]>N){
            cout << path[i] << " ";
        }
    }
    cout << 0 << " ";
    cout << endl;
    //cout << ans << endl;
}