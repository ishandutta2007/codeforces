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
int m, k;
const int maxn = 110000;
int a0[maxn];
int a1[maxn];
int a[maxn];
int t[maxn];
int r[maxn];
bool ans[maxn];
bool future[maxn];
void solve() {
  scanf("%d %d", &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &a0[i]);
    a[i] = a0[i];
  }
  int x = 0;
  int borm = m;
  for (int i = 1; i <= m - 1; i++) {
    scanf("%d %d", &t[i], &r[i]);
    if (t[i] != 0) {
      a[t[i]]--;
    } else {
      x++;
    }
    if (r[i] == 1) {
      borm = min(borm, i);
    }
  }
  for (int i = 1; i <= k; i++) {
    ans[i] = false;
  }
  if (borm < m) {
    for (int i = 1; i <= k; i++) {    
      future[i] = false;
    }
    for (int i = borm; i <= m - 1; i++) if (t[i] != 0) {
      future[t[i]] = true;
    }
    for (int i = 1; i <= k; i++) {
      a1[i] = a0[i];
    }
    int x1 = 0;
    for (int i = 1; i < borm; i++) if (t[i] != 0) {
      a1[t[i]]--;
    } else {
      x1++;
    }
    int mn = (int)1e9;
    for (int i = 1; i <= k; i++) if (future[i] == false) {
      if (a1[i] <= x1) {
        ans[i] = true;
      }
      mn = min(mn, a1[i]);
    }
    assert(mn <= x1);
    x -= mn;
  }
  for (int i = 1; i <= k; i++) {
    ans[i] |= (a[i] <= x);
  }
  for (int i = 1; i <= k; i++) {
    printf("%c", ans[i] ? 'Y' : 'N');
  }
  printf("\n");
}

int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  int T;
  scanf("%d", &T);
  for (int ti = 0; ti < T; ti++) {
    solve();
  }
  return 0;
}