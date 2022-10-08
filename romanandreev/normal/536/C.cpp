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
const ld eps = 1e-12;
struct pnt {
  ld x, y;
  int id;
  pnt() {
  }  
};
int n;
pnt p[1000100];
int ans[1000100];
int wans[1000100];

bool cmp(pnt a, pnt b) {
  if (fabs(a.y - b.y) > eps) {
    return a.y > b.y;
  }
  if (fabs(a.x - b.x) > eps) {
    return a.x > b.x;
  }
  return false;
}
bool eq(pnt a, pnt b) {
  return fabs(a.x - b.x) <= eps && fabs(a.y - b.y) <= eps;
}
ld inters(pnt a, pnt b) {
  ld c = (a.x - b.x) / (b.y - a.y);
  return c;
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int s, r;
    scanf("%d %d", &s, &r);
    p[i].x = (ld)1 / s;
    p[i].y = (ld)1 / r;
    p[i].id = i;
  }
  sort(p, p + n, cmp);
  vector<pnt> st;
  pnt inf;
  inf.x = 2;
  inf.y = 2;
  inf.id = n;
  st.pb(inf);
  for (int i = 0; i < n; i++) {
    wans[i] = n;      
    ans[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (eq(st[sz(st) - 1], p[i])) {
      wans[p[i].id] = st[sz(st) - 1].id;
      continue;
    }
    while (sz(st) >= 2 && inters(st[sz(st) - 2], st[sz(st) - 1]) > inters(st[sz(st) - 2], p[i]) + eps) {
      st.pop_back();
    }
    st.pb(p[i]);
  }
  for (int i = 1; i < sz(st); i++) {      
    if (inters(st[i - 1], st[i]) >= eps) {
      ans[st[i - 1].id] = 1;
      ans[st[i].id] = 1;
    }
  }
  ans[st[sz(st) - 1].id] = 1;
  for (int i = 0; i < n; i++) {
    if (wans[i] != n) {
      ans[i] = ans[wans[i]];
    }
  }
  for (int i = 0; i < n; i++) {
    if (ans[i]) {
      printf("%d ", i + 1);
    }
  }
  return 0;
}