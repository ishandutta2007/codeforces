#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
#define all(v) v.begin(),v.end()
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr)
using Graph = vector<vector<ll>>;

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
    riano_;
    ll N,M; cin >> N >> M;
    Graph G(N+1);
    //main 
    unionfind uf(N+1);
    rep(i,M){
        ll a,b; cin >> a >> b;
        if(uf.same(a,b)) continue;
        uf.unite(a,b);
        G[a].push_back(b); G[b].push_back(a);
    }
    ll Q; cin >> Q;
    set<ll> end;
    vector<vector<ll>> ans(Q);
    rep(i,Q){
        ll a[2];
        rep(j,2){
            cin >> a[j];
            if(end.count(a[j])){
                end.erase(a[j]);
            }
            else{
                end.insert(a[j]);
            }
        }
        //BFS ()
        queue<int> go; ll dist[N+1],par[N+1]; // ll par[N+1];
        rep(i,N+1){
            dist[i] = 2000000000; par[i] = -1;
        }
        dist[a[0]] = 0; go.push(a[0]);
        while(!go.empty()){
            int s = go.front(); go.pop();
            for(int x:G[s]){
                if(dist[x]<=dist[s]+1) continue;
                dist[x] = dist[s] + 1;
                par[x] = s;
                go.push(x);
            }
        }

        //
        //
        // map 
        int now = a[1]; //
        vector<ll> path;
        while(now!=-1){
            path.push_back(now);
            now = par[now];
        }
        reverse(path.begin(),path.end());
        ans[i] = path;
    }
    if(end.empty()){
        cout << "YES" << endl;
        rep(i,Q){
            cout << ans[i].size() << endl;
            for(ll x:ans[i]){
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    else{
        cout << "NO" << endl;
        ll ss = end.size();
        cout << ss/2 << endl;
    }
}