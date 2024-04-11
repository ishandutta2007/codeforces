#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
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
#pragma endregion

void solve(){
    int n; ll S; cin >> n >> S;
    struct edge{
        int to,id; ll w;
        edge(int to,ll w,int id):to(to),w(w),id(id){}
    };
    vector<vector<edge>> G(n);
    vector<ll> w(n-1);
    vector<int> c(n-1);
    for (int i=0;i<n-1;++i){
        int u,v; cin >> u >> v >> w[i] >> c[i]; --u,--v;
        G[u].emplace_back(v,w[i],i);
        G[v].emplace_back(u,w[i],i);
    }
    vector<int> sub(n,0),cnt(n-1);
    auto dfs=[&](auto self,int v,int p)->void{
        for (auto e:G[v]){
            int u=e.to;
            if (u==p) continue;
            self(self,u,v);
            cnt[e.id]=sub[u];
            sub[v]+=sub[u];
        }
        if (~p&&G[v].size()==1) sub[v]=1;
    };
    dfs(dfs,0,-1);
    ll sum=0;
    vector<priority_queue<pair<ll,int>>> pq(2);
    for (int i=0;i<n-1;++i){
        sum+=w[i]*cnt[i];
        pq[c[i]-1].emplace((w[i]-w[i]/2)*cnt[i],i);
    }
    if (sum<=S){cout << 0 << '\n'; return;}
    vector<vector<ll>> dec(2);
    for (int i=0;i<2;++i){
        dec[i].emplace_back(0);
        while(!pq[i].empty()){
            auto p=pq[i].top(); pq[i].pop();
            dec[i].emplace_back(dec[i].back()+p.first);
            int id=p.second; w[id]/=2;
            if (w[id]==0) continue;
            pq[i].emplace((w[id]-w[id]/2)*cnt[id],id);
        }
    }
    int ans=INF;
    for (int i=0;i<dec[1].size();++i){
        int pos=lower_bound(ALL(dec[0]),sum-S-dec[1][i])-dec[0].begin();
        if (pos==dec[0].size()) continue;
        chmin(ans,i*2+pos);
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}