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

ll dp[1<<13][13];
ll d[1<<13][13];

int e[13];
vi p[13];

int main() {
  int n,m,q;
  scanf("%d%d%d",&n,&m,&q);
  rep(i,m) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a; --b;
    e[a] |= 1<<b;
    e[b] |= 1<<a;
  }
  rep(i,q) {
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    --a; --b; --c;
    p[c].pb((1<<a)|(1<<b));
  }
  rep(i,n) d[1<<i][i] = 1;
  bool ok;
  int n2 = (1<<n)-1;
  rep(i,1<<n)rep(j,n)if(i>>j&1) {
    if (i == n2 && j != 0) continue;
    // if (i != n2 && j == 0) continue;
    int s = i^(1<<j);
    int ms = 1;
    while (ms <= s) ms <<= 1;
    ms >>= 1;
    for (int l = s; l && l >= ms; l = (l-1)&s) {
      int r = i^l;
      rep(k,n) if(l>>k&1) {
        ok = true;
        for (int f : p[j]) if ((l&f) == f) { ok = false; break;}
        if (!ok) continue;
        if ((l^(1<<k))&e[j]) continue;
        if (((l|1<<j)&e[k]) != e[k]) continue;
        // printf("%d %d\n", ((l|1<<j)&e[k]), e[k]);
        d[i][j] += d[r][j]*dp[l][k];
        // printf("%d %d: %I64d %I64d, %d %d %d\n", i,j,dp[i][j],d[i][j],l,k,r);
      }
    }
    // ok = ((i&e[j]) == e[j]);
    ok = true;
    for (int f : p[j]) if ((i&f) != f) { ok = false; break;}
    if (ok) dp[i][j] = d[i][j];
    // printf("%d %d: %I64d %I64d\n", i,j,dp[i][j],d[i][j]);
  }
  cout<<dp[(1<<n)-1][0]<<endl;
  return 0;
}