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
typedef pair<double,int> DP;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 1005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n;
double p[MX][MX];
bool used[MX];
double d[MX];
double l[MX], r[MX];

int main() {
  scanf("%d",&n);
  rep(i,n)rep(j,n) {
    int a;
    scanf("%d",&a);
    p[i][j] = 0.01*a;
  }
  rep(i,n) d[i] = 1e20;
  rep(i,n) l[i] = 0, r[i] = 1;
  d[n-1] = 0;
  while (1) {
    DP np(1e20,-1);
    rep(i,n) if (!used[i] && d[i] < 1e19) mins(np, DP(d[i],i));
    if (np.se == -1) break;
    int v = np.se;
    // cout<<d[v]<<" "<<v<<endl;
    used[v] = true;
    rep(i,n) if (!used[i] && p[i][v] > eps) {
      l[i] += r[i]*p[i][v]*(d[v]+1);
      r[i] -= r[i]*p[i][v];
      d[i] = (l[i]+r[i])/(1-r[i]);
    }
  }
  printf("%.10f\n", d[0]);
  return 0;
}