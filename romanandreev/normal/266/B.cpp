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
const int maxn = 1e6 + 10;
char s[maxn];
int was[maxn];
int n, T;
vector<int> pos;
int calc(int cur) {
  int l = 0;
  int r = sz(pos) - 1;
  while (l < r) {
    int m = (l + r + 1) / 2;
    int T1 = cur - pos[m] + sz(pos) - m;
    if (T > T1) {
      r = m - 1;
    } else {
      l = m;
    }
  }
  {
    int T1 = cur - pos[l] + sz(pos) - l;
    return max(pos[l], pos[l] - 1 + T1 - T);
  }
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d", &n, &T);
  scanf("%s", s);
  int kf = 0;
  int ADD = 0;
  pos.pb(-(int)1e9);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      if (sz(pos) > 1) {
        pos.pop_back();
      }      
    } else {
      kf++;
      if (kf == i + 1) {
        was[i] = 1;
        continue;
      }
      ADD++;
      was[max(kf - 1, calc(i - ADD) + ADD)] = 1;
      pos.pb(i - ADD);
    }
  }
  for (int i = 0; i < n; i++) {
    if (was[i] == 1) {
      printf("G");
    } else {
      printf("B");
    }
  }
  return 0;
}