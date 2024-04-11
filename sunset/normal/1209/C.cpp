#include <bits/stdc++.h>

using namespace std;

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
    string s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = s[i] - '0';
    }
    vector<int> l(10, n);
    vector<int> r(10, -1);
    for (int i = 0; i < n; ++i) {
      l[a[i]] = min(l[a[i]], i);
      r[a[i]] = max(r[a[i]], i);
    }
    vector<int> col(n, -1);
    int last = -1;
    int who = 0;
    for (int i = 0; i < 10; ++i) {
      if (l[i] <= r[i]) {
        if (last > l[i]) {
          ++who;
          if (who == 2) {
            break;
          }
          for (int j = last; j < n; ++j) {
            if (a[j] == i) {
              col[j] = 0;
            }
          }
          last = -1;
        }
        for (int j = l[i]; j <= r[i]; ++j) {
          if (a[j] == i && col[j] == -1) {
            col[j] = who;
            last = j;
          }
        }
      }
    }
    if (who == 2) {
      cout << "-" << "\n";
    } else {
      for (int i = 0; i < n; ++i) {
        cout << col[i] + 1;
      }
      cout << "\n";
    }
  }
  return 0;
}