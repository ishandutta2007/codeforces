#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
const int INF=1e5;
const long long IINF=1e18;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

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

const int MAX_N=1e5+10;

int n;
int x[MAX_N],y[MAX_N],f[MAX_N][4];

void solve(){
    int lx=-INF,rx=INF,ly=-INF,ry=INF;
    for (int i=0;i<n;++i){
        if (!f[i][0]) lx=max(lx,x[i]);
        if (!f[i][1]) ry=min(ry,y[i]);
        if (!f[i][2]) rx=min(rx,x[i]);
        if (!f[i][3]) ly=max(ly,y[i]);
    }
    if (rx<lx||ry<ly){cout << 0 << '\n'; return;}
    cout << 1 << ' ' << lx << ' ' << ly << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n;
        for (int i=0;i<n;++i){
            cin >> x[i] >> y[i];
            for (int j=0;j<4;++j) cin >> f[i][j];
        }
        solve();
    }
}