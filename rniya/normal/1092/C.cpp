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

int n;
string pre="",suf="";

int PS(string s){
    int res=3,sz=s.size();
    for (int i=0;i<sz;++i) if (s[i]!=pre[i]){
        res^=1; break;
    }
    for (int i=0;i<sz;++i) if (s[sz-1-i]!=suf[n-2-i]){
        res^=2; break;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int N=2*n-2;
    vector<string> S(N); cin >> S;
    for (int i=0;i<N;++i){
        if (S[i].size()==n-1){
            (pre==""?pre:suf)=S[i];
        }
    }
    vector<int> ans(N);
    for (int _=0;_<2;++_){
        vector<int> cnt(N),check1(n,0),check2(n,0);
        for (int i=0;i<N;++i){
            int ps=PS(S[i]),sz=S[i].size();
            if ((ps&1)&&!check1[sz]) cnt[i]=0,check1[sz]=1;
            else if ((ps&2)&&!check2[sz]) cnt[i]=1,check2[sz]=1;
        }
        int ok=1;
        for (int i=1;i<n;++i) ok&=check1[i];
        for (int i=1;i<n;++i) ok&=check2[i];
        if (ok) ans=cnt;
        swap(pre,suf);
    }
    for (int i=0;i<N;++i) cout << (ans[i]?'S':'P');
    cout << '\n';
}