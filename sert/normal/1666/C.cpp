#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pt {
  ll x, y;
  explicit pt(ll x = 0, ll y = 0): x(x), y(y) {}
  bool operator==(const pt &a) const { return x == a.x && y == a.y; }
  pt operator-(const pt &a) const { return pt(x - a.x, y - a.y); }
  ll operator%(const pt &a) const { return x * a.x + y * a.y; }
  friend istream& operator>>(istream &fi, pt &p) {
    fi >> p.x >> p.y;
    return fi;
  }
};

vector<pair<pt, pt>> ans;
ll ans_val = 1e18;

void upd(pt a, pt b, pt c, int k) {
  pt p(a.x, b.y);
  vector<pair<pt, pt>> cur;
  long long curLen = 0;
  auto add = [&](const pt &bb, const pt &aa) {
    if (aa == bb) return;
    cur.emplace_back(aa, bb);
    curLen += abs(aa.x - bb.x) + abs(aa.y - bb.y);
  };
  add(a, p);
  add(p, b);

  if (k) swap(a, b);
  if (a == p) return;

  if ((a - p) % (c - p) < 0) {
    add(c, pt(c.x, p.y));
    add(pt(c.x, p.y), p);
  } else if ((p - a) % (c - a) < 0) {
    add(c, pt(c.x, a.y));
    add(pt(c.x, a.y), a);
  } else {
    if (a.x == p.x) add(c, pt(a.x, c.y));
    else add(c, pt(c.x, a.y));
  }

  if (curLen < ans_val) {
    ans_val = curLen;
    ans = cur;
  }
}

int main() {
#ifdef SERT
  freopen("../a.in", "r", stdin);
#endif
  pt a, b, c;
  cin >> a >> b >> c;

  for (int k = 0; k < 2; k++) {
    upd(a, b, c, k);
    upd(a, c, b, k);
    upd(b, a, c, k);
    upd(b, c, a, k);
    upd(c, b, a, k);
    upd(c, a, b, k);
  }

#ifdef SERT
  cout << ans_val << "\n";
#endif

  cout << ans.size() << "\n";
  for (auto &[p1, p2] : ans) {
    cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << "\n";
  }
}