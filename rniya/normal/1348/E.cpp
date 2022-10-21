#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?'\n':' ');
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    vector<int> a(n),b(n);
    for (int i=0;i<n;++i) cin >> a[i] >> b[i];
    vector<vector<ll>> dp(n+1,vector<ll>(k,-1));
    dp[0][0]=0;
    int sum=0;
    for (int i=0;i<n;++i){
        if (i) (sum+=a[i-1]+b[i-1])%=k;
        for (int j=0;j<k;++j){
            if (dp[i][j]<0) continue;
            int use=(a[i]+b[i])%k,blue=(sum+k-j)%k,only=(a[i]+b[i])/k;
            int s=max(0,use-b[i]),t=min({use,k-1,a[i]});
            for (int l=s;l<=t;++l){
                int nj=j+l;
                chmax(dp[i+1][nj%k],dp[i][j]+only+nj/k+(blue+use-l)/k);
            }
            if (a[i]+b[i]<k) continue;
            use+=k; --only;
            s=max(0,use-b[i]),t=min({use,k-1,a[i]});
            for (int l=s;l<=t;++l){
                int nj=j+l;
                chmax(dp[i+1][nj%k],dp[i][j]+only+nj/k+(blue+use-l)/k);
            }
        }
    }
    ll ans=0;
    for (int j=0;j<k;++j) chmax(ans,dp[n][j]);
    cout << ans << '\n';
}