#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  vector<int> a(n);
  int value = n;
  while (!*min_element(a.begin(), a.end())) {
    bool zero = false;
    for (int i = 0; i < n; ++i) {
      if (!l[i] && !r[i] && !a[i]) {
        zero = true;
        a[i] = value;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] == value) {
        for (int j = 0; j < n; ++j) {
          if (!a[j]) {
            if (j < i) {
              --r[j];
              if (r[j] < 0) {
                cout << "NO" << endl;
                return 0;
              }
            } else {
              --l[j];
              if (l[j] < 0) {
                cout << "NO" << endl;
                return 0;
              }
            }
          }
        }
      }
    }
    if (!zero) {
      cout << "NO" << endl;
      return 0;
    }
    --value;
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (i < n - 1) {
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}