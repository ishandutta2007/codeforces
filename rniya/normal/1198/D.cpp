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

template<typename T>
struct CumulativeSum2D{
    int H,W;
    vector<vector<T>> dat;
    CumulativeSum2D(vector<vector<T>> v){
        H=v.size(),W=v[0].size();
        dat.assign(H+1,vector<T>(W+1,0));
        for (int i=0;i<H;++i){
            for (int j=0;j<W;++j){
                dat[i+1][j+1]=v[i][j];
                dat[i+1][j+1]+=dat[i+1][j]+dat[i][j+1]-dat[i][j];
            }
        }
    }
    T query(int sx,int gx,int sy,int gy){ //[sx,gx),[sy,gy)
        return dat[gx][gy]-dat[sx][gy]-dat[gx][sy]+dat[sx][sy];
    }
};

const int MAX_N=55;
int dp[MAX_N][MAX_N][MAX_N][MAX_N];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<string> S(n); cin >> S;

    vector<vector<int>> v(n,vector<int>(n));
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            v[i][j]=(S[i][j]=='#');
        }
    }
    CumulativeSum2D<int> CS(v);

    for (int i=0;i<=n;++i){
        for (int j=0;j<=n;++j){
            for (int k=0;k<=n;++k){
                for (int l=0;l<=n;++l){
                    dp[i][j][k][l]=n;
                }
            }
        }
    }
    for (int i=0;i<=n;++i){
        for (int k=0;k<=n;++k){
            dp[i][i][k][k]=0;
        }
    }

    for (int j=0;j<=n;++j){
        for (int i=0;i+j<=n;++i){
            for (int l=0;l<=n;++l){
                for (int k=0;k+l<=n;++k){
                    chmin(dp[i][i+j][k][k+l],max(j,l));
                    if (j>=1&&CS.query(i,i+1,k,k+l)==0) chmin(dp[i][i+j][k][k+l],dp[i+1][i+j][k][k+l]);
                    if (j>=1&&CS.query(i+j-1,i+j,k,k+l)==0) chmin(dp[i][i+j][k][k+l],dp[i][i+j-1][k][k+l]);
                    if (l>=1&&CS.query(i,i+j,k,k+1)==0) chmin(dp[i][i+j][k][k+l],dp[i][i+j][k+1][k+l]);
                    if (l>=1&&CS.query(i,i+j,k+l-1,k+l)==0) chmin(dp[i][i+j][k][k+l],dp[i][i+j][k][k+l-1]);
                    for (int m=1;m<j;++m) chmin(dp[i][i+j][k][k+l],dp[i][i+m][k][k+l]+dp[i+m][i+j][k][k+l]);
                    for (int m=1;m<l;++m) chmin(dp[i][i+j][k][k+l],dp[i][i+j][k][k+m]+dp[i][i+j][k+m][k+l]);
                }
            }
        }
    }

    cout << dp[0][n][0][n] << '\n';
}