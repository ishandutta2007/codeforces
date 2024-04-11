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

const int MAX_Q=510;
ll a,b,q;
ll l[MAX_Q],r[MAX_Q];
set<pair<int,int>> ok;
vector<int> ans;

void solve(){
    ok.clear(); ans.clear();
    for (int i=0;i<a;++i)
        for (int j=0;j<b;++j)
            if (i%b!=j%a) ok.emplace(i,j);
    for (int i=0;i<a*b;++i)
        if (ok.count({i%a,i%b}))
            ans.emplace_back(i);
    int n=ans.size();
    for (int i=0;i<q;++i){
        ll cnt=0;
        cnt+=r[i]/(a*b)*n;
        cnt+=(ll)(upper_bound(ans.begin(),ans.end(),r[i]%(a*b))-ans.begin());
        cnt-=(l[i]-1)/(a*b)*n;
        cnt-=(ll)(upper_bound(ans.begin(),ans.end(),(l[i]-1)%(a*b))-ans.begin());
        cout << cnt << (i+1==q?'\n':' ');
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> a >> b >> q;
        for (int i=0;i<q;++i) cin >> l[i] >> r[i];
        solve();
    }
}