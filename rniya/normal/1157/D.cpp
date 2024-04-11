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
    ll n,k; cin >> n >> k;
    ll Min=k*(k+1)/2;
    if (n<Min){cout << "NO" << '\n'; return 0;}
    n-=Min;
    vector<int> ans(k);
    for (int i=0;i<k;++i) ans[i]=i+1+n/k;
    if (0<n/k||n%k<k-1||k==1) ans[k-1]+=n%k;
    else {
        if (3<k) ans[k-1]+=k-2,++ans[k-2];
        else {cout << "NO" << '\n'; return 0;}
    }
    cout << "YES" << '\n';
    cout << ans;
}