#include <bits/stdc++.h>

using namespace std;

using ld = double;

const ld pi = acos(-1);

struct fenwick {
  vector<int> fenw;
  int n;

  fenwick(int n) : n(n) {
    fenw.resize(n);
  }

  void modify(int x, int v) {
    while (x < n) {
      fenw[x] += v;
      x |= x + 1;
    }
  }

  int query(int x) {
    int res = 0;
    while (x >= 0) {
      res += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
};

ld norm(ld x) {
  while (x < 0) {
    x += pi * 2;
  }
  while (x >= pi * 2) {
    x -= pi * 2;
  }
  return x;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  ld x, y;
  cin >> n >> x >> y >> m;
  x /= 1000; y /= 1000;
  vector<ld> a(n), b(n), angle(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    a[i] /= 1000; b[i] /= 1000;
    angle[i] = atan(a[i]);
    if (y > a[i] * x + b[i]) {
      angle[i] -= pi / 2;
    } else {
      angle[i] += pi / 2;
    }
  }
  ld low = 0, high = 2e9;
  for (int rep = 0; rep < 60; ++rep) {
    ld r = (low + high) / 2;
    vector<pair<ld, ld>> p;
    for (int i = 0; i < n; ++i) {
      ld d = abs((a[i] * x - y + b[i]) / (sqrt(a[i] * a[i] + 1)));
      if (d < r) {
        ld delta = acos(d / r);
        p.emplace_back(norm(angle[i] - delta), norm(angle[i] + delta));
        if (p.back().first > p.back().second) {
          swap(p.back().first, p.back().second);
        }
      }
    }
    int s = p.size();
    sort(p.begin(), p.end());
    vector<ld> d(s);
    for (int i = 0; i < s; ++i) {
      d[i] = p[i].second;
    }
    sort(d.begin(), d.end());
    fenwick fenw(s);
    long long cnt = 0;
    for (int i = 0; i < s; ++i) {
      int l = lower_bound(d.begin(), d.end(), p[i].first) - d.begin();
      int r = lower_bound(d.begin(), d.end(), p[i].second) - d.begin();
      cnt += fenw.query(r) - fenw.query(l - 1);
      fenw.modify(r, 1);
    }
    if (cnt <= m) {
      low = r;
    } else {
      high = r;
    }
  }
  ld r = low;
  vector<pair<pair<ld, ld>, int>> p;
  for (int i = 0; i < n; ++i) {
    ld d = abs((a[i] * x - y + b[i]) / (sqrt(a[i] * a[i] + 1)));
    if (d < r) {
      ld delta = acos(d / r);
      p.emplace_back(make_pair(norm(angle[i] - delta), norm(angle[i] + delta)), i);
      if (p.back().first.first > p.back().first.second) {
        swap(p.back().first.first, p.back().first.second);
      }
    }
  }
  int s = p.size(), take = 0;
  sort(p.begin(), p.end());
  set<pair<ld, int>> st;
  ld ans = 0;
  for (int i = 0; i < s; ++i) {
    auto it = st.lower_bound(make_pair(p[i].first.first, -1));
    while (it != st.end()) {
      if (it->first > p[i].first.second) {
        break;
      }
      int j = it->second;
      int k = p[i].second;
      ld xx = (b[k] - b[j]) / (a[j] - a[k]);
      ld yy = a[j] * xx + b[j];
      ans += sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
      ++take;
      ++it;
    }
    st.emplace(p[i].first.second, p[i].second);
  }
  cout << fixed << setprecision(10) << ans + (m - take) * low << "\n";
  return 0;
}