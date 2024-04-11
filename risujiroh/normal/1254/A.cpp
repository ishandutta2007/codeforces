#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string str;
  for (char c = 'a'; c <= 'z'; ++c) str += c;
  for (char c = 'A'; c <= 'Z'; ++c) str += c;
  for (char c = '0'; c <= '9'; ++c) str += c;
  int T; cin >> T;
  while (T--) {
    int h, w, k; cin >> h >> w >> k;
    V<string> s(h);
    int c = 0;
    for (auto&& e : s) {
      cin >> e;
      c += count(begin(e), end(e), 'R');
    }
    V<> a(k, c / k);
    fill(begin(a), begin(a) + c % k, c / k + 1);
    V<string> res(h, string(w, 0));
    int t = 0;
    for (int i = 0; i < h; ++i) {
      if (~i & 1) {
        for (int j = 0; j < w; ++j) {
          if (a[t] == 0 and s[i][j] == 'R') {
            ++t;
          }
          res[i][j] = str[t];
          a[t] -= s[i][j] == 'R';
        }
      } else {
        for (int j = w - 1; j >= 0; --j) {
          if (a[t] == 0 and s[i][j] == 'R') {
            ++t;
          }
          res[i][j] = str[t];
          a[t] -= s[i][j] == 'R';
        }
      }
    }
    for (const auto& e : res) {
      cout << e << '\n';
    }
  }
}