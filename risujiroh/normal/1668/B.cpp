#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& e : a) {
      cin >> e;
    }
    sort(begin(a), end(a));

    auto s = 0ll;

    for (int i = 0; i < n; ++i) {
      s += max(a[i], a[i + 1 < n ? i + 1 : 0]) + 1;
    }

    cout << (s <= m ? "YES\n" : "NO\n");
  }
}