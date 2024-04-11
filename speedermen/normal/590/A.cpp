#include <bits/stdc++.h>

using namespace std;

const int MaxN = 5e5 + 10;

int a[MaxN], b[MaxN], n;

int calc() {
  for (int i = 1; i <= n; ++i) {
    if (i == 1 || i == n) {
      b[i] = a[i];
      continue;
    }
    int arr[3] = {a[i - 1], a[i], a[i + 1]};
    sort(arr, arr + 3);
    b[i] = arr[1];
  }
  for (int i = 1; i <= n; ++i) {
    a[i] = b[i];
  }
}

void solve() {
  //10
  //1 1 0 1 0 0 1 0 1 0
  int ans = 0;
  for (int i = 1, j; i <= n; i = j + 1) {
    if (i == n || a[i] == a[i + 1]) {
      j = i;
      continue;
    }
    j = i + 1;
    while (j <= n && a[j] != a[j - 1]) {
      ++j;
    }
    --j;
    ans = max(ans, (j - i) / 2);
    if (a[i] == a[j]) {
      for (int k = i; k <= j; ++k) {
        a[k] = a[i];
      }
    } else if (a[i] != a[j]) {
      int c = (j - i) / 2;
      for (int k = 1; k <= c; ++k) {
        a[i + k] = a[i];
        a[j - k] = a[j];
      }
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  memcpy(b, a, sizeof(b));
  solve();
  memcpy(a, b, sizeof(a));
  /*cout << endl;
  for (int it = 0; it < 10; ++it) {
    calc();
    for (int i = 1; i <= n; ++i) {
      cout << a[i] << ' ';
    }
    cout << endl;
  }*/
  return 0;
}