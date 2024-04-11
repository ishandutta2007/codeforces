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

struct CycleDetection{
    vector<vector<int>> G;
    vector<int> seen,finished;
    stack<int> hist;
    int pos;
    CycleDetection(int n):G(n),seen(n,0),finished(n,0),pos(-1){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
    }
    void dfs(int v){
        seen[v]=1; hist.push(v);
        for (int u:G[v]){
            if (finished[u]) continue;
            if (seen[u]&&!finished[u]){pos=u; return;}
            dfs(u);
            if (pos!=-1) return;
        }
        finished[v]=1; hist.pop();
    }
    vector<int> build(int &cycle){
        for (int v=0;v<G.size();++v){
            if (!seen[v]) dfs(v);
            if (~pos) break;
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

struct TopologicalSort{
    vector<vector<int>> G;
    vector<int> seen,order;
    TopologicalSort(int n):G(n),seen(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
    }
    void dfs(int v){
        seen[v]=1;
        for (int u:G[v]) if (!seen[u]) dfs(u);
        order.emplace_back(v);
    }
    vector<int> build(){
        for (int i=0;i<G.size();++i) if (!seen[i]) dfs(i);
        reverse(order.begin(),order.end());
        return order;
    }
    int operator[](int i){return order[i];}
};

void solve(){
    int n,m; cin >> n >> m;
    CycleDetection CD(n);
    TopologicalSort TS(n);
    vector<pair<int,int>> es,ans;
    for (int i=0;i<m;++i){
        int t,u,v; cin >> t >> u >> v;
        if (!t) es.emplace_back(--u,--v);
        else {
            CD.add_edge(--u,--v);
            TS.add_edge(u,v);
            ans.emplace_back(u,v);
        }
    }
    int check;
    CD.build(check);
    if (check){cout << "NO" << '\n'; return;}
    vector<int> v=TS.build();
    vector<int> pos(n);
    for (int i=0;i<n;++i) pos[TS[i]]=i;
    for (auto p:es){
        if (pos[p.first]>pos[p.second]) swap(p.first,p.second);
        ans.emplace_back(p);
    }
    cout << "YES" << '\n';
    for (auto p:ans) cout << p.first+1 << ' ' << p.second+1 << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}