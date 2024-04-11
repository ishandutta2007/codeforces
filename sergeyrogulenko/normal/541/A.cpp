#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>
#include <complex>
#include <iomanip>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

int n, m, k;
int t[8000000], l1[500000], r1[500000], l2[500000], r2[500000], w[500000], ans[500000], ans_id[500000];
pair<int, int> md[8000000];

void md_update(int idx, int l, int r, int pos, pair<int, int> val) {
  if (l == r) {
    md[idx] = max(md[idx], val);
    return;
  }

  int mid = (l + r) >> 1;
  if (pos <= mid) 
    md_update(idx << 1, l, mid, pos, val);
  else
    md_update(idx << 1 | 1, mid + 1, r, pos, val);

  md[idx] = max(md[idx << 1], md[idx << 1 | 1]);
}

pair<int, int> md_max(int idx, int l, int r, int a, int b) {
  pair<int, int> res(-INF, -INF);
  if (r < a || b < l)
    return res;
  if (a <= l && r <= b)
    return md[idx];

  int mid = (l + r) >> 1;
  res = max(res, md_max(idx << 1, l, mid, a, b));
  res = max(res, md_max(idx << 1 | 1, mid + 1, r, a, b));

  return res;
}

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  cin >> n >> m;
  forn(i, n)
    scanf("%d%d", &l1[i], &r1[i]);
  forn(i, m)
    scanf("%d%d%d", &l2[i], &r2[i], &w[i]);

  forn(i, n) {
    t[k++] = l1[i];
    t[k++] = r1[i];
  }
  forn(i, m) {
    t[k++] = l2[i];
    t[k++] = r2[i];
  }

  sort(t, t + k);
  k = int(unique(t, t + k) - t);

  forn(i, n) {
    l1[i] = int(lower_bound(t, t + k, l1[i]) - t);
    r1[i] = int(lower_bound(t, t + k, r1[i]) - t);
  }
  forn(i, m) {
    l2[i] = int(lower_bound(t, t + k, l2[i]) - t);
    r2[i] = int(lower_bound(t, t + k, r2[i]) - t);
  }

  vector<pair<int, pair<int, int> > > ev;
  forn(i, n) {
    ev.pb(mp(l1[i], mp(-1, i)));
    ev.pb(mp(r1[i], mp(2, i)));
  }
  forn(i, m) {
    ev.pb(mp(l2[i], mp(0, i)));
    ev.pb(mp(r2[i], mp(1, i)));
  }

  sort(all(ev));

  set<pair<int, int> > opl, opr;

  forn(i, ev.size()) {
    int tp = ev[i].sc.fs;
    int id = ev[i].sc.sc;

    if (tp == -1) {
      opr.insert(mp(-r1[id], id));
      opl.insert(mp(l1[id], id));
      continue;
    }
    if (tp == 2) {
      opr.erase(mp(-r1[id], id));
      opl.erase(mp(l1[id], id));
      md_update(1, 0, k - 1, l1[id], mp(t[r1[id]] - t[l1[id]], id));
      continue;
    }
    if (tp == 0) {
      if (opr.size()) {
        int cid = opr.begin()->sc;
        int clen = t[min(r1[cid], r2[id])] - t[l2[id]];
        if (clen > ans[id]) {
          ans[id] = clen;
          ans_id[id] = cid;
        }
      }
      continue;
    }

    if (opl.size()) {
      int cid = opl.begin()->sc;
      int clen = t[r2[id]] - t[max(l1[cid], l2[id])];
      if (clen > ans[id]) {
        ans[id] = clen;
        ans_id[id] = cid;
      }
    }

    pair<int, int> ft = md_max(1, 0, k - 1, l2[id], r2[id]);
    if (ft > mp(ans[id], ans_id[id])) {
      ans[id] = ft.fs;
      ans_id[id] = ft.sc;
    }
  }

  int64 res = 0;
  int ans1, ans2;
  forn(i, m) {
    int64 c = ans[i] * int64(w[i]);
    if (c > res) {
      res = c;
      ans1 = ans_id[i];
      ans2 = i;
    }
  }

  cout << res << endl;
  if (res > 0)
    cout << ans1 + 1 << ' ' << ans2 + 1 << endl;

  return 0;
}