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
const int maxn = 200100;
int n;
int h[maxn];
int w[maxn];
int mxl[maxn];
int mxr[maxn];

int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d", &n);
  ll sum = 0;
  h[0] = h[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &w[i], &h[i]);
    sum += w[i];
  }
  mxl[0] = 0;
  for (int i = 1; i <= n + 1; i++) {
    mxl[i] = max(mxl[i - 1], h[i]);
  }
  mxr[n + 1] = 0;
  for (int i = n; i >= 0; i--) {
    mxr[i] = max(mxr[i + 1], h[i]);
  }
  for (int i = 1; i <= n; i++) {
    printf("%I64d%c", (sum - w[i]) * max(mxl[i - 1], mxr[i + 1]), " \n"[i == n]);
  }
  return 0;
}