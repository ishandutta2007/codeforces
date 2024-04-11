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

typedef pair<int,int> P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    vector<int> m(n),c(k);
    for (int i=0;i<n;++i) cin >> m[i];
    for (int i=0;i<k;++i) cin >> c[i];
    sort(m.begin(),m.end());
    reverse(m.begin(),m.end());
    vector<vector<int>> ans;
    int now=0;
    priority_queue<P,vector<P>,greater<P>> pq;
    for (int i=0;i<n;++i){
        if (c[m[i]-1]*now-i==0){
            ans.emplace_back(); ++now;
            ans[now-1].emplace_back(m[i]);
            pq.emplace(1,now-1);
        } else {
            auto p=pq.top(); pq.pop();
            ans[p.second].emplace_back(m[i]);
            pq.emplace(p.first+1,p.second);
        }
    }
    cout << now << '\n';
    for (int i=0;i<now;++i){
        cout << ans[i].size();
        for (int j=0;j<ans[i].size();++j) cout << ' ' << ans[i][j];
        cout << '\n';
    }
}