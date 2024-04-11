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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    vector<queue<int>> pos(6);
    vector<int> b={4,8,15,16,23,42};
    for (int i=0;i<n;++i){
        for (int j=0;j<6;++j) if (a[i]==b[j]){
            pos[j].emplace(i);
        }
    }
    int ans=0;
    while(1){
        int pre=-1,ok=0;
        for (int i=0;i<6;++i){
            while(!pos[i].empty()&&pos[i].front()<=pre){
                pos[i].pop(); ++ans;
            }
            if (!pos[i].empty()) pre=pos[i].front();
            else break;
            if (i==5) ok=1;
        }
        if (!ok) break;
        for (int i=0;i<6;++i) pos[i].pop();
    }
    for (int i=0;i<6;++i) ans+=pos[i].size();
    cout << ans << '\n';
}