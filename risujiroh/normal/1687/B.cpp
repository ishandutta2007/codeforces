#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<int> len(m);
  for (int e = 0; e < m; ++e) {
    cout << "? ";
    for (int i = 0; i < m; ++i) {
      cout << (i == e);
    }
    cout << endl;
    cin >> len[e];
  }

  vector<int> order(m);
  iota(begin(order), end(order), 0);
  sort(begin(order), end(order), [&](int x, int y) { return len[x] < len[y]; });

  int cur = 0;
  string s(m, '0');
  for (int e : order) {
    s[e] = '1';
    cout << "? " << s << endl;
    int x;
    cin >> x;
    if (x == cur + len[e]) {
      cur += len[e];
    } else {
      s[e] = '0';
    }
  }

  cout << "! " << cur << endl;
}