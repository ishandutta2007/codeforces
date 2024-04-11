#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};
#define LOCAL

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<int> d(m); cin >> d;
    int g,r; cin >> g >> r;
    sort(ALL(d));
    deque<pair<int,int>> deq;
    vector<vector<int>> dp(m,vector<int>(g,INF));
    dp[0][0]=0; deq.emplace_back(0,0);
    while(!deq.empty()){
        auto p=deq.front(); deq.pop_front();
        int v=p.first,c=p.second;
        if (v==m-1) continue;
        if (v+1<m&&c+d[v+1]-d[v]<=g){
            if (c+d[v+1]-d[v]==g){
                if (chmin(dp[v+1][0],dp[v][c]+1)){
                    deq.emplace_back(v+1,0);
                }
            } else {
                if (chmin(dp[v+1][c+d[v+1]-d[v]],dp[v][c])){
                    deq.emplace_front(v+1,c+d[v+1]-d[v]);
                }
            }
        }
        if (v-1>=0&&c-d[v-1]+d[v]<=g){
            if (c-d[v-1]+d[v]==g){
                if (chmin(dp[v-1][0],dp[v][c]+1)){
                    deq.emplace_back(v-1,0);
                }
            } else {
                if (chmin(dp[v-1][c-d[v-1]+d[v]],dp[v][c])){
                    deq.emplace_front(v-1,c-d[v-1]+d[v]);
                }
            }
        }
    }
    int ans=INF;
    for (int j=0;j<g;++j){
        if (dp[m-1][j]==INF) continue;
        chmin(ans,(g+r)*dp[m-1][j]+j-(!j?r:0));
    }
    cout << (ans==INF?-1:ans) << '\n';
}