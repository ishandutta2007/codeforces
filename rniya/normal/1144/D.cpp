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

const int MAX_A=2e5+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    vector<int> cnt(MAX_A,0);
    for (int i=0;i<n;++i) ++cnt[a[i]];
    int Max=0,num,pos;
    for (int i=0;i<MAX_A;++i){
        if (chmax(Max,cnt[i])) num=i;
    }
    cout << n-Max << '\n';
    for (int i=0;i<n;++i) if (a[i]==num) pos=i;
    for (int i=pos-1;i>=0;--i) if (a[i]!=num){
        cout << (a[i]<num?1:2) << ' ' << i+1 << ' ' << i+2 << '\n';
    }
    for (int i=pos+1;i<n;++i) if (a[i]!=num){
        cout << (a[i]<num?1:2) << ' ' << i+1 << ' ' << i << '\n';
    }
}