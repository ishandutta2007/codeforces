#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int n): n(n) {
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  inline int find(int x) {
    if (x >= n) {
      return n - 1;
    }
    while (x != p[x]) {
      x = p[x] = p[p[x]];
    }
    return x;
  }

  inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    } else {
      p[x] = y;
      return true;
    }
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    dsu d(n + 1);
    for (int i = 0; i < n; ++i) {
      if (a[i] == 1) {
        d.unite(i, i + 1);
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] > n - i) {
        ans += a[i] - (n - i);
        a[i] = n - i;
      }
      while (a[i] > 1) {
        int j = d.find(i + a[i]--);
        while (j != n) {
          if (a[j] == 2) {
            d.unite(j, j + 1);
          }
          j = d.find(j + a[j]--);
        }
        ans += 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}