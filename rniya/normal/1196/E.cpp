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

int b,w;

void solve(){
    if (b-1<=w&&w<=3*b+1){
        cout << "YES" << '\n';
        for (int i=2;i<=2*b;++i) cout << 2 << ' ' << i+1 << '\n';
        w-=b-1;
        if (!w) return;
        cout << 2 << ' ' << 2 << '\n'; --w;
        if (!w) return;
        cout << 2 << ' ' << 2*b+2 << '\n'; --w;
        if (!w) return;
        for (int i=2;i<=2*b;i+=2){
            cout << 1 << ' ' << i+1 << '\n'; --w;
            if (!w) return;
        }
        for (int i=2;i<=2*b;i+=2){
            cout << 3 << ' ' << i+1 << '\n'; --w;
            if (!w) return;
        }
    } else if (w-1<=b&&b<=3*w+1){
        cout << "YES" << '\n';
        for (int i=2;i<=2*w;++i) cout << 2 << ' ' << i << '\n';
        b-=w-1;
        if (!b) return;
        cout << 2 << ' ' << 1 << '\n'; --b;
        if (!b) return;
        cout << 2 << ' ' << 2*w+1 << '\n'; --b;
        if (!b) return;
        for (int i=2;i<=2*w;i+=2){
            cout << 1 << ' ' << i << '\n'; --b;
            if (!b) return;
        }
        for (int i=2;i<=2*w;i+=2){
            cout << 3 << ' ' << i << '\n'; --b;
            if (!b) return;
        }
    }
    cout << "NO" << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> b >> w;
        solve();
    }
}