#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  int res = 1e9;
  auto diff = [](char c, char d) -> int { return min((26 + c - d) % 26, (26 + d - c) % 26); };
  for (int i = 0; i < n - 3; ++i) {
    int curr = 0;
    curr += diff(s[i], 'A');
    curr += diff(s[i + 1], 'C');
    curr += diff(s[i + 2], 'T');
    curr += diff(s[i + 3], 'G');
    res = min(res, curr);
  }
  cout << res << '\n';
}