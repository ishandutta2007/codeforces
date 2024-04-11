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
const int sh = 1 << 18;
pair<int, int> rm1[sh * 2 + 10];
pair<int, int> rm2[sh * 2 + 10];
void upd(int x, int v) {
  pair<int, int> vv = mp(v, x);
  x += sh;
  while (x >= 1) {
    rm1[x] = max(rm1[x], vv);
    rm2[x] = min(rm2[x], vv);
    x /= 2;
  }
}
pair<int, int> get(int l, int r) {
  l += sh;
  r += sh;
  pair<int, int> mn = rm2[l];
  pair<int, int> mx = rm1[l];
  while (l <= r) {
    mn = min(mn, rm2[l]);
    mn = min(mn, rm2[r]);
    mx = max(mx, rm1[l]);
    mx = max(mx, rm1[r]);
    l = (l + 1) / 2;
    r = (r - 1) / 2;
  }
  return mp(mn.y, mx.y);
}
int a[2 * sh + 10];
int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  for (int i = 0; i <= 2 * sh + 1; i++) {
    rm1[i].x = -1;
    rm2[i].x = (int)1e7;
  }
  int n, m;      
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    upd(i, a[i]);
  }
  for (int i = 0; i < m; i++) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    l--, r--;
    pair<int, int> mxmn = get(l, r);
    if (a[mxmn.x] != x) {
      printf("%d\n", mxmn.x + 1);
    } else 
    if (a[mxmn.y] != x) {
      printf("%d\n", mxmn.y + 1);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}