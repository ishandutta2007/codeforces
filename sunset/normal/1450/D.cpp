#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      p[--a[i]].push_back(i);
    }
    vector<int> l(n), r(n);
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && a[i] < a[stk.top()]) {
        r[stk.top()] = i - 1;
        stk.pop();
      }
      stk.push(i);
    }
    while (!stk.empty()) {
      r[stk.top()] = n - 1;
      stk.pop();
    }
    for (int i = n - 1; ~i; --i) {
      while (!stk.empty() && a[i] <= a[stk.top()]) {
        l[stk.top()] = i + 1;
        stk.pop();
      }
      stk.push(i);
    }
    while (!stk.empty()) {
      l[stk.top()] = 0;
      stk.pop();
    }
    vector<int> bad(n + 1);
    for (int i = 0; i < n; ++i) {
      vector<int> lens;
      for (int j : p[i]) {
        lens.push_back(r[j] - l[j] + 1);
      }
      sort(lens.begin(), lens.end());
      if (lens.empty()) {
        bad[0]++;
        bad[n - i]--;
      } else {
        if ((int) lens.size() >= 2) {
          bad[0]++;
          bad[lens[lens.size() - 2]]--;
        }
        int l = min(n - i, lens.back()), r = max(n - i, lens.back());
        bad[l]++;
        bad[r]--;
      }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += bad[i];
      cout << (int) (sum == 0);
    }
    cout << "\n";
  }
  return 0;
}