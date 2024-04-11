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
    vector<int> x(2),y(2);
    vector<int> X(4),Y(4);
    for (int i=0;i<2;++i) cin >> x[i] >> y[i];
    for (int i=0;i<4;++i) cin >> X[i] >> Y[i];
    int ok=1;
    for (int i=0;i<2;++i){
        if (X[2*i+1]<=x[0]||x[1]<=X[2*i]||Y[2*i+1]<=y[0]||y[1]<=Y[2*i]) continue;
        if (X[2*i]<=x[0]&&x[1]<=X[2*i+1]){
            if (Y[2*i]<=y[0]&&y[1]<=Y[2*i+1]) ok=0;
            else if (Y[2*i]<=y[0]) y[0]=Y[2*i+1];
            else if (y[1]<=Y[2*i+1]) y[1]=Y[2*i];
        } else if (Y[2*i]<=y[0]&&y[1]<=Y[2*i+1]){
            if (X[2*i]<=x[0]) x[0]=X[2*i+1];
            else if (x[1]<=X[2*i+1]) x[1]=X[2*i];
        }
    }
    cout << (ok?"YES":"NO") << '\n';

}