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

const int MAX_N=14;
vector<ll> dp[1<<MAX_N][MAX_N];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<string> S(n);
    for (int i=0;i<n;++i) cin >> S[i];
    for (int mask=1;mask<(1<<n);++mask){
        int flag=__builtin_popcount(mask);
        for (int j=0;j<n;++j){
            for (int bit=0;bit<(1<<(flag-1));++bit){
                dp[mask][j].emplace_back(0);
            }
        }
    }
    for (int mask=0;mask<(1<<n);++mask){
        if (!mask){
            for (int j=0;j<n;++j) dp[mask|1<<j][j][0]=1;
            continue;
        }
        int flag=__builtin_popcount(mask);
        for (int j=0;j<n;++j){
            for (int bit=0;bit<(1<<(flag-1));++bit){
                if (dp[mask][j][bit]==0) continue;
                for (int k=0;k<n;++k){
                    if (!(mask&1<<k)){
                        dp[mask|1<<k][k][(bit<<1)|(S[j][k]-'0')]+=dp[mask][j][bit];
                    }
                }
            }
        }
    }
    vector<ll> ans(1<<(n-1),0);
    for (int j=0;j<n;++j){
        for (int mask=0;mask<(1<<(n-1));++mask){
            ans[mask]+=dp[(1<<n)-1][j][mask];
        }
    }
    for (int mask=0;mask<(1<<(n-1));++mask) cout << ans[mask] << (mask+1==(1<<(n-1))?'\n':' ');
}