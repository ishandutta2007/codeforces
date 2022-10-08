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
int n;
int x[1000000];
int w[1000000];
int X[1000000];
int Y[1000000];
const int sh = 1 << 19;
vector<int> xx;
int rm[2 * sh + 10];
const int inf = (int)2e9;
int findd(int x) {
  return lower_bound(all(xx), x) - xx.begin();
} 
int get(int l, int r) {
  l = findd(l);
  r = findd(r);
  l += sh;
  r += sh;
  int res = 0;
  while (l <= r) {
    res = max(res, rm[l]);
    res = max(res, rm[r]);
    l = (l + 1) / 2;
    r = (r - 1) / 2;
  }
  return res;
}
void upd(int l, int v) {
  l = findd(l);
  l += sh;
  while (l >= 1) {
    rm[l] = max(rm[l], v);
    l = l / 2;
  }
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d", &n);
  vector<pair<int, int> > ls;

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &w[i]);
    X[i] = x[i] - w[i];
    Y[i] = x[i] + w[i];
    ls.pb(mp(x[i], i));
    xx.pb(X[i]);
    xx.pb(Y[i]);
  }
  sort(all(xx));
  sort(all(ls));
  int ans = 0;
  for (int ii = n - 1; ii >= 0; ii--) {
    int i = ls[ii].y;
    int res = get(Y[i], inf) + 1;
    ans = max(ans, res);
    upd(X[i], res);
  }
  printf("%d\n", ans);
  return 0;
}