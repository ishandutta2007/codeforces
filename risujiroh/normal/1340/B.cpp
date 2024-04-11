#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto&& e : a) {
    string s;
    cin >> s;
    e = stoi(s, nullptr, 2);
  }
  vector<string> kasu{"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
  vector<int> b(10);
  for (int d = 0; d < 10; ++d) {
    b[d] = stoi(kasu[d], nullptr, 2);
  }
  vector dp(n + 1, vector<bool>(k + 1));
  dp[n][0] = true;
  for (int i = n; i--; ) {
    bitset<8> can;
    for (int d = 0; d < 10; ++d) {
      if ((a[i] | b[d]) == b[d]) {
        can[__builtin_popcount(b[d] ^ a[i])] = 1;
      }
    }
    for (int y = 0; y < 8; ++y) {
      if (can[y]) {
        for (int x = 0; x + y <= k; ++x) {
          dp[i][x + y] = dp[i][x + y] or dp[i + 1][x];
        }
      }
    }
  }
  if (not dp[0][k]) {
    cout << "-1\n";
    exit(0);
  }
  for (int i = 0; i < n; ++i) {
    for (int d = 10; d--; ) {
      if ((a[i] | b[d]) == b[d]) {
        int y = __builtin_popcount(b[d] ^ a[i]);
        if (y <= k and dp[i + 1][k - y]) {
          cout << d;
          k -= __builtin_popcount(b[d] ^ a[i]);
          break;
        }
      }
    }
  }
  cout << '\n';
}