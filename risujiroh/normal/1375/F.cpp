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
  using ll = long long;
  array<ll, 3> a;
  cin >> a[0] >> a[1] >> a[2];
  vector<int> ord(3);
  iota(begin(ord), end(ord), 0);
  auto upd = [&] {
    sort(begin(ord), end(ord), [&](int i, int j) {
      return a[i] < a[j];
    });
  };
  upd();
  cout << "First" << endl;
  if (a[ord[0]] == a[ord[2]]) {
    cout << 1 << endl;
    int i;
    cin >> i;
    assert(i == 0);
    exit(0);
  }
  int last = -1;
  while (true) {
    upd();
    if (last != -1 and 2 * a[ord[1]] == a[ord[0]] + a[ord[2]]) {
      cout << a[ord[1]] - a[ord[0]] << endl;
      int i;
      cin >> i;
      assert(i == 0);
      exit(0);
    }
    ll y = 2 * a[ord[2]] - a[ord[0]] - a[ord[1]];
    cout << y << endl;
    cin >> last;
    --last;
    a[last] += y;
  }
}