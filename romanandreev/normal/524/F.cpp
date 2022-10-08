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
const int maxn = (int)2e6 + 10;
const int inf = (int)1e9;
const int P[] = {(int)1e9 + 7, (int)1e9 + 9};
const int Q[] = {17, 239};
int stp[2][maxn];
int h[2][maxn];
int h1[2][maxn];
int h2[2][maxn];
const int sh = 1 << 21;
int rm[2 * sh + 10];
void upd(int x, int val) {
  x += sh;
  rm[x] = val;
  while (x > 1) {
    x /= 2;
    rm[x] = min(rm[x * 2], rm[x * 2 + 1]);
  }
}
int get_min(int l, int r) {
  l += sh;
  r += sh;
  int ans = inf;
  while(l <= r) {
    ans = min(rm[l], ans);
    ans = min(rm[r], ans);
    l = (l + 1) / 2;
    r = (r - 1) / 2;
  }
  return ans;
}
char s[maxn];
int n;
int sum[maxn];
void print(pair<int, pair<int, int> > ans) {
  for (int j = 0; j < ans.x; j++) {
    printf("(");
  }
  for (int j = 0; j < n; j++) {
    printf("%c", s[ans.y.x + j]);
  }
  for (int j = 0; j < ans.y.y; j++) {
    printf(")");
  }
  printf("\n");
}
int get_c(const pair<int, pair<int, int> >& a, int l) {
  if (l < a.x) return -1;
  if (l < a.x + n) {
    return s[a.y.x + l - a.x] == '(' ? -1 : 1;
  }
  return 1;
}
pair<int, int> get_hash(const pair<int, pair<int, int> >& a, int l) {
  if (l <= a.x) {
    return mp(h1[0][l], h1[1][l]);
  }
  if (l <= a.x + n) {
    int l2 = l - a.x;
    pair<int, int> H1 = mp(h1[0][a.x], h1[1][a.x]);
    pair<int, int> H2 = mp(((h[0][a.y.x] - (ll)h[0][a.y.x + l2] * stp[0][l2]) % P[0] + P[0]) % P[0],
                           ((h[1][a.y.x] - (ll)h[1][a.y.x + l2] * stp[1][l2]) % P[1] + P[1]) % P[1]);
    return mp((H1.x + (ll)H2.x * stp[0][a.x]) % P[0],
              (H1.y + (ll)H2.y * stp[1][a.x]) % P[1]);
  }
  {
    int l2 = l - a.x - n;
    pair<int, int> H1 = get_hash(a, a.x + n);
    pair<int, int> H2 = mp(h2[0][l2], h2[1][l2]);;
    return mp((H1.x + (ll)H2.x * stp[0][a.x + n]) % P[0],
              (H1.y + (ll)H2.y * stp[1][a.x + n]) % P[1]);
 }      
}
bool super_less(const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b) {
  if (a.x + a.y.y != b.x + b.y.y) {
    return a.x + a.y.y < b.x + b.y.y;
  }
  int l = 0;
  int r = a.x + a.y.y + n;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (get_hash(a, m) == get_hash(b, m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  if (r == a.x + a.y.y + n) {
    return false;
  }
  return get_c(a, l) < get_c(b, l);
}
int main() {
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%s", s);
  n = strlen(s);


  for (int i = 0; i < n; i++) {
    s[i + n] = s[i];
  }

  stp[0][0] = 1;
  stp[1][0] = 1;
  for (int j = 0; j < 2; j++) {
    for (int i = 1; i <= 2 * n; i++) {
      stp[j][i] = ((ll)stp[j][i - 1] * Q[j]) % P[j];
    }
  }

  for (int j = 0; j < 2; j++) {
    h[j][2 * n] = 0;
    for (int i = 2 * n - 1; i >= 0; i--) {
      h[j][i] = ((ll)h[j][i + 1] * Q[j] + (s[i] == '(' ? 1 : 2)) % P[j];
    }
  }

  for (int j = 0; j < 2; j++) {
    h1[j][0] = 0;
    h2[j][0] = 0;
    for (int i = 1; i <= 2 * n; i++) {
      h1[j][i] = ((ll)h1[j][i - 1] * Q[j] + 1) % P[j];
      h2[j][i] = ((ll)h2[j][i - 1] * Q[j] + 2) % P[j];
    }
  }

  sum[0] = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == '(') {
      sum[i + 1] = sum[i] + 1;
    } else {
      sum[i + 1] = sum[i] - 1;
    }
  }
  for (int i = 0; i <= 2 * n; i++) {
    upd(i, sum[i]);
  }

  pair<int, pair<int, int> > ans = mp(inf, mp(0, inf));
  for (int i = 0; i < n; i++) {
    int mn = min(0, get_min(i, i + n) - sum[i]);
    int add_beg = abs(mn);
    int add_end = sum[i + n] + add_beg - sum[i]; 
    //int len = add_beg + n + add_end;
    pair<int, pair<int, int> > res = mp(add_beg, mp(i, add_end));
    if (super_less(res, ans)) {
      ans = res;
    }
  }
  print(ans);
  return 0;
}