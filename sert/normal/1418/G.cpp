#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Rect {
  int y, x, yy, xx;
  Rect(int y = 0, int x = 0, int yy = 0, int xx = 0): y(y), x(x), yy(yy), xx(xx) {};
};

struct ST {
  vector<int> mn;
  vector<int> numMn;
  vector<int> ad;
  int sz;

  ST(int sz) {
    this->sz = sz;
    mn.resize(sz * 4);
    numMn.resize(sz * 4);
    ad.resize(sz * 4);
    for (int i = 0; i < sz * 4; i++) {
      mn[i] = 0;
      numMn[i] = 0;
      ad[i] = 0;
    }
    build();
  }

  void build(int v = 0, int l = 0, int r = -1) {
    if (r == -1) r = sz;
    if (l + 1 == r) {
      numMn[v] = 1;
      mn[v] = 0;
      return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    numMn[v] = r - l;
  }

  void push(int v) {
    if (ad[v]) {
      ad[v * 2 + 1] += ad[v];
      mn[v * 2 + 1] += ad[v];
      ad[v * 2 + 2] += ad[v];
      mn[v * 2 + 2] += ad[v];
      ad[v] = 0;
    }
  }  

  void add(int L, int R, int val, int v = 0, int l = 0, int r = -1) {
    if (r == -1) r = sz;
    if (l >= R || L >= r) return;
    if (L <= l && r <= R) {
      ad[v] += val;
      mn[v] += val;
      return;
    }
    push(v);
    int m = (l + r) / 2;
    add(L, R, val, v * 2 + 1, l, m);
    add(L, R, val, v * 2 + 2, m, r);

    mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
    numMn[v] = (mn[v * 2 + 1] == mn[v] ? numMn[v * 2 + 1] : 0) + 
               (mn[v * 2 + 2] == mn[v] ? numMn[v * 2 + 2] : 0);
  }

  int getNonZero() {
    return (mn[0] == 0 ? sz - numMn[0] : sz);
  }  
};

ll cntArea(const vector<Rect> &rects, int n) {
  ST st(n);
  vector<vector<pair<int, int>>> op(n), cl(n);
  for (const Rect &rect : rects) {
    op[rect.x].emplace_back(rect.y, rect.yy);
    cl[rect.xx].emplace_back(rect.y, rect.yy);

    // cout << rect.y << " " << rect.x << " " << rect.yy << " " << rect.xx << endl;
  }

  ll area = 0;
  for (int x = 0; x < n; x++) {
    for (auto &[y, yy] : op[x])
      st.add(y, yy + 1, 1);
    area += st.getNonZero();
    for (auto &[y, yy] : cl[x])
      st.add(y, yy + 1, -1);
  }

  return area;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> pos(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[x - 1].push_back(i);
  }

  vector<Rect> rects;
  for (const auto &v : pos) {
    if (v.empty()) continue;

    for (int i = 0; i < (int)v.size(); i++) {
      rects.emplace_back(
        (i == 0 ? 0 : v[i - 1] + 1),
        v[i],
        v[i],
        (i + 2 < (int)v.size() ? v[i + 2] - 1 : n - 1));

      if (i + 3 < (int)v.size()) 
        rects.emplace_back(0, v[i + 3], v[i], n - 1);
    }
  }

  ll tot = (ll)n * (n + 1) / 2;
  ll bad = cntArea(rects, n);

  // cout << tot << " " << bad << endl;

  cout << tot - bad << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
#ifdef SERT
  t = 3;
#endif
  while (t--) solve();
}