#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; string S; cin >> n >> S;
    vector<int> c(n);
    for (int i=0;i<n;++i){
        if (S[i]=='R') c[i]=0;
        if (S[i]=='G') c[i]=1;
        if (S[i]=='B') c[i]=2;
    }
    vector<vector<int>> dp(n+1,vector<int>(3,INF))
                        ,pre(n+1,vector<int>(3));
    dp[0][0]=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<3;++j){
            for (int k=0;k<3;++k){
                if (c[i]!=k&&(!i||j!=k)) if (chmin(dp[i+1][k],dp[i][j]+1)) pre[i+1][k]=j;
                if (c[i]==k&&(!i||j!=k)) if (chmin(dp[i+1][k],dp[i][j])) pre[i+1][k]=j;
            }
        }
    }
    int ans=INF,r;
    for (int j=0;j<3;++j) if (chmin(ans,dp[n][j])) r=j;
    cout << ans << '\n';
    vector<int> col(n);
    col[n-1]=r;
    for (int i=n;i>=2;--i){
        col[i-2]=pre[i][r];
        r=pre[i][r];
    }
    for (int i=0;i<n;++i){
        if (col[i]==0) cout << 'R';
        if (col[i]==1) cout << 'G';
        if (col[i]==2) cout << 'B';
    }
    cout << '\n';
}