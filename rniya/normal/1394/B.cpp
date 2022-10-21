#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,K; cin >> n >> m >> K;
    struct edge{
        int u,v,w;
        edge(int u,int v,int w):u(u),v(v),w(w){}
        const bool operator<(const edge &rhs){
            return w<rhs.w;
        }
    };
    vector<edge> es;
    for (int i=0;i<m;++i){
        int u,v,w; cin >> u >> v >> w;
        es.emplace_back(--u,--v,w);
    }
    sort(ALL(es));
    vector<vector<int>> G(n);
    for (int i=0;i<m;++i) G[es[i].u].emplace_back(es[i].v);
    vector<ll> base(n);
    random_device seed_gen;
    mt19937_64 engine(seed_gen());
    ll whole=0;
    for (int i=0;i<n;++i){
        base[i]=engine();
        whole^=base[i];
    }
    vector<vector<ll>> hash(K+1,vector<ll>(K+1,0));
    for (int i=0;i<n;++i){
        int s=G[i].size();
        for (int j=0;j<s;++j){
            hash[s][j+1]^=base[G[i][j]];
        }
    }
    int ans=0;
    auto dfs=[&](auto self,ll now,int s)->void{
        if (s==K){
            ans+=(now==whole);
            return;
        }
        for (int i=0;i<=s;++i){
            now^=hash[s+1][i+1];
            self(self,now,s+1);
            now^=hash[s+1][i+1];
        }
    };
    dfs(dfs,0,0);
    cout << ans << '\n';
}