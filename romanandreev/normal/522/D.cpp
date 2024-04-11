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
const int sh = 1 << 19;
const int inf = (int)1e9;
const int maxv = 22 * sh;
const int maxn = 500100;
int kv;
int rm[maxv];
int L[maxv];
int R[maxv];
int a[maxn];
int root[maxn];
int change(int v, int l, int r, int p, int val) {
  if (l == r) {
    kv++;
    rm[kv] = val;
    return kv;
  }
  int m = (l + r) / 2;
  int nl = L[v];
  int nr = R[v];
  if (p <= m) {
    nl = change(nl, l, m, p, val);
  } else {
    nr = change(nr, m + 1, r, p, val);
  }
  kv++;
  L[kv] = nl;
  R[kv] = nr;
  rm[kv] = min(rm[nl], rm[nr]);
  return kv;
}
int get_min(int v, int l, int r, int l1, int r1) {
  if (l1 <= l && r <= r1) {
    return rm[v];
  }   
  int m = (l + r) / 2;
  int ans = inf;
  if (l1 <= m) {
    ans = min(ans, get_min(L[v], l, m, l1, min(r1, m)));
  }
  if (r1 > m) {
    ans = min(ans, get_min(R[v], m + 1, r, max(m + 1, l1), r1));
  }
  return ans;
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  map<int, int> pos;
  for (int i = 1; i < 2 * sh; i++) {
    rm[i] = inf;
  }
  for (int i = sh - 1; i >= 1; i--) {
    L[i] = i * 2;
    R[i] = i * 2 + 1;
  }
  kv = 2 * sh - 1;
  root[0] = 1;
  for (int i = 1; i <= n; i++) {
    int p = pos[a[i]];
    if (p == 0) {
      root[i] = root[i - 1];
    } else {
      root[i] = change(root[i - 1], 1, sh, p, i - p);
    }
    pos[a[i]] = i;
  }
//  cerr<<clock() * 1./CLOCKS_PER_SEC<<endl;
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    int ans = get_min(root[r], 1, sh, l, r);
    if (ans == inf) {
      ans = -1;
    }
    printf("%d\n", ans);
  }
//  cerr<<clock() * 1./CLOCKS_PER_SEC<<endl;
  return 0;
}