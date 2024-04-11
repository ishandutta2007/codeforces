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

const int MX = 2005, M = 5005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n;
int a[MX];
ll dp[3][M];
int d[M];

int main() {
  scanf("%d",&n);
  rep(i,n) scanf("%d",&a[i]);
  sort(a,a+n);
  rep(i,n)rep(j,n) if (i != j && a[i] < a[j]) {
    d[a[j]-a[i]]++;
  }
  rep(i,5003) dp[0][i] = d[i];
  rep(i,2)rep(j,M) {
    rep(k,M) {
      if (j-k <= 0) break;
      dp[i+1][j-k] += dp[i][j]*d[k];
    }
    // cout<<j<<" "<<dp[i][j]<<endl;
  }
  ll sum = 0;
  rep(i,M) sum += dp[2][i];
  // cout<<sum<<endl;
  ll t = n*(n-1)/2;
  double ans = sum*1./t/t/t;
  printf("%.10f\n", ans);
  return 0;
}