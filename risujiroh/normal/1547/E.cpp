#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (auto&& e : a) cin >> e, --e;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> ans(n, int(2e9));
    for (int i = 0; i < k; ++i) {
      int t;
      cin >> t;
      pq.emplace(ans[a[i]] = t, a[i]);
    }
    while (!empty(pq)) {
      auto [t, i] = pq.top();
      pq.pop();
      if (t > ans[i]) continue;
      for (int j : {i - 1, i + 1})
        if (0 <= j && j < n && ans[j] > ans[i] + 1) pq.emplace(ans[j] = ans[i] + 1, j);
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
  }
}