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

const int MAX_N=101,MAX_A=10010;

int n;
int a[MAX_N*4],cnt[MAX_A];

void solve(){
    for (int i=0;i<MAX_A;++i) cnt[i]=0;
    for (int i=0;i<4*n;++i) ++cnt[a[i]];
    for (int i=0;i<MAX_A;++i) if (cnt[i]&1){
        cout << "NO" << '\n'; return;
    }
    for (int i=0;i<4*n;++i){
        int area=a[0]*a[i],ok=1;
        for (int i=0;i<4*n;++i){
            if (area%a[i]!=0){ok=0; break;}
            if (MAX_A<=area/a[i]){ok=0; break;}
            if (a[i]!=area/a[i]&&cnt[a[i]]!=cnt[area/a[i]]){ok=0; break;}
            if (a[i]==area/a[i]&&cnt[a[i]]%4!=0){ok=0; break;}
        }
        if (ok){cout << "YES" << '\n'; return;}
    }
    cout << "NO" << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n;
        for (int i=0;i<4*n;++i) cin >> a[i];
        solve();
    }
}