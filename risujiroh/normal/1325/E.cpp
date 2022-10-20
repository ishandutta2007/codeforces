#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 1e6;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  vector<int> factor(lim + 1);
  for (int p = 2; p <= lim; ++p) {
    if (factor[p] == 0) {
      for (int i = p; i <= lim; i += p) {
        if (factor[i] == 0) {
          factor[i] = p;
        }
      }
    }
  }
  vector<map<int, int>> mp(lim + 1);
  for (int i = 2; i <= lim; ++i) {
    mp[i] = mp[i / factor[i]];
    ++mp[i][factor[i]];
  }
  vector<int> p2v(lim + 1, -1);
  int sz = 0;
  for (int p = 1; p <= lim; ++p) {
    if (p == 1 or factor[p] == p) {
      p2v[p] = sz++;
    }
  }
  int n;
  cin >> n;
  vector<pair<int, int>> es;
  while (n--) {
    int x;
    cin >> x;
    vector<int> ps;
    for (auto e : mp[x]) {
      if (e.second & 1) {
        ps.push_back(e.first);
      }
    }
    if (ps.empty()) {
      cout << "1\n";
      exit(0);
    }
    if (ps.size() == 1) {
      ps.insert(begin(ps), 1);
    }
    assert(ps.size() == 2);
    int u = p2v[ps[0]], v = p2v[ps[1]];
    es.emplace_back(u, v);
  }
  sort(begin(es), end(es));
  if (adjacent_find(begin(es), end(es)) != end(es)) {
    cout << "2\n";
    exit(0);
  }
  vector<vector<int>> g(sz);
  for (auto e : es) {
    g[e.first].push_back(e.second);
    g[e.second].push_back(e.first);
  }
  int res = sz + 1;
  for (int r = 0; r <= 168; ++r) {
    vector<int> d(sz, -1);
    d[r] = 0;
    queue<pair<int, int>> que({{r, -1}});
    while (not que.empty()) {
      int v, p;
      tie(v, p) = que.front();
      que.pop();
      if (2 * d[v] >= res) {
        break;
      }
      for (int u : g[v]) {
        if (u == p) {
          continue;
        }
        if (d[u] == -1) {
          d[u] = d[v] + 1;
          que.emplace(u, v);
        } else {
          res = min(res, d[v] + d[u] + 1);
        }
      }
    }
  }
  cout << (res <= sz ? res : -1) << '\n';
}