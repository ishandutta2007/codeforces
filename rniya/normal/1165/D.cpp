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

template<typename T>
vector<T> divisor(T n){
    vector<T> res;
    for (T i=1;i*i<=n;++i) if (n%i==0){
        res.emplace_back(i);
        if (i!=n/i) res.emplace_back(n/i);
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        vector<ll> d(n); cin >> d;
        sort(d.begin(),d.end());
        ll ans=d[0]*d[n-1];
        int ok=1;
        for (int i=0;i<n;++i) if (ans%d[i]!=0) ok=0;
        vector<ll> div=divisor(ans);
        if (div.size()!=n+2) ok=0;
        cout << (ok?ans:-1) << '\n';
    }
}