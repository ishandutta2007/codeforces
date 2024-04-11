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

int n;
string S[2];

void solve(){
    for (int i=0;i<2;++i)
        for (int j=0;j<n;++j)
            S[i][j]=(S[i][j]<'3'?'0':'1');
    int now=0;
    for (int i=0;i<n;++i){
        if (S[now][i]=='0') continue;
        if (S[now][i]=='1'){
            if (S[now^1][i]=='1') now^=1;
            else {cout << "NO" << '\n'; return;}
        }
    }
    cout << (now?"YES":"NO") << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q; cin >> q;
    for (;q--;){
        cin >> n >> S[0]>> S[1];
        solve();
    }
}