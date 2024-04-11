#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, s, k;
    cin >> n >> s >> k;
    set<int> se;
    while (k--) {
      int a;
      cin >> a;
      se.insert(a);
    }
    [&] {
      for (int i = 0; ; ++i) {
        if ((s + i <= n and not se.count(s + i)) or (s - i >= 1 and not se.count(s - i))) {
          cout << i << '\n';
          return;
        }
      }
    }();
  }
}