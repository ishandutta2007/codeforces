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
    assert(int(size(s)) == 2 * n);

    vector<int> h(2 * n + 1);
    for (int i = 0; i < 2 * n; ++i) {
      if (s[i] == '(') {
        h[i + 1] = h[i] + 1;
      } else {
        h[i + 1] = h[i] - 1;
      }
    }

    assert(h[2 * n] == 0);

    if (0 <= *min_element(begin(h), end(h))) {
      cout << "0\n";
      continue;
    }

    int l = 0;
    while (0 <= h[l + 1]) {
      ++l;
    }

    int r = 2 * n;
    while (0 <= h[r - 1]) {
      --r;
    }

    int li = int(max_element(begin(h), begin(h) + (l + 1)) - begin(h));
    int ri = int(max_element(begin(h) + r, end(h)) - begin(h));

    if (*max_element(begin(h), end(h)) <= h[li] + h[ri]) {
      cout << "1\n";
      cout << li + 1 << ' ' << ri << '\n';
      continue;
    }

    cout << "2\n";
    int max_i = int(max_element(begin(h), end(h)) - begin(h));
    cout << "1 " << max_i << '\n';
    cout << max_i + 1 << ' ' << 2 * n << '\n';
  }
}