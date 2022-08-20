#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    unsigned int x, y, z;
    long long l, r;
    int n;
    scanf("%d %lld %lld %u %u %u", &n, &l, &r, &x, &y, &z);
    vector<unsigned int> b(n);
    scanf("%u %u", &b[0], &b[1]);
    for (int i = 2; i < n; ++i) {
      b[i] = x * b[i - 2] + y * b[i - 1] + z;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = b[i] % (r - l + 1) + l;
    }
    long long answer = 1ll << 62;
    int minv = INT_MAX;
    for (int i = 0; i < n; ++i) {
      if (a[i] > minv) {
        answer = min(answer, (long long)a[i] * minv);
      } else {
        minv = a[i];
      }
    }
    int maxv = INT_MIN;
    for (int i = n - 1; ~i; --i) {
      if (a[i] < maxv) {
        answer = min(answer, (long long)a[i] * maxv);
      } else {
        maxv = a[i];
      }
    }
    if (answer == 1ll << 62) {
      puts("IMPOSSIBLE");
    } else {
      printf("%lld\n", answer);
    }
  }
  return 0;
}