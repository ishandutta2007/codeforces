#include <bits/stdc++.h>

using namespace std;

int query(int x) {
  printf("%d\n", x);
  fflush(stdout);
  int result;
  scanf("%d", &result);
  if (!result) {
    exit(0);
  }
  return result;
}

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  vector<bool> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = query(m) == -1;
  }
  int l = 1, r = m;
  for (int t = 0; l <= r; t = (t + 1) % n) {
    int mid = l + r >> 1;
    if ((query(mid) == -1) ^ a[t]) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return 0;
}