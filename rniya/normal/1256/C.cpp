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
    int n,m,d; cin >> n >> m >> d;
    vector<int> c(m);
    for (int i=0;i<m;++i) cin >> c[i];
    int rest=n;
    for (int i=0;i<m;++i) rest-=c[i];
    vector<int> ans(n,0);
    int now=-1;
    for (int i=0;i<m;++i){
        int skip=min(rest,d-1); rest-=skip;
        for (int j=now+skip+1;j<now+skip+1+c[i];++j)
            ans[j]=i+1;
        now+=skip+c[i];
    }
    now=-1;
    int ok=1;
    while(now+d<n){
        for (int i=d;i>0;--i){
            if (ans[now+i]){now+=i; break;}
            if (i==1){ok=0; break;}
        }
        if (!ok) break;
    }
    if (!ok){cout << "NO" << '\n'; return 0;}
    cout << "YES" << '\n';
    for (int i=0;i<n;++i) cout << ans[i] << (i+1==n?'\n':' ');
}