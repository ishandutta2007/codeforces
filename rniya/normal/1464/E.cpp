#include <bits/stdc++.h>
using namespace std;
// const long long MOD=1000000007;
const long long MOD=998244353;
#define LOCAL
#pragma region Macros
typedef long long ll;
typedef __int128_t i128;
typedef unsigned int uint;
typedef unsigned long long ull;
#define ALL(x) (x).begin(),(x).end()
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
template<typename T,typename U,typename V>
ostream&operator<<(ostream &os,const tuple<T,U,V> &t){
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';
    return os;
}
template<typename T,typename U,typename V,typename W>
ostream&operator<<(ostream &os,const tuple<T,U,V,W> &t){
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const unordered_map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const multiset<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const unordered_set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const deque<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
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

template<uint32_t mod> class modint{
    using i64=int64_t;
    using u32=uint32_t;
    using u64=uint64_t;
public:
    u32 v;
    constexpr modint(const i64 x=0) noexcept :v(x<0?mod-1-(-(x+1)%mod):x%mod){}
    constexpr u32 &value() noexcept {return v;}
    constexpr const u32 &value() const noexcept {return v;}
    constexpr modint operator+(const modint &rhs) const noexcept {return modint(*this)+=rhs;}
    constexpr modint operator-(const modint &rhs) const noexcept {return modint(*this)-=rhs;}
    constexpr modint operator*(const modint &rhs) const noexcept {return modint(*this)*=rhs;}
    constexpr modint operator/(const modint &rhs) const noexcept {return modint(*this)/=rhs;}
    constexpr modint &operator+=(const modint &rhs) noexcept {
        v+=rhs.v;
        if (v>=mod) v-=mod;
        return *this;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept {
        if (v<rhs.v) v+=mod;
        v-=rhs.v;
        return *this;
    }
    constexpr modint &operator*=(const modint &rhs) noexcept {
        v=(u64)v*rhs.v%mod;
        return *this;
    }
    constexpr modint &operator/=(const modint &rhs) noexcept {
        return *this*=rhs.pow(mod-2);
    }
    constexpr modint pow(u64 exp) const noexcept {
        modint self(*this),res(1);
        while (exp>0){
            if (exp&1) res*=self;
            self*=self; exp>>=1;
        }
        return res;
    }
    constexpr modint &operator++() noexcept {if (++v==mod) v=0; return *this;}
    constexpr modint &operator--() noexcept {if (v==0) v=mod; return --v,*this;}
    constexpr modint operator++(int) noexcept {modint t=*this; return ++*this,t;}
    constexpr modint operator--(int) noexcept {modint t=*this; return --*this,t;}
    constexpr modint operator-() const noexcept {return modint(mod-v);}
    template<class T> friend constexpr modint operator+(T x,modint y) noexcept {return modint(x)+y;}
    template<class T> friend constexpr modint operator-(T x,modint y) noexcept {return modint(x)-y;}
    template<class T> friend constexpr modint operator*(T x,modint y) noexcept {return modint(x)*y;}
    template<class T> friend constexpr modint operator/(T x,modint y) noexcept {return modint(x)/y;}
    constexpr bool operator==(const modint &rhs) const noexcept {return v==rhs.v;}
    constexpr bool operator!=(const modint &rhs) const noexcept {return v!=rhs.v;}
    constexpr bool operator!() const noexcept {return !v;}
    friend istream &operator>>(istream &s,modint &rhs) noexcept {
        i64 v; rhs=modint{(s>>v,v)}; return s;
    }
    friend ostream &operator<<(ostream &s,const modint &rhs) noexcept {
        return s<<rhs.v;
    }
};

struct TopologicalSort{
    vector<vector<int>> G;
    vector<int> seen,order;
    TopologicalSort(int n):G(n),seen(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
    }
    void dfs(int v){
        seen[v]=1;
        for (int u:G[v]){
            if (!seen[u]) dfs(u);
        }
        order.emplace_back(v);
    }
    vector<int> build(){
        for (int i=0;i<G.size();++i){
            if (!seen[i]) dfs(i);
        }
        reverse(order.begin(),order.end());
        return order;
    }
    int operator[](int i){return order[i];}
};

template<typename T>
vector<T> gauss_jordan(const vector<vector<T>> &A,const vector<T> &b){
    int n=A.size();
    vector<vector<T>> B(n,vector<T>(n+1));
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j) B[i][j]=A[i][j];
        B[i][n]=b[i];
    }

    for (int i=0;i<n;++i){
        int pivot=i;
        for (int j=i+1;j<n;++j){
            if (B[j][i]!=0){
                pivot=j;
            }
        }
        swap(B[i],B[pivot]);
        if (B[i][i]==0) return {};
        T inv=T(1)/B[i][i];
        for (int j=i+1;j<=n;++j) B[i][j]*=inv;
        for (int j=0;j<n;++j){
            if (i==j) continue;
            for (int k=i+1;k<=n;++k) B[j][k]-=B[i][k]*B[j][i];
        }
    }
    vector<T> res(n);
    for (int i=0;i<n;++i) res[i]=B[i][n];
    return res;
}

const int MAX_G=512;
using mint=modint<MOD>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    TopologicalSort TS(n);
    for (int i=0;i<m;++i){
        int u,v; cin >> u >> v;
        TS.add_edge(--u,--v);
    }
    TS.build();

    vector<int> grundy(n),cnt(m+1,0),g(MAX_G,0);
    auto &G=TS.G;
    for (int i=n-1;i>=0;--i){
        int v=TS[i];
        for (int u:G[v]) ++cnt[grundy[u]];
        for (int j=0;j<=m;++j){
            if (!cnt[j]){
                grundy[v]=j;
                ++g[j];
                break;
            }
        }
        for (int u:G[v]) --cnt[grundy[u]];
    }

    vector<vector<mint>> A(MAX_G,vector<mint>(MAX_G,0));
    vector<mint> b(MAX_G,0);
    for (int i=0;i<MAX_G;++i){
        for (int j=0;j<MAX_G;++j){
            A[i][j]=mint(g[i^j])/(n+1);
            if (i==j) --A[i][j];
        }
        if (i) b[i]=mint(-1)/(n+1);
    }

    vector<mint> res=gauss_jordan(A,b);
    cout << res[0] << '\n';
}