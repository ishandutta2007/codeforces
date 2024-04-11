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
    string S,T; cin >> S >> T;
    int s=S.size(),t=T.size();
    vector<int> pre(t+1),suf(t+1);
    vector<vector<int>> pos(26);
    for (int i=0;i<s;++i) pos[S[i]-'a'].emplace_back(i);
    pre[0]=-1,suf[t]=s;
    int now=-1;
    for (int i=0;i<t;++i){
        int x=T[i]-'a';
        now=*upper_bound(pos[x].begin(),pos[x].end(),now);
        pre[i+1]=now;
    }
    now=s;
    for (int i=t-1;i>=0;--i){
        int x=T[i]-'a';
        int y=lower_bound(pos[x].begin(),pos[x].end(),now)-pos[x].begin();
        now=pos[x][y-1]; suf[i]=now;
    }
    int ans=0;
    for (int i=0;i<=t;++i) ans=max(ans,suf[i]-pre[i]-1);
    cout << ans << '\n';
}