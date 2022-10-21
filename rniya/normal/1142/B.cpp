#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1000000007;
// const long long MOD=998244353;
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

template<typename T>
struct SparseTable{
    typedef function<T(T,T)> F;
    vector<vector<T>> dat;
    vector<int> lookup;
    const F f;
    SparseTable(F f):f(f){}
    void build(const vector<T> &v){
        int n=v.size(),h=1;
        while((1<<h)<=n) ++h;
        dat.assign(h,vector<T>(n));
        lookup.assign(n+1,0);
        for (int i=2;i<=n;++i) lookup[i]=lookup[i>>1]+1;
        for (int j=0;j<n;++j) dat[0][j]=v[j];
        for (int i=1,mask=1;i<h;++i,mask<<=1){
            for (int j=0;j<n;++j){
                dat[i][j]=f(dat[i-1][j],dat[i-1][min(j+mask,n-1)]);
            }
        }
    }
    T query(int a,int b){
        int d=lookup[b-a];
        return f(dat[d][a],dat[d][b-(1<<d)]);
    }
};

const int MAX_LOG=20;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,q; cin >> n >> m >> q;
    vector<int> p(n),a(m);
    for (int i=0;i<n;++i) cin >> p[i],--p[i];
    for (int i=0;i<m;++i) cin >> a[i],--a[i];

    vector<int> idx(n);
    for (int i=0;i<n;++i) idx[p[i]]=i;
    vector<int> nxt(n,m),rs;
    vector<vector<int>> G(m);
    for (int i=m-1;i>=0;--i){
        int P=p[(idx[a[i]]+1)%n];
        if (nxt[P]<m) G[nxt[P]].emplace_back(i);
        else rs.emplace_back(i);
        nxt[a[i]]=i;
    }

    vector<vector<int>> par(MAX_LOG,vector<int>(m,-1));
    auto dfs=[&](auto self,int v,int p)->void{
        par[0][v]=p;
        for (int u:G[v]) self(self,u,v);
    };
    for (int r:rs) dfs(dfs,r,-1);
    for (int i=0;i<MAX_LOG-1;++i){
        for (int j=0;j<m;++j){
            if (~par[i][j]){
                par[i+1][j]=par[i][par[i][j]];
            }
        }
    }

    vector<int> dp(m,m);
    for (int i=0;i<m;++i){
        int cur=i;
        for (int j=0;j<MAX_LOG&&~cur;++j){
            if ((n-1)&1<<j){
                cur=par[j][cur];
            }
        }
        if (~cur) dp[i]=cur;
    }
    SparseTable<int> ST([](int a,int b){return min(a,b);});
    ST.build(dp);

    string ans="";
    for (;q--;){
        int l,r; cin >> l >> r;
        int Min=ST.query(--l,r);
        ans+=(Min<r?'1':'0');
    }

    cout << ans << '\n';
}