#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> p(n);
    for (auto&& e : p) {
      cin >> e;
    }
    int k = 0;
    set<string> se;
    for (int i = 0; i < n; ++i) {
      if (se.count(p[i])) {
        [&] {
          for (int j = 0; j < 4; ++j) {
            for (char c = '0'; c <= '9'; ++c) {
              auto q = p[i];
              q[j] = c;
              if (find(begin(p), end(p), q) == end(p)) {
                p[i] = q;
                return;
              }
            }
          }
          assert(false);
        }();
        ++k;
      }
      se.insert(p[i]);
    }
    cout << k << '\n';
    for (const auto& e : p) {
      cout << e << '\n';
    }
  }
}