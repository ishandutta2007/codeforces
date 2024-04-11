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

const int MAX_N=101;

int n;
int a[MAX_N];
vector<int> dp[MAX_N];

bool comp(vector<int> a,vector<int> b){
    if (b.empty()) return 1;
    for (int i=0;i<a.size();++i){
        if (a[i]<b[i]) return 1;
        if (b[i]<a[i]) return 0;
    }
    return 0;
}

void solve(){
    for (int i=0;i<=n;++i) dp[i].clear();
    for (int i=0;i<n;++i){
        for (int j=0;j<=i;++j){
            vector<int> cnt(i+1);
            for (int k=0;k<i+1;++k){
                if (k<j) cnt[k]=dp[j][k];
                if (k==j) cnt[k]=a[i];
                if (j<k) cnt[k]=a[k-1];
            }
            if (comp(cnt,dp[i+1])) dp[i+1]=cnt;
            if (0<=j-1) swap(cnt[j-1],cnt[j]);
            if (comp(cnt,dp[i+1])) dp[i+1]=cnt;
        }
    }
    for (int i=0;i<n;++i) cout << dp[n][i] << (i+1==n?'\n':' ');
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n;
        for (int i=0;i<n;++i) cin >> a[i];
        solve();
    }
}