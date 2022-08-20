#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    --from;
    --to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  for (int i = 0; i < n; ++i) {
    sort(adj[i].begin(), adj[i].end());
  }
  for (int k = 1; k < n; ++k) {
    if (n % k == 0) {
      bool valid = true;
      for (int i = 0; i < n; ++i) {
        if (adj[i].size() != adj[(i + k) % n].size()) {
          valid = false;
          break;
        }
        vector<int> need;
        for (auto j : adj[i]) {
          need.push_back((j + k) % n);
        }
        rotate(need.begin(), min_element(need.begin(), need.end()), need.end());
        if (need != adj[(i + k) % n]) {
          valid = false;
          break;
        }
      }
      if (valid) {
        cout << "Yes" << "\n";
        return 0;
      }
    }
  }
  cout << "No" << "\n";
  return 0;
}