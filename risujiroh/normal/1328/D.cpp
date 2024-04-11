#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    int s = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] == a[(i + 1) % n]) {
        s = i + 1;
        break;
      }
    }
    if (count(begin(a), end(a), a[0]) == n) {
      cout << "1\n";
      for (int i = 0; i < n; ++i) {
        cout << 1 << " \n"[i == n - 1];
      }
    } else if (s == -1 and n & 1) {
      cout << "3\n";
      for (int i = 0; i < n; ++i) {
        cout << (i ? 1 + i % 2 : 3) << " \n"[i == n - 1];
      }
    } else {
      cout << "2\n";
      vector<int> res(n);
      for (int i = 0; i < s; ++i) {
        res[i] = i % 2;
      }
      for (int i = n; i-- > s; ) {
        res[i] = (n - i) % 2;
      }
      for (int i = 0; i < n; ++i) {
        cout << res[i] + 1 << " \n"[i == n - 1];
      }
    }
  }
}