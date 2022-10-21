#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
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
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(2));
    for (int i=0;i<n;++i)
        for (int j=0;j<2;++j)
            cin >> a[i][j],--a[i][j];
    if (n==3){
        cout << 1 << ' ' << 2 << ' ' << 3 << '\n';
        return 0;
    }
    vector<int> ans(n,-1),pos(n,-1);
    queue<int> que;
    que.emplace(0);
    ans[0]=0,pos[0]=0;
    while (!que.empty()){
        int x=que.front(); que.pop();
        int y=pos[x];
        if (~ans[(y+1)%n]&&~ans[(y+2)%n]) continue;
        for (int i=0;i<2;++i){
            for (int j=0;j<2;++j){
                if (a[a[x][i]][j]==a[x][i^1]){
                    if (ans[(y+1)%n]<0){
                        ans[(y+1)%n]=a[x][i];
                        pos[a[x][i]]=(y+1)%n;
                        que.emplace(a[x][i]);
                    }
                    if (ans[(y+2)%n]<0){
                        ans[(y+2)%n]=a[x][i^1];
                        pos[a[x][i^1]]=(y+2)%n;
                        que.emplace(a[x][i^1]);
                    }
                }
            }
        }
    }
    for (int i=0;i<n;++i) cout << ans[i]+1 << (i+1==n?'\n':' ');
}