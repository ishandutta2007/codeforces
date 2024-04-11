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
    int n,m; cin >> n >> m;
    vector<int> x(m);
    for (int i=0;i<m;++i) cin >> x[i],--x[i];
    ll sum=0;
    for (int i=0;i<m-1;++i) sum+=abs(x[i+1]-x[i]);
    vector<ll> imos(n,0);
    for (int i=0;i<m-1;++i){
        int m=min(x[i],x[i+1]),M=max(x[i],x[i+1]);
        if (m==M) continue;
        --imos[m+1]; ++imos[M];
    }
    for (int i=0;i<n-1;++i) imos[i+1]+=imos[i];
    for (int i=0;i<n;++i) imos[i]+=sum;
    for (int i=0;i<m;++i){
        if (0<=i-1){
            imos[x[i]]-=abs(x[i]-x[i-1]);
            imos[x[i]]+=x[i-1]<x[i]?x[i-1]+1:(x[i]<x[i-1]?x[i-1]:0);
        }
        if (i+1<m){
            imos[x[i]]-=abs(x[i]-x[i+1]);
            imos[x[i]]+=x[i+1]<x[i]?x[i+1]+1:(x[i]<x[i+1]?x[i+1]:0);
        }
    }
    for (int i=0;i<n;++i) cout << imos[i] << (i+1==n?'\n':' ');
}