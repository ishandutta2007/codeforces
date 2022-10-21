#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
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
    int n; cin >> n;
    vector<pair<ll,int>> A;
    for (int i=0;i<n;++i){
        ll a; cin >> a;
        A.emplace_back(a,i);
    }
    sort(A.begin(),A.end());
    vector<ll> dp(n+1,IINF);
    vector<int> pre(n+1),num(n+1);
    ll Min=IINF;
    int id=-1,team=0;
    dp[0]=0;
    for (int i=0;i<n;++i){
        if (0<=i-2&&chmin(Min,dp[i-2]-A[i-2].first)) id=i-2,team=num[i-2]+1;
        dp[i+1]=Min+A[i].first; pre[i+1]=id,num[i+1]=team;
    }
    vector<int> ans(n);
    int now=n;
    while(now){
        for (int i=pre[now];i<now;++i)
            ans[A[i].second]=num[now];
        now=pre[now];
    }
    cout << dp[n] << ' ' << num[n] << '\n';
    for (int i=0;i<n;++i) cout << ans[i] << (i+1==n?'\n':' ');
}