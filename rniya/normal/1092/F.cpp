#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
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
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}

const int MAX_N=2e5+10;

int n; ll ans=0;
ll a[MAX_N];
vector<int> G[MAX_N];
ll sub_a[MAX_N],sub_sum[MAX_N];

void dfs1(int v,int p){
    sub_a[v]=a[v];
    for (int u:G[v]){
        if (u==p) continue;
        dfs1(u,v);
        sub_a[v]+=sub_a[u];
        sub_sum[v]+=sub_sum[u]+sub_a[u];
    }
}

void dfs2(int v,int p,ll D){
    ans=max(ans,sub_sum[v]+D);
    for (int u:G[v]){
        if (u==p) continue;
        D+=sub_sum[u]+sub_a[u];
    }
    for (int u:G[v]){
        if (u==p) continue;
        dfs2(u,v,D-sub_sum[u]-sub_a[u]+sub_a[0]-sub_a[u]);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<n-1;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs1(0,-1);
    dfs2(0,-1,0);
    cout << ans << '\n';
}