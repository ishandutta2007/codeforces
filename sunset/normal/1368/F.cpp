#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  auto get = [&](int k) {
    return n - k - (n + k - 1) / k + 1;
  };
  int k = 1;
  for (int i = 1; i <= n; ++i) {
    if (get(i) > get(k)) {
      k = i;
    }
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    if (i % k == 0) {
      a[i] = 2;
    }
  }
  int t = 0;
  while (t < get(k)) {
    cout << k;
    int used = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 0) {
        cout << " " << i + 1;
        a[i] = 1;
        used++;
        t++;
        if (used == k) {
          break;
        }
      }
    }
    cout << endl;
    int p;
    cin >> p;
    for (int i = 0; i < k; ++i) {
      if (a[(p + i - 1) % n] == 1) {
        a[(p + i - 1) % n] = 0;
        t--;
      }
    }
  }
  cout << 0 << endl;
  return 0;
}