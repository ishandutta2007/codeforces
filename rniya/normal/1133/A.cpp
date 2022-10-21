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

vector<int> c={600,60,0,10,1};

int f(string s){
    int res=0;
    for (int i=0;i<5;++i) if (i!=2) res+=(s[i]-'0')*c[i];
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S,T; cin >> S >> T;
    int x=f(S),y=f(T);
    int z=(x+y)/2;
    string ans="";
    for (int i=0;i<5;++i){
        if (i==2){ans+=':'; continue;}
        ans+=(char)('0'+(z/c[i]));
        z%=c[i];
    }
    cout << ans << '\n';
}