#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
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

const int MAX=1010;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> cnt(MAX,0);
    for (int i=0;i<n*n;++i){
        int a; cin >> a; ++cnt[a];
    }
    vector<vector<int>> ans(n,vector<int>(n));
    vector<int> sym;
    for (int i=1;i<MAX;++i){
        while(4<=cnt[i]&&sym.size()<(n/2)*(n/2)){
            sym.emplace_back(i); cnt[i]-=4;
        }
    }
    if (sym.size()<(n/2)*(n/2)){cout << "NO" << '\n'; return 0;}
    for (int i=0;i<n/2;++i){
        for (int j=0;j<n/2;++j){
            ans[i][j]=ans[n-1-i][j]=ans[i][n-1-j]=ans[n-1-i][n-1-j]=sym[i*(n/2)+j];
        }
    }
    int row=n/2,col=n/2;
    for (int i=1;i<MAX;++i){
        if (cnt[i]&1){
            if (ans[n/2][n/2]!=0){cout << "NO" << '\n'; return 0;}
            ans[n/2][n/2]=i; --cnt[i];
        }
        while(cnt[i]>0){
            if (row>0) ans[n/2-row][n/2]=ans[n/2+row][n/2]=i,--row;
            else ans[n/2][n/2-col]=ans[n/2][n/2+col]=i,--col;
            cnt[i]-=2;
        }
    }
    cout << "YES" << '\n';
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cout << ans[i][j] << (j+1==n?'\n':' ');
}