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

struct UnionFind{
    int num;
    vector<int> par,rank;
    UnionFind(int n):num(n),par(n),rank(n,1){
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
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i=0;i<m;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    int Max=0;
    for (int i=0;i<n;++i){
        if (G[Max].size()<G[i].size()) Max=i;
    }
    UnionFind uf(n);
    for (int u:G[Max]){
        cout << Max+1 << ' ' << u+1 << '\n';
        uf.merge(u,Max);
    }
    for (int v=0;v<n;++v){
        for (int u:G[v]) if (!uf.same(u,v)){
            cout << u+1 << ' ' << v+1 << '\n';
            uf.merge(u,v);
        }
    }
}