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
    ll H; int n; cin >> H >> n;
    vector<ll> d(n),sum(n+1,0);
    for (int i=0;i<n;++i) cin >> d[i];
    for (int i=0;i<n;++i) d[i]*=-1,sum[i+1]=sum[i]+d[i];
    ll ans=IINF;
    for (int i=0;i<n;++i){
        if (d[i]<=0) continue;
        if (H<=sum[i+1]){chmin(ans,(ll)i+1); continue;}
        if (sum[n]<=0) continue;
        ll x=(H-sum[i+1]+sum[n]-1)/sum[n];
        chmin(ans,x*n+i+1);
    }
    cout << (ans==IINF?-1:ans) << '\n';
}