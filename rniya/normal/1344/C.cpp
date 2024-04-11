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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<int> A(m),B(m);;
    for (int i=0;i<m;++i) cin >> A[i] >> B[i],--A[i],--B[i];
    CycleDetection CD(n);
    vector<int> indeg(n,0);
    vector<vector<int>> G1(n),G2(n);
    for (int i=0;i<m;++i){
        ++indeg[B[i]];
        CD.add_edge(A[i],B[i]);
        G1[A[i]].emplace_back(B[i]);
        G2[B[i]].emplace_back(A[i]);
    }
    int cycle;
    CD.build(cycle);
    if (cycle){cout << -1 << '\n'; return 0;}
    vector<int> seen1(n,0),seen2(n,0),Min1(n,INF),Min2(n,INF);
    auto dfs1=[&](auto self,int v)->void{
        seen1[v]=1;
        Min1[v]=v;
        for (int u:G1[v]){
            if (!seen1[u]) self(self,u);
            chmin(Min1[v],Min1[u]);
        }
    };
    auto dfs2=[&](auto self,int v)->void{
        seen2[v]=1;
        Min2[v]=v;
        for (int u:G2[v]){
            if (!seen2[u]) self(self,u);
            chmin(Min2[v],Min2[u]);
        }
    };
    vector<char> res(n,'E');
    for (int i=0;i<n;++i) if (!seen1[i]){
        dfs1(dfs1,i);
    }
    for (int i=0;i<n;++i) if (!seen2[i]){
        dfs2(dfs2,i);
    }
    int ans=0;
    for (int i=0;i<n;++i){
        if (Min1[i]==i&&Min2[i]==i) res[i]='A';
        ans+=(res[i]=='A');
    }
    cout << ans << '\n';
    for (int i=0;i<n;++i) cout << res[i];
    cout << '\n';
}