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
#define next next_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
const int maxn = 1e6 + 10;
int n;
int a[2 * maxn];
int next[2 * maxn];
int dp[2 * maxn];
int wh[2 * maxn];
int solve(ll b) {
  int r = 0;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    while (r - i < n && sum + a[r] <= b) {
      sum += a[r];
      r++;
    }    
    next[i] = r;
    next[i + n] = r + n;
    sum -= a[i];
  }
  int ans = n;
  for (int i = n - 1; i >= 0; i--) {
    if (next[i] >= n) {
      dp[i] = 1;
      wh[i] = next[i];
    } else {
      dp[i] = dp[next[i]] + 1;
      wh[i] = wh[next[i]];
    }
    if (wh[i] - n >= i) {
      ans = min(ans, dp[i]);
    }
  }
  return ans;
}
int main() {
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i + n] = a[i];
  }
  for (int it = 0; it < q; it++) {
    ll b;
    scanf("%I64d", &b);
    printf("%d\n", solve(b));
  }
//  cerr<<clock() * 1. / CLOCKS_PER_SEC<<endl;
  return 0;
}