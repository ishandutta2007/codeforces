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
    int k; cin >> k;
    string S,T; cin >> S >> T;
    reverse(S.begin(),S.end());
    reverse(T.begin(),T.end());
    vector<int> cnt(k+1,0);
    for (int i=0;i<k;++i){
        int s=S[i]-'a',t=T[i]-'a';
        cnt[i]+=(S[i]-'a')+(T[i]-'a');
        cnt[i+1]+=cnt[i]/26; cnt[i]%=26;
    }
    for (int i=k;i>=0;--i){
        cnt[i-1]+=(cnt[i]&1)*26;
        cnt[i]/=2;
    }
    for (int i=k-1;i>=0;--i) cout << (char)('a'+cnt[i]);
    cout << '\n';
}