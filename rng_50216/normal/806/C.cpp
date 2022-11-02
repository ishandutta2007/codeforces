#include <bits/stdc++.h>

using namespace std;

int const N = 123456;

int const BITS = 42;
int have[BITS], h[BITS], got[BITS];
int ans[N];

int main() {
  int n;
  scanf("%d", &n);
  map<long long, int> mp;
  for (int i = 0; i < BITS; i++) {
    mp[1LL << i] = i;
  }
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    if (mp.find(x) != mp.end()) {
      have[mp[x]]++;
    } else {
      h[mp.lower_bound(x)->second]++;
    }
  }
  int ac = 0;
  int cnt = 0;
  while (have[0] > 0) {
    ++cnt;
    int cur = 0;
    while (have[cur] > 0) {
      --have[cur];
      ++cur;
    }
    got[cur]++;
    int sum = 0;
    bool ok = true;
    for (int i = BITS - 1; i >= 0; i--) {
      sum += got[i];
      sum -= have[i] + h[i];
      if (sum < 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans[ac++] = cnt;
    }
  }
  if (ac == 0) {
    ans[ac++] = -1;
  }
  for (int i = 0; i < ac; i++) {
    if (i > 0) putchar(' ');
    printf("%d", ans[i]);
  }
  puts("");
}