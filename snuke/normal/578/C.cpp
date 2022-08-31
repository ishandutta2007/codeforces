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
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 200005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n;
int a[MX];

double f(double x) {
  double s = 0, ma = 0, mi = 0, res = 0;
  rep(i,n) {
    double y = a[i]-x;
    s += y;
    maxs(res,abs(s-mi));
    maxs(res,abs(s-ma));
    mins(mi,s);
    maxs(ma,s);
  }
  return res;
}

int main() {
  scanf("%d",&n);
  rep(i,n) scanf("%d",&a[i]);
  double l = -20005;
  double r = 20005;
  rep(ti,100) {
    double c1 = (l*2+r)/3;
    double c2 = (l+r*2)/3;
    double d1 = f(c1);
    double d2 = f(c2);
    if (d1 > d2) l = c1;
    else r = c2;
  }
  printf("%.10f\n", f(l));
  return 0;
}