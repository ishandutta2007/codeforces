#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
int n, m;
const int maxn = 10000;
vector<int> g[maxn];
int d[maxn];
int q[maxn];
int cl[maxn];
int bfs(int v) {
  for (int i = 0; i < n; i++) {
    d[i] = maxn;
  }
  int l = 0;
  int r = 0;
  q[r++] = v;
  d[v] = 0;
  int res = 0;
  while (l < r) {
    int qv = q[l++];
    for (int i = 0; i < sz(g[qv]); i++) {
      int qe = g[qv][i];
      if (d[qe] == maxn) {
        d[qe] = d[qv] + 1;
        res = max(res, d[qe]);
        q[r++] = qe;
      }
    }
  }
  return res;
}
vector<int> ls;
void dfs(int v, int c) {
  cl[v] = c;
  ls.pb(v);
  for (int i = 0; i < sz(g[v]); i++) {
    int e = g[v][i];
    if (cl[e] == 0) {
      dfs(e, 3 - c);
    } else
    if (cl[e] != 3 - c) {
      printf("-1\n");
      exit(0);
    }
  }
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    g[x].pb(y);
    g[y].pb(x);
  }
  for (int i = 0; i < n; i++) {
    cl[i] = 0;
  }
  int nc = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) if (cl[i] == 0) { 
    nc++;
    ls.clear();
    dfs(i, 1);
    int cur = 0;
    for (int v : ls) {
      cur = max(cur, bfs(v));
    }
    ans += cur;
  }
  cout << ans << endl;    
  return 0;
}