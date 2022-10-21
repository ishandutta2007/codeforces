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
    int n,k; cin >> n >> k;
    vector<int> a(n); cin >> a;
    vector<int> left(n,-1),right(n,-1),ans(n);
    for (int i=1;i<n;++i) left[i]=i-1;
    for (int i=0;i<n-1;++i) right[i]=i+1;
    set<pair<int,int>> s;
    for (int i=0;i<n;++i) s.emplace(a[i],i);
    for (int i=1;!s.empty();i=3-i){
        auto itr=s.end();
        auto p=*(--itr);
        ans[p.second]=i; s.erase(p);
        int L=p.second,R=p.second;
        for (int j=0;j<k;++j){
            L=left[L];
            if (L<0) break;
            ans[L]=i; s.erase({a[L],L});
        }
        for (int j=0;j<k;++j){
            R=right[R];
            if (R<0) break;
            ans[R]=i; s.erase({a[R],R});
        }
        if (~L) L=left[L];
        if (~R) R=right[R];
        if (~L) right[L]=R;
        if (~R) left[R]=L;
    }
    for (int i=0;i<n;++i) cout << ans[i];
    cout << '\n';
}