#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int k;
  cin >> k;
  vector<vector<int>> res(2, vector<int>(3));
  res[0][0] = ~(-1u << 18);
  res[0][1] = k;
  res[0][2] = 0;
  res[1][0] = 1 << 17;
  res[1][1] = ~(-1u << 18);
  res[1][2] = ~(-1u << 17);
  cout << "2 3\n";
  for (auto&& v : res) {
    for (int j = 0; j < 3; ++j) {
      cout << v[j] << " \n"[j == 2];
    }
  }
}