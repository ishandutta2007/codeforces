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

int n,k; string S;

void solve(){
    vector<int> cnt(26,0);
    int Min=30;
    for (int i=0;i<n;++i) ++cnt[S[i]-'a'],Min=min(Min,S[i]-'a');
    string ans="";
    if (cnt[Min]<k){
        for (int i=0;i<26;++i){
            if (cnt[i]<k) k-=cnt[i],cnt[i]=0;
            else {cout << (char)('a'+i) << '\n'; return;}
        }
    } else {
        ans+=(char)('a'+Min); cnt[Min]-=k;
        for (int i=25;i>=0;--i) if (0<cnt[i]) Min=i;
        if (cnt[Min]==n-k){
            for (int i=0;i<(cnt[Min]+k-1)/k;++i) ans+=(char)('a'+Min);
            cout << ans << '\n';
        } else {
            for (int i=0;i<26;++i)
                for (int j=0;j<cnt[i];++j)
                    ans+=(char)('a'+i);
            cout << ans << '\n';
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n >> k >> S;
        solve();
    }
}