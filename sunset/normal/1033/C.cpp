#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[a[i] - 1] = i;
  }
  vector<bool> f(n);
  for (int i = n - 1; ~i; --i) {
    int x = b[i];
    for (int j = x + i + 1; j < n; j += i + 1) {
      if (a[j] > i && !f[j]) {
        f[x] = true;
      }
    }
    for (int j = x - i - 1; j >= 0; j -= i + 1) {
      if (a[j] > i && !f[j]) {
        f[x] = true;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    putchar(f[i] ? 'A' : 'B');
  }
  putchar(10);
  return 0;
}