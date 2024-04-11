#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c = int(count(begin(s), end(s), '1'));
    if (c & 1 || c == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";

    vector<int> pos;
    pos.reserve(c + 1);
    for (int i = 0; i < n; ++i) {
      if (s[i] & 1) {
        pos.push_back(i);
      }
    }
    pos.push_back(pos[0] + n);
    DUMP(pos);

    vector<int> v(c);
    for (int z = 0; z < c; ++z) {
      for (int i = pos[z]; i + 1 < pos[z + 1]; ++i) {
        cout << i % n + 1 << ' ' << (i + 1) % n + 1 << '\n';
      }
      v[z] = (pos[z + 1] + n - 1) % n;
    }
    DUMP(v);
    for (int i = 1; i < c; ++i) {
      cout << v[0] + 1 << ' ' << v[i] + 1 << '\n';
    }
  }
}