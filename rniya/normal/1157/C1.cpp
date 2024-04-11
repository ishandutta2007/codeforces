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
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    stack<int> s;
    set<int> cnt;
    s.emplace(a[0]); cnt.emplace(a[0]);
    for (int i=1;i<n;++i){
        if (a[i-1]<a[i]) s.emplace(a[i]),cnt.emplace(a[i]);
        else break;
    }
    int ans=s.size(),l=ans,r=0;
    for (int i=n-1;i>=0;--i){
        if (i<n-1&&a[i]<=a[i+1]) break;
        if (cnt.count(a[i])){
            while(s.top()!=a[i]) cnt.erase(s.top()),s.pop();
            cnt.erase(s.top()),s.pop();
        }
        if (chmax(ans,(int)s.size()+n-i)) l=s.size(),r=n-i;
    }
    cout << ans << '\n';
    vector<pair<int,char>> v;
    for (int i=0;i<l;++i) v.emplace_back(a[i],'L');
    for (int i=0;i<r;++i) v.emplace_back(a[n-1-i],'R');
    sort(v.begin(),v.end());
    for (int i=0;i<ans;++i) cout << v[i].second;
    cout << '\n';
}