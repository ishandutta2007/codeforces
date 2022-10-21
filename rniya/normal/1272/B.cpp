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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        string S; cin >> S;
        vector<int> cnt(4,0);
        for (char c:S) for (int i=0;i<4;++i){
            if (c==dir[i]) ++cnt[i];
        }
        for (int i=0;i<2;++i){
            cnt[i]=min(cnt[i],cnt[i+2]);
            cnt[i+2]=cnt[i];
        }
        if (2<=cnt[0]&&!cnt[1]) cnt[0]=cnt[2]=1;
        if (2<=cnt[1]&&!cnt[0]) cnt[1]=cnt[3]=1;
        string ans="";
        for (int i=0;i<4;++i)
            for (int j=0;j<cnt[i];++j)
                ans+=dir[i];
        cout << ans.size() << '\n';
        cout << ans << '\n';
    }
}