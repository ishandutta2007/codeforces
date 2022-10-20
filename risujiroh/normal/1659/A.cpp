#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n, r, b;
    cin >> n >> r >> b;
    assert(b < r);

    int q = r / (b + 1);
    int rem = r - q * (b + 1);
    for (int i = 0; i <= b; ++i) {
      for (int _ = q; _--;) cout << 'R';
      if (i < rem) cout << 'R';
      cout << "B\n"[i == b];
    }
  }
}