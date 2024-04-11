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
map<int, set<int> > g;
int k;
bool good(int x, int y) {
  if (g[x].find(y) != g[x].end() || x == y) {
    return false;
  }
  int c1 = sz(g[x]);
  int c2 = 0;
  for (const auto d : g[x]) {
    if (g[y].find(d) != g[y].end()) {
      c2++;
    }
  }
  return c2 * 100 >= k * c1;
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  int m;
  scanf("%d %d", &m, &k);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].insert(y);
    g[y].insert(x);
  }
  for (const auto& v : g) {
    vector<int> ans;
    for (const auto& d : g) {
      if (good(v.x, d.x)) {
        ans.pb(d.x);
      }
    }
    sort(all(ans));
    printf("%d: %d", v.x, sz(ans));
    for (int i = 0; i < sz(ans); i++) {
      printf(" %d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}