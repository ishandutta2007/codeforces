#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> res;
  for (int i = max(n - 100, 1); i < n; ++i) {
    int s = i;
    for (char c : to_string(i)) {
      s += c - '0';
    }
    if (s == n) {
      res.push_back(i);
    }
  }
  cout << size(res) << '\n';
  for (int e : res) {
    cout << e << '\n';
  }
}