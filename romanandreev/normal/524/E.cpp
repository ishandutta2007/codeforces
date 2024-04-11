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
const int maxn = (int)2e5 + 10;
const int inf = (int)1e9;
const int sh = 1 << 18;
int rm[2 * sh + 10];
int n, m, k, q;
int x[maxn];
int y[maxn];
int x1[maxn];
int y1[maxn];
int x2[maxn];
int y2[maxn];
bool ans[maxn];
vector<int> sob[maxn];
void rotate_world() {
  swap(n, m);
  for (int i = 0; i < k; i++) {
    swap(x[i], y[i]);
  }
  for (int i = 0; i < q; i++) {
    swap(x1[i], y1[i]);
    swap(x2[i], y2[i]);
  }
}
void upd(int x, int val) {
  x += sh;
  rm[x] = val;
  while(x > 1) {
    x /= 2;
    rm[x] = max(rm[x * 2], rm[x * 2 + 1]);
  }
}
int get_max(int l, int r) {
  l += sh;
  r += sh;
  int ans = -1;
  while(l <= r) {
    ans = max(rm[l], ans);
    ans = max(rm[r], ans);
    l = (l + 1) / 2;
    r = (r - 1) / 2;
  }
  return ans;
}
void solve() {
  for (int i = 1; i <= n; i++) {
    sob[i].clear();
  } 
  for (int i = 0; i < k; i++) {
    sob[x[i]].pb(-i - 1);
  }
  for (int i = 0; i < q; i++) {
    sob[x1[i]].pb(i);
  }
  for (int i = 1; i <= 2 * sh; i++) {
    rm[i] = inf;
  }
  for (int i = n; i >= 1; i--) {
    sort(all(sob[i]));
    for (int j = 0; j < sz(sob[i]); j++) {
      if (sob[i][j] < 0) {
        int v = -sob[i][j] - 1;
        upd(y[v], x[v]);
      } else {
        int v = sob[i][j];
        if (get_max(y1[v], y2[v]) <= x2[v]) {
          ans[v] = true;
        }
      }
    }
  }
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d %d %d", &n, &m, &k, &q);
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
  }
  solve();
  rotate_world();
  solve();
  for (int i = 0; i < q; i++) {
    printf(ans[i] ? "YES\n" : "NO\n");
  }

  return 0;
}