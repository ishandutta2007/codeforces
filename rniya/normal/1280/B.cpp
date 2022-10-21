#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
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
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();++itr){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();++itr){
        os << *itr;
        if (++itr!=s.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}

void debug_out(){cerr << '\n';}
template<class Head,class... Tail>
void debug_out(Head&& head,Tail&&... tail){
    cerr << head;
    if (sizeof...(Tail)>0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...) cerr << " ";\
cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n';\
cerr << " ";\
debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}
#pragma endregion

void solve(){
    int r,c; cin >> r >> c;
    vector<string> S(r); cin >> S;
    int cnt=0;
    for (int i=0;i<r;++i){
        for (int j=0;j<c;++j){
            cnt+=(S[i][j]=='A');
        }
    }
    if (!cnt){cout << "MORTAL" << '\n'; return;}
    if (cnt==r*c){cout << 0 << '\n'; return;}
    int edge=0;
    for (int i=0;i<r;++i){
        edge+=(S[i][0]=='A');
        edge+=(S[i][c-1]=='A');
    }
    for (int j=1;j<c-1;++j){
        edge+=(S[0][j]=='A');
        edge+=(S[r-1][j]=='A');
    }
    if (!edge){cout << 4 << '\n'; return;}
    int ans=3;
    for (int i=0;i<r;++i){
        for (int j=0;j<c;++j){
            if (S[i][j]=='P') break;
            if (j==c-1) chmin(ans,(i==0||i==r-1?1:2));
        }
    }
    for (int j=0;j<c;++j){
        for (int i=0;i<r;++i){
            if (S[i][j]=='P') break;
            if (i==r-1) chmin(ans,(j==0||j==c-1?1:2));
        }
    }
    if (S[0][0]=='A') chmin(ans,2);
    if (S[0][c-1]=='A') chmin(ans,2);
    if (S[r-1][0]=='A') chmin(ans,2);
    if (S[r-1][c-1]=='A') chmin(ans,2);
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}