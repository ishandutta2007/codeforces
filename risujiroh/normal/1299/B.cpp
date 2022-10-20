#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  if (n & 1) {
    cout << "NO\n";
    exit(0);
  }
  set<pair<int, int>> se;
  for (int i = 0; i < n / 2; ++i) {
    se.emplace(x[i] + x[n / 2 + i], y[i] + y[n / 2 + i]);
  }
  if (se.size() == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}