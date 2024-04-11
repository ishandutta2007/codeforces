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

int n,k; string S;
string T="RGB";

void solve(){
    vector<vector<int>> cnt(n,vector<int>(3,0));
    for (int i=0;i<k;++i)
        for (int j=0;j<3;++j)
            cnt[0][j]+=(S[i]!=T[(i+j)%3]);
    for (int i=1;i+k-1<n;++i)
        for (int j=0;j<3;++j)
            cnt[i][j]=cnt[i-1][(j+2)%3]-(S[i-1]!=T[(j+2)%3])+(S[i+k-1]!=T[(j+k+2)%3]);
    int ans=INF;
    for (int i=0;i+k-1<n;++i)
        for (int j=0;j<3;++j)
            ans=min(ans,cnt[i][j]);
    cout << ans << '\n';
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n >> k >> S;
        solve();
    }
}