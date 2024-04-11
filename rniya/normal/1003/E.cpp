#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};
#define LOCAL

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
ostream &operator<< (ostream &os,const set<T> &s){
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

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}

template<typename T>
struct TreeDiameter{
    vector<T> dp;
    vector<vector<pair<int,T>>> G;
    TreeDiameter(int n):dp(n),G(n){}
    void add_edge(int u,int v,T c){
        G[u].emplace_back(v,c);
        G[v].emplace_back(u,c);
    }
    void dfs(int v,int p,int &s){
        if (p<0) dp[v]=T(0);
        if (dp[s]<dp[v]) s=v;
        for (auto e:G[v]){
            int u=e.first;
            if (u==p) continue;
            dp[u]=dp[v]+e.second;
            dfs(u,v,s);
        }
    }
    pair<int,int> endPoints(){
        int s=0;
        dfs(s,-1,s);
        int t=s;
        dfs(t,-1,t);
        return make_pair(s,t);
    }
    T build(){
        int t=endPoints().second;
        return dp[t];
    }
    vector<T> distance(int v){
        dfs(v,-1,v);
        return dp;
    }
    vector<T> farthest(){
        int t=endPoints().second;
        auto ds=dp;
        auto dt=distance(t);
        for (int i=0;i<ds.size();++i) ds[i]=max(ds[i],dt[i]);
        return ds;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,d,k; cin >> n >> d >> k;
    if (n==1&&d!=0){cout << "NO" << '\n'; return 0;}
    if (n==2&&d!=1){cout << "NO" << '\n'; return 0;}
    if (n>=3&&(d<2||n-1<d||k<2)){cout << "NO" << '\n'; return 0;}
    if (d>n-1){cout << "NO" << '\n'; return 0;}
    vector<pair<int,int>> ans;
    TreeDiameter<int> TD(n);
    vector<int> deg(n,0); int p=0;
    for (int i=1;i<n;++i){
        ans.emplace_back(p,i);
        TD.add_edge(p,i,1);
        ++deg[p]; ++deg[i];
        if (deg[p]==k) ++p;
    }
    int Min=TD.build(),now=Min;
    if (d<Min){cout << "NO" << '\n'; return 0;}
    pair<int,int> f=TD.endPoints();
    vector<int> dist1=TD.distance(f.first),dist2=TD.distance(f.second);
    vector<pair<int,int>> ans1;
    int par=f.second;
    while(now<d){
        auto p=ans.back(); ans.pop_back();
        int v=p.second;
        if (dist1[v]+dist2[v]==Min){
            ans1.emplace_back(p);
            continue;
        }
        ans1.emplace_back(par,v);
        par=v; ++now;
    }
    cout << "YES" << '\n';
    for (auto p:ans) cout << p.first+1 << ' ' << p.second+1 << '\n';
    for (auto p:ans1) cout << p.first+1 << ' ' << p.second+1 << '\n';
}