#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
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

int n;
vector<int> G[MAX_N];
int dp[MAX_N][3],cnt[MAX_N][3];

void dfs(int v,int p){
    cnt[v][2]=(p<=0?0:1); cnt[v][1]=INF; int sum=0;
    for (int u:G[v]){
        if (u==p) continue;
        dfs(u,v);
        if (cnt[v][0]<INF) cnt[v][0]+=dp[u][1];
        if (cnt[v][2]<INF) cnt[v][2]+=min({dp[u][0],dp[u][1],dp[u][2]});
        if (sum<INF) sum+=min(dp[u][1],dp[u][2]);
    }
    if (sum<INF) for (int u:G[v]) if (u!=p){
        cnt[v][1]=min(cnt[v][1],sum-min(dp[u][1],dp[u][2])+dp[u][2]);
    }
    for (int i=0;i<3;++i) dp[v][i]=min(dp[v][i],cnt[v][i]);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n-1;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for (int v=0;v<n;++v)
        for (int i=0;i<3;++i)
            dp[v][i]=INF;
    dfs(0,-1);
    cout << min({dp[0][0],dp[0][1],dp[0][2]}) << '\n';
}