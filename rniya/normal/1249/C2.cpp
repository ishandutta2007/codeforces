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

void solve(ll n){
    ll m=n;
    vector<int> convert;
    while(3<=m){
        convert.emplace_back(m%3);
        m/=3;
    }
    convert.emplace_back(m);
    convert.emplace_back(0);
    int d=convert.size(),most;
    for (most=d-1;most>=0;--most){
        if (convert[most]==2) break;
    }
    if (most<0){cout << n << '\n'; return;}
    for (int i=0;i<most;++i) convert[i]=0;
    for (int i=most;i<d;++i){
        if (convert[i]==2) convert[i]=0,convert[i+1]+=1;
        else if (convert[i]==3) convert[i]=0,convert[i+1]+-1;
    }
    ll po=1,ans=0;
    for (int i=0;i<d;++i){
        ans+=po*convert[i];
        po*=3;
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        ll n; cin >> n;
        solve(n);
    }
}