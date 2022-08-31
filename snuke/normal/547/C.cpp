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

const int MX = 500005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n, q;
int a[MX];
ll c[MX];
vi d[MX];

int main(){
  for (int i = 1; i < MX; ++i) {
    for (int j = i; j < MX; j += i) d[j].pb(i);
  }
  scanf("%d%d",&n,&q);
  rep(i,n) scanf("%d",&a[i]);
  ll ans = 0, cnt = 0;
  rep(qi,q) {
    int p;
    scanf("%d",&p); --p;
    int x = abs(a[p]);
    int h = 1;
    vi s(sz(d[x]));
    if (a[p] > 0) {
      drep(i,sz(d[x])) {
        s[i] = c[d[x][i]];
        for (int j = i+1; j < sz(d[x]); ++j) {
          if (d[x][j]%d[x][i] == 0) s[i] -= s[j];
        }
      }
      ans += s[0];
      for (int y : d[x]) c[y]++;
      cnt++;
    } else {
      for (int y : d[x]) c[y]--;
      cnt--;
      drep(i,sz(d[x])) {
        s[i] = c[d[x][i]];
        for (int j = i+1; j < sz(d[x]); ++j) {
          if (d[x][j]%d[x][i] == 0) s[i] -= s[j];
        }
      }
      ans -= s[0];
    }
    a[p] *= -1;
    printf("%I64d\n", ans);
  }
  return 0;
}