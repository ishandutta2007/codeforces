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

int n, m;
vi d[MX][2];
bool ok[MX];
string ans;
vi to[MX], id[MX];
bool used[MX];

queue<int> q;
void add(int v) {
  ok[v] = true;
  q.push(v);
}
bool dfs(int v, int pe=-1) {
  if (used[v]) return true;
  used[v] = true;
  rep(i,sz(to[v])) {
    int u = to[v][i];
    int e = id[v][i];
    if (pe == e) continue;
    if (dfs(u,e)) {
      add(v);
      ans[e] = '0';
      if (d[e][1][0] == v) ans[e]++;
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d%d",&m,&n);
  rep(i,m) {
    int cs;
    scanf("%d",&cs);
    rep(j,cs) {
      int a;
      scanf("%d",&a);
      if (a < 0) {
        a = -a; --a;
        d[a][0].pb(i);
      } else {
        --a;
        d[a][1].pb(i);
      }
    }
  }
  ans = string(n,'?');
  rep(i,n) {
    if (sz(d[i][0]) == 0) {
      rep(j,sz(d[i][1])) add(d[i][1][j]);
      ans[i] = '1';
    } else if (sz(d[i][1]) == 0) {
      rep(j,sz(d[i][0])) add(d[i][0][j]);
      ans[i] = '0';
    } else {
      to[d[i][0][0]].pb(d[i][1][0]); id[d[i][0][0]].pb(i);
      to[d[i][1][0]].pb(d[i][0][0]); id[d[i][1][0]].pb(i);
    }
  }
  rep(i,m) {
    while (sz(q)) {
      int v = q.front(); q.pop();
      rep(j,sz(to[v])) {
        int u = to[v][j];
        int e = id[v][j];
        if (ok[u]) continue;
        add(u);
        ans[e] = '0';
        if (d[e][1][0] == u) ans[e]++;
      }
    }
    if (ok[i]) continue;
    if (!dfs(i)) {
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  rep(i,n) if (ans[i] == '?') ans[i] = '0';
  cout<<ans<<endl;
  return 0;
}