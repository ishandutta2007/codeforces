#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  vector<int> q(n);
  for (int i = 0; i < n; ++i) {
    q[p[i]] = i;
  }
  vector<int> order;
  for (int i = 0; i < n / 2; ++i) {
    order.push_back(n / 2 + i);
    order.push_back(n / 2 - i - 1);
  }
  vector<pair<int, int>> ans;
  auto sw = [&](int a, int b) {
    ans.emplace_back(a, b);
    swap(p[a], p[b]);
    q[p[a]] = a;
    q[p[b]] = b;
  };
  for (auto i : order) {
    int j = q[i];
    if (j != i) {
      if (abs(j - i) >= n / 2) {
        sw(j, i);
      } else {
        if (i >= n / 2) {
          if (j >= n / 2) {
            sw(j, 0);
            sw(0, i);
          } else {
            sw(j, n - 1);
            sw(n - 1, 0);
            sw(0, i);
          }
        } else {
          if (j >= n / 2) {
            sw(j, 0);
            sw(0, n - 1);
            sw(n - 1, i);
          } else {
            sw(j, n - 1);
            sw(n - 1, i);
          }
        }
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto p : ans) {
    cout << p.first + 1 << " " << p.second + 1 << "\n";
  }
  return 0;
}