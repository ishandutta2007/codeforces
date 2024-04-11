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

int n, q;
int x[MX], coa[MX];
P p[MX];

int main() {
  scanf("%d%d",&n,&q);
  rep(i,n) scanf("%d",&x[i]);
  rep(i,n) p[i] = P(x[i],i);
  sort(p,p+n);
  sort(x,x+n);
  rep(i,n) coa[p[i].se] = i;
  rep(qi,q) {
    int a, l;
    scanf("%d%d",&a,&l);
    // cerr << x[a] << endl;
    --a;
    a = coa[a];
    int ans = 0;
    while (1) {
      int b = upper_bound(x,x+n,x[a]+l)-x-1;
      int lb = l-(x[b]-x[a]);
      int c = lower_bound(x,x+n,x[b]-lb)-x;
      if (b == c) {
        ans = b;
        break;
      }
      if (c == a) {
        int r = x[b]-x[a];
        int rt = l/r;
        l %= r;
        if (rt&1) {
          a = lower_bound(x,x+n,x[b]-l)-x;
          l -= x[b]-x[a];
        } else 1;//do nothing
      } else {
        a = c;
        l = lb-(x[b]-x[c]);
      }
    }
    ans = p[ans].se;
    printf("%d\n", ans+1);
  }
  return 0;
}