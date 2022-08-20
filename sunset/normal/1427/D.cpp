#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> ans;
  while (!is_sorted(a.begin(), a.end())) {
    for (int x = 2; x <= n; ++x) {
      int foo = -1, bar = -1;
      for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
          foo = i;
        }
        if (a[i] == x - 1) {
          bar = i;
        }
      }
      if (foo < bar) {
        int first = foo, last = n - 1 - bar;
        int p = foo;
        while (a[p + 1] == a[p] + 1) {
          ++p;
        }
        ans.push_back(vector<int>());
        if (first) {
          ans.back().push_back(foo);
        }
        ans.back().push_back(p - foo + 1);
        ans.back().push_back(bar - p);
        if (last) {
          ans.back().push_back(n - 1 - bar);
        }
        vector<int> new_a;
        for (int i = bar + 1; i < n; ++i) {
          new_a.push_back(a[i]);
        }
        for (int i = p + 1; i <= bar; ++i) {
          new_a.push_back(a[i]);
        }
        for (int i = foo; i <= p; ++i) {
          new_a.push_back(a[i]);
        }
        for (int i = 0; i < foo; ++i) {
          new_a.push_back(a[i]);
        }
        swap(a, new_a);
        break;
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto v : ans) {
    cout << v.size();
    for (int x : v) {
      cout << " " << x;
    }
    cout << "\n";
  }
  return 0;
}