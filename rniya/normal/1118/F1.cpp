#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
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

const int MAX_N=3e5+10;

int n,ans;
vector<int> G[MAX_N];
int a[MAX_N];
int sum[3],sub[MAX_N][3];

void dfs(int v,int p){
    ++sub[v][a[v]];
    for (int u:G[v]){
        if (u==p) continue;
        dfs(u,v);
        for (int i=0;i<3;++i) sub[v][i]+=sub[u][i];
    }
    if (sub[v][1]&&sub[v][2]) return;
    ans+=((sub[v][1]==sum[1])^(sub[v][2]==sum[2]));
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<n;++i) ++sum[a[i]];
    for (int i=0;i<n-1;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(0,-1);
    cout << ans << '\n';
}