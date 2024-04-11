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

struct UnionFind{
    int num;
    vector<int> par,rank;
    UnionFind(int n):num(n),par(n),rank(n,1){
        iota(par.begin(),par.end(),0);
    }
    int root(int x){
        return (par[x]==x?x:par[x]=root(par[x]));
    }
    bool merge(int x, int y){
        x=root(x); y=root(y);
        if (x==y) return false;
        if (rank[x]<rank[y]) swap(x,y);
        par[y]=x;
        rank[x]+=rank[y];
        --num;
        return true;
    }
    bool same(int x, int y){return root(x)==root(y);}
    int size(int x){return rank[root(x)];}
    int count(){return num;}
    int operator[](int x){return root(x);}
};

template<bool directed>
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
        seen[v]=1; hist.emplace(v);
        for (int u:G[v]){
            if (!directed&&u==p) continue;
            if (finished[u]) continue;
            if (seen[u]&&!finished[u]){pos=u; return;}
            dfs(u,v);
            if (~pos) return;
        }
        finished[v]=1; hist.pop();
    }
    vector<int> build(){
        for (int v=0;v<G.size();++v){
            if (!seen[v]) dfs(v,-1);
            if (~pos) break;
        }
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

bool check(int n,vector<int> ans,vector<int> p,vector<int> x,vector<int> y){
    vector<int> pos(n+1,-1);
    for (int i=0;i<n;++i) pos[ans[i]]=i;
    for (int i=1;i<=n;++i){
        if (pos[i]<0){
            return false;
        }
    }
    for (int i=0;i<n;++i){
        if (pos[i+1]<pos[p[i]]){
            return false;
        }
    }
    for (int i=0;i<x.size();++i){
        if (pos[x[i]]==n-1||ans[pos[x[i]]+1]!=y[i]){
            return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    vector<int> p(n); cin >> p;
    vector<int> x(k),y(k);
    for (int i=0;i<k;++i) cin >> x[i] >> y[i];

    vector<vector<int>> G(n+1);
    for (int i=0;i<n;++i) G[p[i]].emplace_back(i+1);

    int h=1;
    while((1<<h)<=n) ++h;
    vector<vector<int>> par(h,vector<int>(n+1));
    vector<int> dep(n+1);

    auto dfs1=[&](auto self,int v,int p)->void{
        par[0][v]=p;
        if (p<0) dep[v]=0;
        for (int u:G[v]){
            dep[u]=dep[v]+1;
            self(self,u,v);
        }
    };
    dfs1(dfs1,0,-1);

    for (int i=0;i<h-1;++i){
        for (int j=0;j<=n;++j){
            if (~par[i][j]){
                par[i+1][j]=par[i][par[i][j]];
            }
        }
    }

    auto lca=[&](int u,int v){
        if (dep[u]>dep[v]) swap(u,v);
        for (int k=0;k<h;++k){
            if ((dep[v]-dep[u])&1<<k){
                v=par[k][v];
            }
        }
        if (u==v) return u;
        for (int k=h-1;k>=0;--k){
            if (par[k][u]!=par[k][v]){
                u=par[k][u]; v=par[k][v];
            }
        }
        return par[0][u];
    };

    UnionFind UF(n+1);
    vector<int> pre(n+1,-1),suf(n+1,-1);
    for (int i=0;i<k;++i){
        int p=lca(x[i],y[i]);
        if (p==x[i]){
            if (par[0][y[i]]!=x[i]){
                cout << 0 << '\n';
                return 0;
            }
        } else if (p==y[i]){
            cout << 0 << '\n';
            return 0;
        }
        if (~pre[y[i]]&&pre[y[i]]!=x[i]){
            cout << 0 << '\n';
            return 0;
        }
        if (~suf[x[i]]&&suf[x[i]]!=y[i]){
            cout << 0 << '\n';
            return 0;
        }
        if (!UF.merge(x[i],y[i])){
            cout << 0 << '\n';
            return 0;
        }
        pre[y[i]]=x[i]; suf[x[i]]=y[i];
    }

    CycleDetection<true> CD(n+1);
    TopologicalSort TS(n+1);
    for (int i=0;i<n;++i){
        CD.add_edge(p[i],i+1);
        TS.add_edge(p[i],i+1);
    }
    vector<vector<int>> seq(n+1);
    vector<int> seen(n+1,0);
    for (int i=1;i<=n;++i){
        if (~pre[i]) continue;
        int v=i;
        while (1){
            seq[i].emplace_back(v);
            seen[v]=1;
            if (~pre[v]&&par[0][v]!=pre[v]&&par[0][v]!=i&&!UF.same(v,par[0][v])){
                CD.add_edge(par[0][v],i);
                TS.add_edge(par[0][v],i);
            }
            if (~pre[v]){
                CD.add_edge(pre[v],v);
                TS.add_edge(pre[v],v);
            }
            if (suf[v]<0) break;
            v=suf[v];
            if (seen[v]){
                cout << 0 << '\n';
                return 0;
            }
        }
    }
    if (!CD.build().empty()){
        cout << 0 << '\n';
        return 0;
    }
    vector<int> res=TS.build(),ans;
    for (int i=0;i<=n;++i){
        int v=res[i];
        if (!v) continue;
        if (~pre[v]) continue;
        for (int u:seq[v]) ans.emplace_back(u);
    }

    cout << ans << '\n';
    // debug(check(n,ans,p,x,y));
}