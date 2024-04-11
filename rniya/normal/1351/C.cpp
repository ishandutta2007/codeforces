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
const char dir[4]={'N','E','S','W'};

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
    int t; cin >> t;
    for (;t--;){
        string S; cin >> S;
        int x=0,y=0,ans=0;
        set<pair<pair<int,int>,pair<int,int>>> cnt;
        for (int i=0;i<S.size();++i){
            int nx=x,ny=y;
            for (int j=0;j<4;++j){
                if (S[i]==dir[j]){
                    nx+=dx[j],ny+=dy[j];
                }
            }
            pair<int,int> p={x,y},q={nx,ny};
            if (p>q) swap(p,q);
            ans+=(cnt.count({p,q})?1:5);
            cnt.insert({p,q});
            x=nx,y=ny;
        }
        cout << ans << '\n';
    }
}