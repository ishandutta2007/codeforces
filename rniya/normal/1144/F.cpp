#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?'\n':' ');
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

struct BipartiteGraph{
    int n,num;
    vector<int> par,rank;
    BipartiteGraph(int n):n(n),num(2*n),par(2*n),rank(2*n,1){
        iota(par.begin(),par.end(),0);
    }
    int root(int x){
        if (par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    bool merge(int x, int y){
        x=root(x),y=root(y);
        if (x==y) return false;
        if (rank[x]<rank[y]) swap(x,y);
        par[y]=x;
        rank[x]+=rank[y];
        --num;
        return true;
    }
    bool same(int x, int y){
        return root(x)==root(y);
    }
    int size(int x){
        return rank[root(x)];
    }
    int count(){
        return num;
    }
    void add_edge(int u,int v){
        merge(u,v+n),merge(u+n,v);
    }
    bool build(){
        for (int i=0;i<n;++i){
            if (same(i,i+n)) return false;
        }
        return true;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<pair<int,int>> G;
    BipartiteGraph BG(n);
    for (int i=0;i<m;++i){
        int u,v; cin >> u >> v;
        BG.add_edge(--u,--v);
        G.emplace_back(u,v);
    }
    if (!BG.build()){cout << "NO" << '\n'; return 0;}
    cout << "YES" << '\n';
    vector<int> bi(n);
    for (int i=0;i<n;++i) bi[i]=BG.same(0,i);
    for (int i=0;i<m;++i){
        cout << bi[G[i].first];
    }
    cout << '\n';
}