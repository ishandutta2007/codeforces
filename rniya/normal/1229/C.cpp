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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i=0;i<m;++i){
        int a,b; cin >> a >> b; --a,--b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    int q; cin >> q;
    vector<int> Q(q);
    for (int i=0;i<q;++i) cin >> Q[i],--Q[i];

    vector<int> dp(n,0),S(n),sum(n,0),last(n,-1),deg(n);
    iota(ALL(S),0);
    ll ans=0;
    for (int v=0;v<n;++v){
        deg[v]=G[v].size();
        for (int u:G[v]){
            if (S[u]<S[v]){
                ++dp[v];
                ans+=dp[u];
            }
        }
    }
    cout << ans << '\n';
    for (int i=0;i<q;++i){
        ++sum[Q[i]];
        last[Q[i]]=i;
    }
    for (int i=0;i<n;++i) sort(ALL(G[i]),[&](int a,int b){return last[a]>last[b];});

    auto update=[&](int v,int t){
        int g=0;
        for (int u:G[v]){
            if (S[u]<S[v]) continue;
            ++g; ans-=deg[u]-dp[u];
            --dp[u]; ans+=dp[u];
        }
        ans-=(ll)g*(deg[v]-g);
        cout << ans << '\n';
        dp[v]=deg[v]; S[v]=n+t;
        while(!G[v].empty()&&last[G[v].back()]<t) G[v].pop_back();
    };
    for (int i=0;i<q;++i) update(Q[i],i);
}