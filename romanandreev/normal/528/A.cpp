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
int w, h, n;
char tp[1000000];
int wh[1000000];
int len1[1000000];
int len2[1000000];
int up1[1000000];
int up2[1000000];
ll ans[1000000];
int go(int* up, int x) {
  if (up[x] == x) return x;
  return up[x] = go(up, up[x]);
}
void unionn(multiset<int>& X, int* up, int* len, int x, int y) {
  x = go(up, x);
  y = go(up, y);
  X.erase(X.find(len[x]));
  X.erase(X.find(len[y]));
  len[x] += len[y];
  up[y] = x; 
  X.insert(len[x]);
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d %d\n", &w, &h, &n);
  for (int i = 0; i < n; i++) {
    scanf("%c %d\n", &tp[i], &wh[i]);
  }
  vector<int> dx, dy;
  dx.pb(0);
  dx.pb(w);
  dy.pb(0);
  dy.pb(h);
  for (int i = 0; i < n; i++) {
    if (tp[i] == 'V') {
      dx.pb(wh[i]);
    } else {
      dy.pb(wh[i]);
    }
  }
  sort(all(dx));
  sort(all(dy));
  multiset<int> X, Y;
  for (int i = 0; i + 1 < sz(dx); i++) {
    len1[i] = dx[i + 1] - dx[i];
    up1[i] = i;
    X.insert(len1[i]);
  }
  for (int i = 0; i + 1 < sz(dy); i++) {
    len2[i] = dy[i + 1] - dy[i];
    up2[i] = i;
    Y.insert(len2[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = ((ll)*X.rbegin()) * (*Y.rbegin());
    if (tp[i] == 'V') {
      int p = lower_bound(all(dx), wh[i]) - dx.begin();
      unionn(X, up1, len1, p - 1, p);
    } else {
      int p = lower_bound(all(dy), wh[i]) - dy.begin();
      unionn(Y, up2, len2, p - 1, p);
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%I64d\n", ans[i]);
  }
  return 0;
}