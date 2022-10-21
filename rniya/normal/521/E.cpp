#include <bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
// const long long MOD=998244353;
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

struct edge{
    int to,id;
    edge(int to,int id):to(to),id(id){}
};

struct LowLink{
    int n,time;
    vector<int> ord,low;
    vector<vector<edge>> G;
    vector<int> articulation;
    vector<pair<int,int>> bridge;
    LowLink(int n):n(n),time(0),ord(n,-1),low(n),G(n){}
    void add_edge(int u,int v,int id){
        G[u].emplace_back(v,id);
        G[v].emplace_back(u,id);
    }
    bool is_bridge(int u,int v){
        if (ord[u]>ord[v]) swap(u,v);
        return ord[u]<low[v];
    }
    void dfs(int v,int p){
        ord[v]=low[v]=time++;
        bool is_articulation=false;
        int cnt=0;
        for (auto e:G[v]){
            int u=e.to;
            if (u==p) continue;
            if (~ord[u]){
                low[v]=min(low[v],ord[u]);
                continue;
            }
            ++cnt;
            dfs(u,v);
            low[v]=min(low[v],low[u]);
            is_articulation|=(~p&&ord[v]<=low[u]);
            if (is_bridge(v,u)) bridge.emplace_back(v,u);
        }
        is_articulation|=(p<0&&cnt>1);
        if (is_articulation) articulation.emplace_back(v);
    }
    void build(){
        for (int v=0;v<n;++v){
            if (ord[v]<0) dfs(v,-1);
        }
    }
};

const int MAX_N=200005;
int u[MAX_N],v[MAX_N];
set<pair<int,int>> used;
bool seen[MAX_N],visited[MAX_N],check[MAX_N],articulation[MAX_N];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;

    LowLink L1(n);
    for (int i=0;i<m;++i){
        cin >> u[i] >> v[i];
        if (u[i]>v[i]) swap(u[i],v[i]);
        L1.add_edge(--u[i],--v[i],i);
    }
    L1.build();

    LowLink L2(n);
    for (int i=0;i<m;++i){
        if (L1.is_bridge(u[i],v[i])) continue;
        L2.add_edge(u[i],v[i],i);
    }
    L2.build();

    for (int v:L2.articulation) articulation[v]=true;
    auto &G=L2.G;
    auto dfs_cycle=[&](auto self,int v,int p,int r,vector<int> &cycle,bool &c)->void{
        cycle.emplace_back(v); seen[v]=true;
        for (auto e:G[v]){
            int u=e.to;
            if (u==p) continue;
            if (u!=r&&seen[u]) continue;
            if (u==r){
                c=true;
                return;
            }
            self(self,u,v,r,cycle,c);
            if (c) return;
        }
        cycle.pop_back();
    };

    auto dfs_path=[&](auto self,int v,int p,int r,vector<int> &path,bool &reached)->void{
        path.emplace_back(v); visited[v]=true;
        if (v!=r&&check[v]){
            reached=true;
            return;
        }
        for (auto e:G[v]){
            int u=e.to;
            if (u==p) continue;
            if (visited[u]) continue;
            if (used.count(minmax(u,v))) continue;
            self(self,u,v,r,path,reached);
            if (reached) return;
        }
        path.pop_back();
    };

    for (int s=0;s<n;++s){
        if (articulation[s]) continue;
        if (G[s].size()<3) continue;

        vector<int> cycle;
        bool c=false;
        dfs_cycle(dfs_cycle,s,-1,s,cycle,c);
        for (int v:cycle) check[v]=true;
        cycle.emplace_back(cycle.front());
        for (int i=0;i+1<cycle.size();++i) used.emplace(minmax(cycle[i],cycle[i+1]));

        vector<int> path;
        bool reached=false;
        dfs_path(dfs_path,s,-1,s,path,reached);
        int t=path.back();
        vector<vector<int>> ans(3);
        ans[0]=path;
        for (int i=0;i<cycle.size();++i){
            ans[1].emplace_back(cycle[i]);
            if (cycle[i]==t) break;
        }
        for (int i=cycle.size()-1;i>=0;--i){
            ans[2].emplace_back(cycle[i]);
            if (cycle[i]==t) break;
        }
        cout << "YES" << '\n';
        for (int i=0;i<3;++i){
            cout << ans[i].size();
            for (int x:ans[i]) cout << ' ' << x+1;
            cout << '\n';
        }
        return 0;
    }

    cout << "NO" << '\n';
}