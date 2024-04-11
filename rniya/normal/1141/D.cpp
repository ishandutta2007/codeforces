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
    string L,R; cin >> L >> R;
    vector<vector<int>> cntl(27),cntr(27);
    for (int i=0;i<n;++i){
        if (L[i]!='?') cntl[L[i]-'a'].emplace_back(i+1);
        else cntl[26].emplace_back(i+1);
        if (R[i]!='?') cntr[R[i]-'a'].emplace_back(i+1);
        else cntr[26].emplace_back(i+1);
    }
    vector<pair<int,int>> ans;
    for (int i=0;i<26;++i){
        while(!cntl[i].empty()&&!cntr[i].empty()){
            ans.emplace_back(cntl[i].back(),cntr[i].back());
            cntl[i].pop_back(); cntr[i].pop_back();
        }
    }
    for (int i=0;i<26;++i){
        while(!cntl[26].empty()&&!cntr[i].empty()){
            ans.emplace_back(cntl[26].back(),cntr[i].back());
            cntl[26].pop_back(); cntr[i].pop_back();
        }
    }
    for (int i=0;i<27;++i){
        while(!cntl[i].empty()&&!cntr[26].empty()){
            ans.emplace_back(cntl[i].back(),cntr[26].back());
            cntl[i].pop_back(); cntr[26].pop_back();
        }
    }
    cout << ans.size() << '\n';
    for (auto p:ans) cout << p.first << ' ' << p.second << '\n';
}