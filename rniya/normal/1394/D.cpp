#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e13;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> t(n),h(n); cin >> t >> h;
    vector<vector<int>> G(n);
    for (int i=0;i<n-1;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<vector<ll>> dp(n,vector<ll>(2,IINF));
    auto dfs=[&](auto self,int v,int p)->void{
        ll sum=0;
        vector<ll> diff;
        for (int u:G[v]){
            if (u==p) continue;
            self(self,u,v);
            sum+=dp[u][0];
            diff.emplace_back(dp[u][1]-dp[u][0]);
        }
        int s=diff.size();
        sort(diff.begin(),diff.end());
        vector<int> add={(~p&&h[p]<=h[v]),(~p&&h[p]>=h[v])};
        for (int j=0;j<2;++j){
            if (~p&&!add[j]) continue;
            ll nxt=sum;
            for (int i=0;i<=s;++i){
                if (!j) dp[v][j]=min(dp[v][j],nxt+(ll)t[v]*max(s-i,i+add[j]));
                else dp[v][j]=min(dp[v][j],nxt+(ll)t[v]*max(s-i+add[j],i));
                if (i==s) continue;
                nxt+=diff[i];
            }
        }
    };

    dfs(dfs,0,-1);
    cout << min(dp[0][0],dp[0][1]) << '\n';
}