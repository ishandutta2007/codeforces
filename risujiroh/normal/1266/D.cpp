#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  while (m--) {
    int u, v, d;
    cin >> u >> v >> d;
    --u, --v;
    a[u] -= d;
    a[v] += d;
  }
  vector<int> pos, neg;
  for (int v = 0; v < n; ++v) {
    if (a[v] > 0) {
      pos.push_back(v);
    }
    if (a[v] < 0) {
      neg.push_back(v);
    }
  }
  vector< tuple<int, int, long long> > res;
  {
    int i = 0, j = 0, np = pos.size(), nn = neg.size();
    while (i < np and j < nn) {
      long long t = min(a[pos[i]], -a[neg[j]]);
      a[pos[i]] -= t;
      a[neg[j]] += t;
      res.emplace_back(neg[j], pos[i], t);
      while (i < np and a[pos[i]] == 0) {
        ++i;
      }
      while (j < nn and a[neg[j]] == 0) {
        ++j;
      }
    }
  }
  cout << res.size() << '\n';
  for (auto e : res) {
    cout << get<0>(e) + 1 << ' ' << get<1>(e) + 1 << ' ' << get<2>(e) << '\n';
  }
}