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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<string> digit={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
    vector<int> num(10,0);
    for (int i=0;i<10;++i){
        for (int j=0;j<7;++j){
            num[i]|=(digit[i][j]-'0')<<j;
        }
    }
    int MAX_D=1<<7;
    vector<vector<int>> calc(MAX_D,vector<int>(10,0));
    for (int i=0;i<MAX_D;++i){
        for (int j=0;j<10;++j){
            int ok=1;
            for (int k=0;k<7;++k){
                if ((i&1<<k)&&!(num[j]&1<<k)) ok=0;
                if (!(i&1<<k)&&(num[j]&1<<k)) ++calc[i][j];
            }
            if (!ok) calc[i][j]=-1;
        }
    }
    int n,k; cin >> n >> k;
    vector<string> S(n); cin >> S;
    vector<vector<int>> dp(n,vector<int>(8,-1));
    for (int i=0;i<n;++i){
        int con=0;
        for (int j=0;j<7;++j){
            con|=(S[i][j]-'0')<<j;
        }
        for (int j=0;j<10;++j){
            if (~calc[con][j]){
                dp[i][calc[con][j]]=j;
            }
        }
    }
    vector<vector<int>> suf(n+1,vector<int>(k+1,0));
    suf[n][0]=1;
    for (int i=n-1;i>=0;--i){
        for (int j=0;j<=7;++j){
            if (~dp[i][j]){
                for (int l=0;l<=k;++l){
                    if (l+j<=k) suf[i][l+j]|=suf[i+1][l];
                }
            }
        }
    }
    string ans="";
    int now=0;
    for (int i=0;i<n;++i){
        int nxt=-1,M=-1;
        for (int j=0;j<=7;++j){
            if (k-now-j>=0&&suf[i+1][k-now-j]){
                if (chmax(M,dp[i][j])) nxt=j;
            }
        }
        if (nxt<0){
            cout << -1 << '\n';
            return 0;
        }
        now+=nxt; ans+=(char)('0'+M);
    }
    cout << ans << '\n';
}