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
    cout << '(' << p.first << ',' << p.second << ')';
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

void solve(){
    int n,m; cin >> n >> m;
    vector<ll> b(n),w(n); cin >> b >> w;
    for (int i=0;i<n;++i) w[i]-=b[i];
    vector<vector<int>> G(n);
    for (int i=0;i<n-1;++i){
        int x,y; cin >> x >> y; --x,--y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    auto f=[](pair<int,ll> a,pair<int,ll> b)->pair<int,ll>{return {a.first+b.first,a.second+b.second};};
    vector<int> sub(n);
    vector<vector<pair<int,ll>>> dp(n,vector<pair<int,ll>>(n+1,{0,-IINF}));
    auto dfs=[&](auto self,int v,int p)->void{
        sub[v]=1;
        dp[v][0]={0,w[v]};
        for (int u:G[v]){
            if (u==p) continue;
            self(self,u,v);
            vector<pair<int,ll>> merge(sub[v]+sub[u],{0,-IINF});
            for (int i=0;i<sub[v];++i){
                for (int j=0;j<sub[u];++j){
                    chmax(merge[i+j],f(dp[v][i],dp[u][j]));
                    chmax(merge[i+j+1],make_pair(dp[v][i].first+dp[u][j].first+(dp[u][j].second>0),dp[v][i].second));
                }
            }
            sub[v]+=sub[u];
            for (int i=0;i<min(m+1,sub[v]);++i) dp[v][i]=merge[i];
        }
    };
    dfs(dfs,0,-1);
    int ans=dp[0][m-1].first+(dp[0][m-1].second>0);
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}