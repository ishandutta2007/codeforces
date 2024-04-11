#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  map<int, long long> mp;
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    mp[b - i] += b;
  }
  long long res = 0;
  for (auto e : mp) {
    res = max(res, e.second);
  }
  cout << res << '\n';
}