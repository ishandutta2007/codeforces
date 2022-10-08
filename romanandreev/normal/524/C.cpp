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

int n, k, q;
const int MX = (int)1e7 + 10;
int was[MX];
int a[10000];
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    was[a[i]] = 1;
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    int ans = k + 1;
    for (int j = 0; j < n; j++) {
      for (int k1 = 1; k1 <= k; k1++) {
        if (x == a[j] * k1) {
          ans = min(ans, k1);
        }
        if (x > a[j] * k1) {
          int val = x - a[j] * k1;
          for (int k2 = 1; k2 + k1 <= k; k2++) {
            if (val % k2 == 0 && val / k2 < MX && was[val / k2] == 1) {
              ans = min(ans, k1 + k2);
            }
          }
        }
      }
    }
    printf("%d\n", ans > k ? -1 : ans);
  }
  return 0;
}