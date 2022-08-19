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
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
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
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

double dp[MX], d[MX];

int main() {
  int n, m;
  scanf("%d%d",&m,&n);
  if (n == 1) {
    puts("1");
    return 0;
  }
  dp[1] = 1;
  int t = 2, sum = 0;
  rep(i,m) {
    int x;
    scanf("%d",&x);
    --x;
    sum += x;
    t += n-1;
    double s = 0;
    rep(j,t) s += dp[j], d[j] = s;
    drep(j,t) {
      dp[j] = (d[j] - d[max(j-n,0)] - dp[max(j-x,0)])/(n-1);
      // printf("%d %.10f %.10f\n", j, dp[j], d[j]);
    }
  }
  double ans = 1;
  rrep(i,sum) ans += dp[i]*(n-1);
  printf("%.10f\n", ans);
  return 0;
}