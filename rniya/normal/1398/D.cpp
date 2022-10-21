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
    os << '(' << p.first << ',' << p.second << ')';
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

const int MAX_C=210;
int dp[MAX_C][MAX_C][MAX_C];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int R,G,B; cin >> R >> G >> B;
    vector<int> r(R),g(G),b(B); cin >> r >> g >> b;
    sort(ALL(r),[](int a,int b){return a>b;});
    sort(ALL(g),[](int a,int b){return a>b;});
    sort(ALL(b),[](int a,int b){return a>b;});

    int ans=0;
    for (int i=0;i<=R;++i){
        for (int j=0;j<=G;++j){
            for (int k=0;k<=B;++k){
                chmax(ans,dp[i][j][k]);
                if (i+1<=R&&j+1<=G) chmax(dp[i+1][j+1][k],dp[i][j][k]+r[i]*g[j]);
                if (j+1<=G&&k+1<=B) chmax(dp[i][j+1][k+1],dp[i][j][k]+g[j]*b[k]);
                if (k+1<=B&&i+1<=R) chmax(dp[i+1][j][k+1],dp[i][j][k]+r[i]*b[k]);
            }
        }
    }

    cout << ans << '\n';
}