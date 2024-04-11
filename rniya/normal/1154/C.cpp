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
    vector<int> eat={0,0,1,2,0,2,1};
    vector<int> cnt(3); cin >> cnt;
    int ans=min({cnt[0]/3,cnt[1]/2,cnt[2]/2});
    cnt[0]-=3*ans,cnt[1]-=2*ans,cnt[2]-=2*ans;
    int Max=0;
    for (int i=0;i<7;++i){
        int rest=0;
        vector<int> a=cnt;
        for (int j=0;j<7;++j,++rest){
            if (!a[eat[(i+j)%7]]) break;
            --a[eat[(i+j)%7]];
        }
        chmax(Max,rest);
    }
    cout << ans*7+Max << '\n';
}