#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};
#define LOCAL

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
    vector<int> n(3); cin >> n;
    vector<vector<int>> a(3),b(3);
    for (int i=0;i<3;++i){
        for (int j=0;j<n[i];++j){
            int r; cin >> r;
            a[i].emplace_back(r);
        }
        sort(ALL(a[i]));
        for (int j=n[i]-1;j>=0;--j){
            b[i].emplace_back(-a[i][j]);
        }
    }
    auto f=[](ll a,ll b,ll c){return (a-b)*(a-b)+(b-c)*(b-c)+(c-a)*(c-a);};
    ll ans=IINF*4;
    for (int i=0;i<3;++i){
        for (int j=0;j<n[i];++j){
            ll low=-1,high=-1;
            for (int k=0;k<3;++k){
                if (k==i) continue;
                if (low<0){
                    auto itr=lower_bound(ALL(b[k]),-a[i][j]);
                    if (itr==b[k].end()) break;
                    low=-(*itr);
                } else {
                    auto itr=lower_bound(ALL(a[k]),a[i][j]);
                    if (itr==a[k].end()) break;
                    high=*itr;
                }
            }
            if (low>0&&high>0) chmin(ans,f(low,a[i][j],high));
            low=high=-1;
            for (int k=2;k>=0;--k){
                if (k==i) continue;
                if (low<0){
                    auto itr=lower_bound(ALL(b[k]),-a[i][j]);
                    if (itr==b[k].end()) break;
                    low=-(*itr);
                } else {
                    auto itr=lower_bound(ALL(a[k]),a[i][j]);
                    if (itr==a[k].end()) break;
                    high=*itr;
                }
            }
            if (low>0&&high>0) chmin(ans,f(low,a[i][j],high));
        }
    }
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