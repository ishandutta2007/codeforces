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
    int n; ll k; cin >> n >> k;
    string S; cin >> S;
    vector<vector<int>> nxt(n+1,vector<int>(26,n));
    for (int i=n-1;i>=0;--i){
        for (int j=0;j<26;++j) nxt[i][j]=nxt[i+1][j];
        nxt[i][S[i]-'a']=i;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    dp[0][0]=1;
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            for (int k=0;k<26;++k){
                if (n<=nxt[i][k]) continue;
                dp[nxt[i][k]+1][j+1]+=dp[i][j];
            }
        }
    }
    ll ans=0;
    for (int j=n;j>=0;--j){
        ll sum=0;
        for (int i=0;i<=n;++i) sum+=dp[i][j];
        ans+=min(sum,k)*(n-j);
        k-=min(sum,k);
        if (k==0) break;
    }
    cout << (0<k?-1:ans) << '\n';
}