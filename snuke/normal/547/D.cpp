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
int c[MX*2], deg[MX*2];
vi to[MX*2], id[MX*2];
string ans;

inline char f(char c) { return 'r'-c+'b';}

int r;
char dfs(int v) {
  while (c[v] < sz(to[v])) {
    int u = to[v][c[v]];
    int j = id[v][c[v]++];
    if (ans[j] != 'x') continue;
    ans[j] = 'o';
    deg[v]--; deg[u]--;
    char a = f(dfs(u));
    ans[j] = a;
    return a;
  }
  // if (r != -1 && r != v) puts("hoge");
  return 'r';
}

int main(){
  scanf("%d",&n);
  ans = string(n,'x');
  rep(i,n) {
    int x, y;
    scanf("%d%d",&x,&y);
    to[x].pb(MX+y); id[x].pb(i); deg[x]++;
    to[MX+y].pb(x); id[y+MX].pb(i); deg[y+MX]++;
  }
  int m = MX*2;
  rep(i,m) {
    if (deg[i]&1) {
      r = -1;
      dfs(i);
    }
  }
  rep(i,m) r = i, dfs(i);
  cout << ans << endl;
  return 0;
}