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
void upd(vector<int>& r, int sh, int pos, int val) {
  int x = pos + sh;
  while (x >= 1) {
    r[x] += val;
    x /= 2;
  }
}
int get(vector<int>& r, int sh, int pos) {
  int lf = 0 + sh;
  int rg = pos + sh;
  int res = 0;
  while (lf <= rg) {
    if (lf % 2 == 1) {
      res += r[lf];
    }
    if (rg % 2 == 0) {
      res += r[rg];
    }
    lf = (lf + 1) / 2;
    rg = (rg - 1) / 2;
  }
  return res;
}
int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  int n;            
  scanf("%d", &n);
  vector<int> tp(n);
  vector<int> t(n);
  vector<int> x(n);  
  map<int, vector<int>> ls;
  map<int, vector<int>> rmq;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &tp[i], &t[i], &x[i]);
    ls[x[i]].pb(t[i]);
  }
  for (auto& p : ls) {
    image(p.y);
    int s = 1;
    while (s < sz(p.y)) {
      s *= 2;
    }
    rmq[p.x] = vector<int>(2 * s + 3, 0);
  }
  for (int i = 0; i < n; i++) {
    vector<int>& cls = ls[x[i]];
    vector<int>& crmq = rmq[x[i]];
    int s = (sz(crmq) - 3) / 2;
    if (tp[i] == 1) {
      upd(crmq, s, lower_bound(all(cls), t[i]) - cls.begin(), 1);
    } else
    if (tp[i] == 2) {
      upd(crmq, s, lower_bound(all(cls), t[i]) - cls.begin(), -1);
    } else {
      printf("%d\n", get(crmq, s, lower_bound(all(cls), t[i]) - cls.begin()));
    }
  }
  return 0;
}