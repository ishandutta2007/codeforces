#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>

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
int a[1000];
int cur[1000];
int cur1[1000];
int was[1000];
int indeg[1000];

int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    cur[i] = a[i];
  }
  ll ans = 9e18;
  for (int d = 1; d <= 3 * n + 1; d++) {
    bool good = true;
    for (int i = 0; i < n; i++) {
      if (cur[cur[i]] != cur[i]) {
        good = false;
      }
    }
    if (good) {
      ans = min(ans, (ll)d);
    }
    for (int i = 0; i < n; i++) {
      indeg[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      indeg[a[cur[i]]]++;
    }
    good = true;
    for (int i = 0; i < n; i++) {
      if (indeg[cur[i]] == 0) {
        good = false;
      }
    }
    if (good) {
      ll nok = 1;
      for (int i = 0; i < n; i++) {
        was[i] = 0;
      }
      for (int i = 0; i < n; i++) if (was[cur[i]] == 0) {
        int cc = cur[i];
        int len = 0;
        while (was[cc] == 0) {
          was[cc] = 1;
          cc = a[cc];
          len++;
        }
        nok = nok / __gcd(nok, (ll)len) * len;
      }
      //cerr<<d + nok<<endl;
      ll xnok = nok;
      while (d > xnok) {
        xnok += nok;
      }
      ans = min(ans, xnok);
    }
    for (int i = 0; i < n; i++) {
      cur1[i] = a[cur[i]];
    }
    for (int i = 0; i < n; i++) {
      cur[i] = cur1[i];
    }
  }
  cout << ans << endl;
  return 0;
}