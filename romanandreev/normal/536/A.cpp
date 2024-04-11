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
bool can(ll k, ll S, ll t, ll m, ll B) {
  m = min(m, k);
  if (S * k + k * (k - 1) / 2 * B > t * m || S + (k - 1) * B > t) return false;
  return true;
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  int A, B, n;
  scanf("%d %d %d", &A, &B, &n);
  for (int i = 0; i < n; i++) {
    int l, t, m;
    scanf("%d %d %d", &l, &t, &m);
    ll S = A + (ll)(l - 1) * B;
    if (S > t) {
      printf("-1\n");
      continue;
    }
    ll L = 1;
    ll R = t;
    while (L < R) {
      ll M = (L + R + 1) / 2;
      if (can(M, S, t, m, B)) {
        L = M;
      } else {
        R = M - 1;
      }
    }    


    printf("%lld\n", l + L - 1);
  }
  return 0;
}