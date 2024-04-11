#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
// const long long MOD=1e9+7;
const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();++itr){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();++itr){
        os << *itr;
        if (++itr!=s.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}

void debug_out(){cerr << '\n';}
template<class Head,class... Tail>
void debug_out(Head&& head,Tail&&... tail){
    cerr << head;
    if (sizeof...(Tail)>0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...) cerr << " ";\
cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n';\
cerr << " ";\
debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}
#pragma endregion

template<uint_fast64_t Modulus> class modint{
    using u64=uint_fast64_t;
    public:
    u64 a;
    constexpr modint(const u64 x=0) noexcept:a(x%Modulus){}
    constexpr u64 &value() noexcept{return a;}
    constexpr const u64 &value() const noexcept{return a;}
    constexpr modint &operator+=(const modint &rhs) noexcept{
        a+=rhs.a;
        if (a>=Modulus) a-=Modulus;
        return *this;
    }
    constexpr modint operator+(const modint &rhs) const noexcept{
        return modint(*this)+=rhs;
    }
    constexpr modint &operator++() noexcept{
        return ++a,*this;
    }
    constexpr modint operator++(int) noexcept{
        modint t=*this; return ++a,t;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept{
        if (a<rhs.a) a+=Modulus;
        a-=rhs.a;
        return *this;
    }
    constexpr modint operator-(const modint &rhs) const noexcept{
        return modint(*this)-=rhs;
    }
    constexpr modint &operator--() noexcept{
        return --a,*this;
    }
    constexpr modint operator--(int) noexcept{
        modint t=*this; return --a,t;
    }
    constexpr modint &operator*=(const modint &rhs) noexcept{
        a=a*rhs.a%Modulus;
        return *this;
    }
    constexpr modint operator*(const modint &rhs) const noexcept{
        return modint(*this)*=rhs;
    }
    constexpr modint &operator/=(modint rhs) noexcept{
        u64 exp=Modulus-2;
        while(exp){
            if (exp&1) *this*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return *this;
    }
    constexpr modint operator/(const modint &rhs) const noexcept{
        return modint(*this)/=rhs;
    }
    constexpr modint operator-() const noexcept{
        return modint(Modulus-a);
    }
    constexpr bool operator==(const modint &rhs) const noexcept{
        return a==rhs.a;
    }
    constexpr bool operator!=(const modint &rhs) const noexcept{
        return a!=rhs.a;
    }
    constexpr bool operator!() const noexcept{return !a;}
    friend constexpr modint pow(modint rhs,long long exp) noexcept{
        modint res{1};
        while(exp){
            if (exp&1) res*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return res;
    }
    template<class T> friend constexpr modint operator+(T x,modint y) noexcept{
        return modint(x)+y;
    }
    template<class T> friend constexpr modint operator-(T x,modint y) noexcept{
        return modint(x)-y;
    }
    template<class T> friend constexpr modint operator*(T x,modint y) noexcept{
        return modint(x)*y;
    }
    template<class T> friend constexpr modint operator/(T x,modint y) noexcept{
        return modint(x)/y;
    }
    friend ostream &operator<<(ostream &s,const modint &rhs) noexcept{
        return s << rhs.a;
    }
    friend istream &operator>>(istream &s,modint &rhs) noexcept{
        u64 a; rhs=modint{(s >> a,a)}; return s;
    }
};

using mint=modint<MOD>;

struct LowestCommonAncestor{
    int n,h;
    vector<vector<int>> G,par;
    vector<int> dep,sub;
    LowestCommonAncestor(int n):n(n),G(n),dep(n),sub(n,1){
        h=1;
        while((1<<h)<=n) ++h;
        par.assign(h,vector<int>(n,-1));
    }
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    int dfs(int v,int p,int d){
        par[0][v]=p;
        dep[v]=d;
        for (int u:G[v]){
            if (u!=p) sub[v]+=dfs(u,v,d+1);
        }
        return sub[v];
    }
    void build(int r=0){
        dfs(r,-1,0);
        for (int k=0;k<h-1;++k) for (int v=0;v<n;++v){
            if (par[k][v]>=0) par[k+1][v]=par[k][par[k][v]];
        }
    }
    int lca(int u,int v){
        if (dep[u]>dep[v]) swap(u,v);
        for (int k=0;k<h;++k){
            if ((dep[v]-dep[u])&1<<k) v=par[k][v];
        }
        if (u==v) return u;
        for (int k=h-1;k>=0;--k){
            if (par[k][u]!=par[k][v]) u=par[k][u],v=par[k][v];
        }
        return par[0][u];
    }
    int distance(int u,int v){
        return dep[u]+dep[v]-dep[lca(u,v)]*2;
    }
};

class EularTourForEdge{
    private:
    vector<int> ds,us,dep,btm;
    void dfs(int v,int p,int d){
        dep[v]=d;
        for (int u:G[v]){
            if (u==p) continue;
            ds[u]=btm.size();
            btm.emplace_back(u);
            dfs(u,v,d+1);
            us[u]=btm.size();
            btm.emplace_back(u);
            nxt[v].emplace_back(us[u],u);
        }
    }
    public:
    vector<vector<int>> G;
    vector<vector<pair<int,int>>> nxt;
    EularTourForEdge(int n):
        ds(n),us(n),dep(n),G(n),nxt(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void build(int r=0){
        btm.clear();
        ds[r]=btm.size(); btm.emplace_back(r);
        dfs(r,-1,0);
        us[r]=btm.size(); btm.emplace_back(r);
    }
    int child(int u,int v){
        return dep[u]<dep[v]?v:u;
    }
    int bottom(int e){
        return btm[e];
    }
    int upside(int v){return us[v];}
    template<typename T,typename F>
    T query(int v,F f){
        return f(0,us[v]);
    }
    //u or v must be lca(u,v)
    template<typename T,typename F>
    T query(int u,int v,F f){
        if (dep[u]<dep[v]) swap(u,v);
        return query<T>(u,f)-query<T>(v,f);
    }
    //v is the child of the edge
    template<typename T,typename G>
    void update(int v,T x,G g){
        g(ds[v],x);
        g(us[v],-x);
    }
};

template<typename T>
struct BinaryIndexedTree{
    vector<T> dat;
    BinaryIndexedTree(int n):dat(n+1,0){}
    void add(int i,T x){
        if (i==0) return;
        for (;i<=dat.size();i+=(i&-i)) dat[i]+=x;
    }
    T sum(int i){
        T res=0;
        for (;i>0;i-=(i&-i)) res+=dat[i];
        return res;
    }
    T query(int l,int r){ //[l,r)
        return sum(r-1)-sum(l-1);
    }
    int lower_bound(T x){
        if (x<=0) return 0;
        int lb=0,r=1;
        while(r<dat.size()) r<<=1;
        for (;r>0;r>>=1){
            if (lb+r<dat.size()&&dat[lb+r]<x){
                x-=dat[lb+r]; lb+=r;
            }
        }
        return lb+1;
    }
    void add0(int i,T x){add(i+1,x);}
    T sum0(int i){return sum(i+1);}
    T query0(int l,int r){return sum(r)-sum(l);}
};

const int heavy=500;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    LowestCommonAncestor LCA(n);
    EularTourForEdge ET(n);
    vector<int> deg(n,0),H;
    for (int i=0;i<n-1;++i){
        int u,v; cin >> u >> v;
        ++deg[--u]; ++deg[--v];
        LCA.add_edge(u,v);
        ET.add_edge(u,v);
    }
    for (int i=0;i<n;++i){
        if (deg[i]>heavy){
            H.emplace_back(i);
        }
    }
    LCA.build(); ET.build();
    BinaryIndexedTree<mint> BIT(2*n);
    auto f=[&](int l,int r){return BIT.query0(l,r);};
    auto g=[&](int k,mint x){BIT.add0(k,x);};
    vector<mint> sum(n,0);
    mint whole=0,inv=(mint)1/n;
    for (;q--;){
        int t,v; cin >> t >> v; --v;
        if (t==1){
            mint d; cin >> d;
            sum[v]+=d;
            if (deg[v]<=heavy){
                for (int u:LCA.G[v]){
                    if (u==LCA.par[0][v]) continue;
                    mint add=d*(n-LCA.sub[u]);
                    ET.update(u,add,g);
                }
            }
            if (v){
                whole+=d*LCA.sub[v];
                mint dis=-d*LCA.sub[v];
                ET.update(v,dis,g);
            }
        } else {
            int id=ET.upside(v);
            mint ans=ET.query<mint>(v,f)+whole+sum[v]*n;
            for (int u:H){
                if (u==v||LCA.lca(u,v)!=u) continue;
                int w=(*lower_bound(ET.nxt[u].begin(),ET.nxt[u].end(),make_pair(id,-1))).second;
                ans+=sum[u]*(n-LCA.sub[w]);
            }
            cout << ans*inv << '\n';
        }
    }
}