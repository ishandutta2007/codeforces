#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v){for(T&x:v)i>>x;return i;}
template<typename T>string join(vector<T>&v){stringstream s;for(T&x:v)s<<' '<<x;return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v){o<<join(v);return o;}

const int MX = 205, M = 1005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// Mod int
const int mod = 1000000007;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  mint operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
//

mint dp[2][MX/2][M];

int a[MX];

int main() {
  int n, m;
  scanf("%d%d",&n,&m);
  rep(i,n) scanf("%d",&a[i]);
  sort(a,a+n);
  int o = 0, p = 1;
  int n1 = n/2+1;
  dp[o][0][0] = 1;
  rep(i,n) {
    int d = 0;
    if (i) d = a[i]-a[i-1];
    rep(j,n1)rep(k,m+1) dp[p][j][k] = 0;
    rep(j,n1)rep(k,m+1) if (k+j*d <= m) {
      int nk = k+j*d;
      dp[p][j][nk] += dp[o][j][k];
      dp[p][j+1][nk] += dp[o][j][k];
      if (j) {
        dp[p][j][nk] += dp[o][j][k]*j;
        dp[p][j-1][nk] += dp[o][j][k]*j;
      }
    }
    swap(o,p);
  }
  mint ans = 0;
  rep(k,m+1) ans += dp[o][0][k];
  cout<<ans.x<<endl;
  return 0;
}