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

const int MAX_N=2e5+10;

int n,m;
vector<int> G[MAX_N];
int color[MAX_N];
vector<vector<int>> ans(2);

void dfs(int v){
    ans[color[v]].emplace_back(v+1);
    for (int u:G[v]){
        if (~color[u]) continue;
        color[u]=color[v]^1;
        dfs(u);
    }
}

void solve(){
    for (int i=0;i<n;++i) color[i]=-1;
    ans[0].clear(); ans[1].clear();
    color[0]=0;
    dfs(0);
    if (ans[0].size()>ans[1].size()) swap(ans[0],ans[1]);
    int s=ans[0].size();
    cout << s << '\n';
    for (int i=0;i<s;++i) cout << ans[0][i] << (i+1==s?'\n':' ');
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n >> m;
        for (int i=0;i<n;++i) G[i].clear();
        for (int i=0;i<m;++i){
            int u,v; cin >> u >> v; --u,--v;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        solve();
    }
}