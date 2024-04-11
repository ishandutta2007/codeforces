#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  ll t;
  scanf("%d %lld", &n, &t);
  vector<ll> a(n), b(n);
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    b[i] = a[i] + t;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
    --c[i];
    if (c[i] < i) {
      puts("No");
      return 0;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (c[i] < c[i - 1]) {
      puts("No");
      return 0;
    }
    if (c[i - 1] > i - 1) {
      b[i - 1] = a[i] + t;
    }
  }
  for (int i = 1; i < n; ++i) {
    b[i] = max(b[i], b[i - 1] + 1);
  }
  for (int i = 0; i < n; ++i) {
    if (c[i] < n - 1 && b[c[i]] >= a[c[i] + 1] + t) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", b[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}