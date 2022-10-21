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

const int MAX_R=6e4+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,r; cin >> n >> r;
    vector<pair<int,int>> pos,neg;
    for (int i=0;i<n;++i){
        int a,b; cin >> a >> b;
        if (b>=0) pos.emplace_back(a,b);
        else neg.emplace_back(a+b,b);
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    reverse(neg.begin(),neg.end());
    vector<pair<int,int>> pro;
    for (auto p:pos) pro.emplace_back(p);
    for (auto p:neg) pro.emplace_back(p);
    vector<vector<int>> dp(n+1,vector<int>(MAX_R,-1));
    dp[0][r]=0;
    for (int i=0;i<n;++i){
        int a=pro[i].first,b=pro[i].second;
        for (int j=0;j<MAX_R;++j){
            if (dp[i][j]<0) continue;
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if (j+(b<0?b:0)<a) continue;
            if (j+b<0) continue;
            dp[i+1][j+b]=max(dp[i+1][j+b],dp[i][j]+1);
        }
    }
    int ans=0;
    for (int j=0;j<MAX_R;++j) ans=max(ans,dp[n][j]);
    cout << (ans==n?"YES":"NO") << '\n';
}