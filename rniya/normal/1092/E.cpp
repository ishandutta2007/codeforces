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

const int MAX_N=1010;

int n,m;
vector<int> G[MAX_N];
int seen[MAX_N];

void dfs(int v,vector<int> &dep){
    for (int u:G[v]){
        if (~dep[u]) continue;
        dep[u]=dep[v]+1;
        dfs(u,dep);
    }
}

pair<int,int> diameter(int v){
    vector<int> dep0(n,-1),dep1(n,-1),dep2(n,-1);
    dep0[v]=0; dfs(v,dep0);
    int u1=max_element(dep0.begin(),dep0.end())-dep0.begin();
    dep1[u1]=0; dfs(u1,dep1);
    int u2=max_element(dep1.begin(),dep1.end())-dep1.begin();
    dep2[u2]=0; dfs(u2,dep2);
    int M=INF,c;
    for (int i=0;i<n;++i){
        if (dep0[i]<0) continue;
        seen[i]=1;
        if (max(dep1[i],dep2[i])<M) M=max(dep1[i],dep2[i]),c=i;
    }
    return {dep1[u2],c};
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0;i<m;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<pair<int,int>> vs;
    for (int i=0;i<n;++i) if (!seen[i]){
        vs.emplace_back(diameter(i));
    }
    sort(vs.begin(),vs.end());
    reverse(vs.begin(),vs.end());
    vector<pair<int,int>> ans;
    for (int i=1;i<vs.size();++i){
        int u=vs[0].second,v=vs[i].second;
        ans.emplace_back(u+1,v+1);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    cout << diameter(0).first << '\n';
    for (auto e:ans) cout << e.first << ' ' << e.second << '\n';
}