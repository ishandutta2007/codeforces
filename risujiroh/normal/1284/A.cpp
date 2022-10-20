#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto&& e : s) {
    cin >> e;
  }
  vector<string> t(m);
  for (auto&& e : t) {
    cin >> e;
  }
  int q;
  cin >> q;
  while (q--) {
    int y;
    cin >> y;
    --y;
    cout << s[y % n] + t[y % m] << '\n';
  }
}