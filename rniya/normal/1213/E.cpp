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
    int n; string S,T; cin >> n >> S >> T;
    int same=(S[0]==S[1]||T[0]==T[1]);
    vector<int> perm(3);
    iota(perm.begin(),perm.end(),0);
    string seg;
    do {
        string cnt="";
        for (int i=0;i<3;++i) cnt+='a'+perm[i];
        int ok=1;
        if (!same) for (int i=0;i<2;++i){
            if (cnt[i]==S[0]&&cnt[i+1]==S[1]) ok=0;
            if (cnt[i]==T[0]&&cnt[i+1]==T[1]) ok=0;
        } else for (int i=0;i<3;++i){
            if (cnt[i]==S[0]&&cnt[(i+1)%3]==S[1]) ok=0;
            if (cnt[i]==T[0]&&cnt[(i+1)%3]==T[1]) ok=0;
        }
        if (ok) seg=cnt;
    } while(next_permutation(perm.begin(),perm.end()));
    cout << "YES" << '\n';
    if (!same)
        for (int i=0;i<3;++i)
            for (int j=0;j<n;++j)
                cout << seg[i];
    else for (int i=0;i<n;++i) cout << seg;
    cout << '\n';
}