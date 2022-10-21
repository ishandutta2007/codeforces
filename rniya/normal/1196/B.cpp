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

const int MAX_N=2e5+10;

int n,k;
ll a[MAX_N];

void solve(){
    ll sum=0;
    for (int i=0;i<n;++i) sum+=a[i];
    if (abs(sum-k)&1LL){cout << "NO" << '\n'; return;}
    vector<int> ans;
    sum=0; int s=0;
    for (int i=0;i<n;++i){
        sum+=a[i];
        if ((sum&1LL)&&s<k-1){
            ans.emplace_back(i+1); ++s;
            sum=0;
        }
    }
    if (s<k-1){cout << "NO" << '\n'; return;}
    if (0<s&&ans.back()==n){cout << "NO" << '\n'; return;}
    ans.emplace_back(n); ++s;
    cout << "YES" << '\n';
    for (int i=0;i<s;++i) cout << ans[i] << (i+1==s?'\n':' ');
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n >> k;
        for (int i=0;i<n;++i) cin >> a[i];
        solve();
    }
}