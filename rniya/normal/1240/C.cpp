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
    os << '(' << p.first << ',' << p.second << ')';
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
    int n,k; cin >> n >> k;
    vector<vector<pair<int,int>>> G(n);
    for (int i=0;i<n-1;++i){
        int u,v,w; cin >> u >> v >> w; --u,--v;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }

    vector<vector<ll>> dp(n,vector<ll>(2,-IINF));
    auto dfs=[&](auto self,int v,int p,int w)->void{
        ll sum=0;
        vector<ll> diff;
        for (auto e:G[v]){
            int u=e.first;
            if (u==p) continue;
            self(self,u,v,e.second);
            sum+=dp[u][0];
            ll delta=dp[u][1]-dp[u][0];
            if (delta>0) diff.emplace_back(delta);
        }
        sort(ALL(diff),[](ll a,ll b){return a>b;});
        int ok=0;
        if (k==1){
            ok|=1;
            chmax(dp[v][1],sum+w);
        }
        for (int i=0;i<diff.size();++i){
            sum+=diff[i];
            if (i==k-2){
                ok|=1;
                chmax(dp[v][1],sum+w);
            } else if (i==k-1){
                ok|=2;
                chmax(dp[v][0],sum);
            }
        }
        if (!(ok&1)) chmax(dp[v][1],sum+w);
        if (!(ok&2)) chmax(dp[v][0],sum);
    };

    dfs(dfs,0,-1,0);
    cout << dp[0][0] << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q; cin >> q;
    for (;q--;){
        solve();
    }
}