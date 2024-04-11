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

bool check(string s){
    int cnt=1;
    s+='$';
    for (int i=1;i<s.size();++i){
        if (s[i]==s[i-1]) ++cnt;
        else {
            if (cnt>2) return false;
            cnt=1;
        }
    }
    return true;
}

void solve(){
    int n; string S; cin >> n >> S;
    vector<string> v={"RL","LL","LR","RR"};
    int ans=INF;
    for (int i=0;i<4;++i){
        vector<vector<int>> dp(n-1,vector<int>(4,INF));
        dp[0][i]=(S[0]!=v[i][0])+(S[1]!=v[i][1]);
        for (int j=2;j<n;++j){
            chmin(dp[j-1][1],dp[j-2][0]+(S[j]!='L'));
            chmin(dp[j-1][3],dp[j-2][2]+(S[j]!='R'));
            chmin(dp[j-1][0],dp[j-2][2]+(S[j]!='L'));
            chmin(dp[j-1][0],dp[j-2][3]+(S[j]!='L'));
            chmin(dp[j-1][2],dp[j-2][0]+(S[j]!='R'));
            chmin(dp[j-1][2],dp[j-2][1]+(S[j]!='R'));
        }
        for (int j=0;j<4;++j){
            if (check(v[j]+v[i])){
                chmin(ans,dp[n-2][j]);
            }
        }
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