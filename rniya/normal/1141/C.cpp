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
    int n; cin >> n;
    vector<ll> q(n-1); cin >> q;
    vector<ll> p(n,0);
    ll Min=0;
    for (int i=0;i<n-1;++i) p[i+1]=p[i]+q[i],chmin(Min,p[i+1]);
    for (int i=0;i<n;++i) p[i]-=Min-1;
    vector<int> cnt(n+1,0);
    for (int i=0;i<n;++i){
        if (p[i]<0||n<p[i]){cout << -1 << '\n'; return 0;}
        ++cnt[p[i]];
    }
    for (int i=1;i<=n;++i) if (cnt[i]!=1){
        cout << -1 << '\n'; return 0;
    }
    cout << p;
}