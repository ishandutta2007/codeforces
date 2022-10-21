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

struct CycleDetection{
    vector<vector<int>> G;
    vector<int> seen,finished;
    stack<int> hist;
    int pos;
    CycleDetection(int n):G(n),seen(n,0),finished(n,0),pos(-1){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
    }
    void dfs(int v,int p){
        seen[v]=1; hist.push(v);
        for (int u:G[v]){
            if (u==p) continue;
            if (finished[u]) continue;
            if (seen[u]&&!finished[u]){pos=u; return;}
            dfs(u,v);
            if (pos!=-1) return;
        }
        finished[v]=1; hist.pop();
    }
    vector<int> build(int &cycle){
        for (int i=0;i<G.size();++i){
            if (pos!=-1) continue;
            if (!finished[i]) dfs(i,-1);
        }
        cycle=(pos!=-1);
        vector<int> res;
        while(!hist.empty()){
            int t=hist.top(); hist.pop();
            res.emplace_back(t);
            if (t==pos) break;
        }
        return res;
    }
};

const int MAX_N=1e5+10;

int n,m,k;
vector<int> G[MAX_N];
int seen[MAX_N],color[MAX_N];

void dfs(int v){
    seen[v]=1;
    for (int u:G[v]){
        if (seen[u]) continue;
        color[u]=color[v]^1;
        dfs(u);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    CycleDetection C(k);
    for (int i=0;i<m;++i){
        int u,v; cin >> u >> v; --u,--v;
        if (u>=k||v>=k) continue;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        C.add_edge(u,v);
        C.add_edge(v,u);
    }
    int flag;
    vector<int> ans2=C.build(flag);
    if (flag){
        cout << 2 << '\n';
        int s=ans2.size();
        cout << s << '\n';
        for (int i=0;i<s;++i) cout << ans2[i]+1 << (i+1==s?'\n':' ');
        return 0;
    }
    cout << 1 << '\n';
    for (int i=0;i<k;++i) if (!seen[i]) dfs(i);
    vector<vector<int>> bip(2);
    for (int i=0;i<k;++i) bip[color[i]].emplace_back(i);
    if (bip[1].size()>bip[0].size()) swap(bip[0],bip[1]);
    for (int i=0;i<(k+1)/2;++i) cout << bip[0][i]+1 << (i+1==(k+1)/2?'\n':' ');
}