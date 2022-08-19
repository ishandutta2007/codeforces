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

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n;
int p[MX];
vvi d;

void dfs(int v) {
  if (p[v] == -1) return;
  d.back().pb(v);
  int nx = p[v];
  p[v] = -1;
  dfs(nx);
}

void add(int a, int b) {
  printf("%d %d\n", a+1, b+1);
}

int main() {
  scanf("%d",&n);
  rep(i,n) scanf("%d",&p[i]);
  rep(i,n) p[i]--;
  rep(i,n) {
    if (p[i] == -1) continue;
    d.pb(vi());
    dfs(i);
  }
  int s = MX;
  rep(i,sz(d)) mins(s,sz(d[i]));
  if (s > 2) {
    puts("NO");
    return 0;
  }
  rep(i,sz(d)) if (sz(d[i])%s) {
    puts("NO");
    return 0;
  }
  puts("YES");
  int si = 0;
  rep(i,sz(d)) if (sz(d[i]) == s) si = i;
  if (s == 2) add(d[si][0],d[si][1]);
  rep(i,sz(d)) {
    if (i == si) continue;
    rep(j,sz(d[i])) {
      add(d[i][j],d[si][j%s]);
    }
  }
  return 0;
}