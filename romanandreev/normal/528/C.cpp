#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

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
vector<int> ans;
vector<pair<int, int> > g[1000000];
int was[1000000];
int st[1000000];
void go(int v) {
  while (st[v] < sz(g[v])) {
    int i = st[v]++;
    if (was[g[v][i].y] == 0) {
      was[g[v][i].y] = 1;                     
      go(g[v][i].x);
    }
  }
  ans.pb(v + 1);
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
    g[x].pb(mp(y, i));
    g[y].pb(mp(x, i));
  }
  int k = m;      
  vector<int> nec;
  for (int i = 0; i < n; i++) {
    if (sz(g[i]) % 2 == 1) {
      nec.pb(i);
    }
  }
  for (int i = 0; i < sz(nec); i += 2) {
    g[nec[i]].pb(mp(nec[i + 1], k));
    g[nec[i + 1]].pb(mp(nec[i], k));
    k++;
  }
  if (k % 2 == 1) {
    g[0].pb(mp(0, k));
    g[0].pb(mp(0, k));
    k++;
  }
  go(0);
  printf("%d\n", k);
  for (int i = 0; i + 1 < sz(ans); i++) {
    if (i % 2 == 0)
      printf("%d %d\n", ans[i], ans[(i + 1) % sz(ans)]);
    else
      printf("%d %d\n", ans[(i + 1) % sz(ans)], ans[i]);
  }
  return 0;
}