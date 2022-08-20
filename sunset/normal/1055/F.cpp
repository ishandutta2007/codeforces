#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  long long m;
  scanf("%d %lld", &n, &m);
  vector<long long> a(n);
  for (int i = 1; i < n; ++i) {
    int parent;
    long long value;
    scanf("%d %lld", &parent, &value);
    --parent;
    a[i] = a[parent] ^ value;
  }
  sort(a.begin(), a.end());
  vector<int> l(n, 0), r(n, n - 1);
  long long answer = 0;
  for (int i = 61; ~i; --i) {
    vector<int> pl(n), pr(n);
    for (int j = 0, k = 0; j < n; j = k) {
      while (k < n && (a[k] ^ a[j]) < 1ll << i) {
        ++k;
      }
      pr[j] = k - 1;
      pl[k - 1] = j;
    }
    long long more = 0;
    for (int j = 0; j < n; ++j) {
      if (l[j] <= r[j]) {
        if (a[j] >> i & 1) {
          if (a[r[j]] >> i & 1) {
            more += r[j] - pl[r[j]] + 1;
          }
        } else {
          if (!(a[l[j]] >> i & 1)) {
            more += pr[l[j]] - l[j] + 1;
          }
        }
      }
    }
    bool use = false;
    if (m > more) {
      answer |= 1ll << i;
      m -= more;
      use = true;
    }
    for (int j = 0; j < n; ++j) {
      if (l[j] <= r[j]) {
        if ((a[j] >> i & 1) == use) {
          if (a[l[j]] >> i & 1) {
            r[j] = l[j] - 1;
          } else {
            r[j] = pr[l[j]];
          }
        } else {
          if (a[r[j]] >> i & 1) {
            l[j] = pl[r[j]];
          } else {
            l[j] = r[j] + 1;
          }
        }
      }
    }
  }
  printf("%lld\n", answer);
  return 0;
}