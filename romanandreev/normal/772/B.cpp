#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}

const ld inf = 1e18;

struct pnt {
  ld x, y;
  pnt() {
  }
  pnt(ld _x, ld _y) : x(_x), y(_y) {
  }
};
pnt operator - (pnt a, pnt b) {
  return {a.x - b.x, a.y - b.y};
}
ld vp(pnt a, pnt b) {
  return a.x * b.y - a.y * b.x;
}
ld sqr(ld x) {
  return x * x;
}
ld dst(pnt a, pnt b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
ld calc(pnt a, pnt b, pnt c) {
  return vp(a - b, c - b) / dst(a, c) / 2;
}
void solve() {
  int n;
  cin >> n;
  vector<pnt> p(n);  
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  ld ans = inf;
  for (int i = 0; i < n; i++) {
    ans = min(ans, calc(p[i], p[(i + 1) % n], p[(i + 2) % n]));
  }
  printf("%.18lf\n", (double)ans);
}

int main(){
  #ifdef home
  assert(freopen("b.out","wt",stdout));
  assert(freopen("b.in","rt",stdin));
  #endif
  solve();
  return 0;
}