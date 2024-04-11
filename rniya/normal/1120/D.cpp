#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1000000007;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> c(n);
    for (int i=0;i<n;++i) cin >> c[i];
    vector<vector<int>> G(n);
    for (int i=0;i<n-1;++i){
        int a,b; cin >> a >> b; --a,--b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    vector<vector<ll>> dp(n,vector<ll>(2,IINF));
    vector<vector<int>> pre(n,vector<int>(2,0));
    vector<int> ans;
    auto dfs1=[&](auto self,int v,int p)->void{
        int leaf=(~p&&G[v].size()==1?1:0);
        ll sum=0,Min=IINF;
        for (int u:G[v]){
            if (u==p) continue;
            self(self,u,v);
            sum+=dp[u][0];
            Min=min(Min,dp[u][1]-dp[u][0]);
        }
        chmin(dp[v][0],sum+leaf*c[v]);
        chmin(dp[v][0],sum+Min+c[v]);
        if (dp[v][0]==sum+leaf*c[v]) pre[v][0]|=1;
        if (leaf&&dp[v][0]==sum+leaf*c[v]) pre[v][0]|=4;
        if (dp[v][0]==sum+Min+c[v]) pre[v][0]|=6;
        chmin(dp[v][1],sum+Min);
        if (leaf) chmin(dp[v][1],sum);
        if (dp[v][1]==sum+Min) pre[v][1]|=2;
        // debug(v,G[v].size(),dp[v],pre[v],leaf);
    };
    auto dfs2=[&](auto self,int v,int p,int D)->void{
        ll Min=IINF; int min_cnt=0;
        // debug(v,D,pre[v]);
        for (int u:G[v]){
            if (u==p) continue;
            ll diff=dp[u][1]-dp[u][0];
            if (diff<Min){
                Min=diff; min_cnt=1;
            } else if (diff==Min) ++min_cnt;
        }
        int ch=0;
        for (int i=0;i<2;++i){
            if (D&1<<i){
                if (pre[v][i]&1<<2) ans.emplace_back(v);
                ch|=pre[v][i];
            }
        }
        ch&=3;
        if (min_cnt>1) ch|=1;
        for (int u:G[v]){
            if (u==p) continue;
            ll diff=dp[u][1]-dp[u][0];
            self(self,u,v,(Min<diff?1:ch));
        }
    };
    dfs1(dfs1,0,-1);
    dfs2(dfs2,0,-1,1);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());

    int s=ans.size();
    cout << dp[0][0] << ' ' << s << '\n';
    for (int i=0;i<s;++i) cout << ans[i]+1 << (i+1==s?'\n':' ');
}