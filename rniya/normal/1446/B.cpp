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
    int n,m; cin >> n >> m;
    string S,T; cin >> S >> T;

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    dp[0][0]=0;
    int ans=0;
    for (int i=0;i<=n;++i){
        for (int j=0;j<=m;++j){
            int x=dp[i][j];
            chmax(ans,x);
            if (i+1<=n) chmax(dp[i+1][j],x-1);
            if (j+1<=m) chmax(dp[i][j+1],x-1);
            if (i+1<=n&&j+1<=m) chmax(dp[i+1][j+1],x+(S[i]==T[j]?2:-2));
        }
    }

    cout << ans << '\n';
}

/*
const int MAX_N=5010;
int dp[MAX_N][MAX_N][3][3];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    string S,T; cin >> S >> T;

    for (int i=0;i<=n;++i){
        for (int j=0;j<=m;++j){
            for (int k=0;k<3;++k){
                for (int l=0;l<3;++l){
                    dp[i][j][k][l]=-INF;
                }
            }
        }
    }
    dp[0][0][0][0]=0;
    int ans=0;
    for (int i=0;i<=n;++i){
        for (int j=0;j<=m;++j){
            for (int k=0;k<3;++k){
                for (int l=0;l<3;++l){
                    int x=dp[i][j][k][l];
                    chmax(ans,x);
                    if (i+1<=n&&(k==0||k==2)) chmax(dp[i+1][j][k][l],x);
                    if (j+1<=m&&(l==0||l==2)) chmax(dp[i][j+1][k][l],x);
                    if (i+1<=n&&k==1) chmax(dp[i+1][j][k][l],x-1);
                    if (j+1<=m&&l==1) chmax(dp[i][j+1][k][l],x-1);
                    if (i+1<=n&&k==1&&j+1<=m&&l==1) chmax(dp[i+1][j+1][k][l],x+(S[i]==T[j]?2:-2));
                    if (i+1<=n&&k==0) chmax(dp[i+1][j][1][l],x-1);
                    if (j+1<=m&&l==0) chmax(dp[i+1][j][k][1],x-1);
                    if (i+1<=n&&k==1) chmax(dp[i+1][j][2][l],x);
                    if (j+1<=m&&l==1) chmax(dp[i+1][j][k][2],x);
                    if (i+1<=n&&j+1<=m&&k==0&&l==0) chmax(dp[i+1][j+1][1][1],x+(S[i]==T[j]?2:-2));
                }
            }
        }
    }

    cout << ans << '\n';
}

*/