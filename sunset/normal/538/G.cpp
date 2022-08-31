#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto no_solution = [&]() {
    cout << "NO" << "\n";
    exit(0);
  };
  int n, m;
  cin >> n >> m;
  ++n;
  vector<pair<long long, long long>> foo(n);
  vector<pair<long long, long long>> bar(n);
  for (int i = 0; i < n; ++i) {
    long long t, x, y;
    if (!i) {
      t = x = y = 0;
    } else {
      cin >> t >> x >> y;
    }
    if (abs(x) + abs(y) > t || (x + y + t) % 2 == 1) {
      no_solution();
    }
    foo[i] = make_pair(t, (x + y + t) / 2);
    bar[i] = make_pair(t, (x - y + t) / 2);
  }
  auto solve = [&](vector<pair<long long, long long>> v) {
    sort(v.begin(), v.end(), [&](const pair<long long, long long>& a, const pair<long long, long long>& b) {
      return a.first % m < b.first % m;
    });
    long long l = 0;
    long long r = m;
    for (int i = 0; i < n; ++i) {
      long long foo = (i == n - 1 ? -1 : v[i + 1].first / m) - v[i].first / m;
      long long bar = (i == n - 1 ? m : v[i + 1].first % m) - v[i].first % m;
      long long baz = (i == n - 1 ? 0 : v[i + 1].second) - v[i].second;
      bar = baz - bar;
      if (!foo) {
        if (baz < 0 || bar > 0) {
          no_solution();
        }
        continue;
      }
      if (foo < 0) {
        foo *= -1; bar *= -1; baz *= -1;
        swap(bar, baz);
      }
      if (baz < 0) {
        no_solution();
      }
      l = max(l, (bar + foo - 1) / foo);
      r = min(r, baz / foo);
    }
    if (l > r) {
      no_solution();
    }
    vector<int> ans(m);
    for (int i = 0; i < n; ++i) {
      long long foo = (i == n - 1 ? -1 : v[i + 1].first / m) - v[i].first / m;
      long long baz = (i == n - 1 ? 0 : v[i + 1].second) - v[i].second;
      for (int j = 0; j < baz - foo * l; ++j) {
        ans[v[i].first % m + j] = 1;
      }
    }
    return ans;
  };
  vector<int> ans_foo = solve(foo);
  vector<int> ans_bar = solve(bar);
  string output = "LDUR";
  for (int i = 0; i < m; ++i) {
    cout << output[ans_foo[i] << 1 | ans_bar[i]];
  }
  cout << "\n";
  return 0;
}