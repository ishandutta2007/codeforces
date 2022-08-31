#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end(), greater<int>());
  long long low = 0, high = n;
  {
    // <= a[i-1]
    long long lsum = 0;
    for (int i = 0; i < n; ++i) {
      lsum += a[i];
    }
    long long rsum = 0;
    vector<int> cnt(n + 1);
    int larger = 0;
    {
      long long temp = lsum - rsum - (long long) n * (n - 1);
      if (n < temp) {
        low = max(low, (long long) a[n - 1] + 1);
      } else {
        low = max(low, min(temp, (long long) a[n - 1] + 1));
      }
    }
    for (int i = n - 1; i; --i) {
      lsum -= a[i];
      rsum += min(a[i], i);
      larger += cnt[i + 1];
      rsum -= larger;
      ++cnt[a[i]];
      if (a[i] > i) {
        ++larger;
      }
      long long temp = lsum - rsum - (long long) i * (i - 1);
      if (i < temp) {
        low = max(low, (long long) a[i - 1] + 1);
      } else {
        low = max(low, min(temp, (long long) a[i - 1] + 1));
      }
    }
  }
  {
    // >= a[i]
    long long lsum = 0;
    for (int i = 0; i < n; ++i) {
      lsum += a[i];
    }
    long long rsum = 0;
    vector<int> cnt(n + 2);
    int larger = 0;
    for (int i = n - 1; i; --i) {
      lsum -= a[i];
      rsum += min(a[i], i + 1);
      larger += cnt[i + 2];
      rsum -= larger;
      ++cnt[a[i]];
      if (a[i] > i + 1) {
        ++larger;
      }
      long long temp = (long long) i * (i + 1) + rsum - lsum;
      high = min(high, max(temp, (long long) a[i] - 1));
    }
    {
      lsum = rsum = 0;
      for (int i = 0; i < n; ++i) {
        rsum += min(a[i], 1);
      }
      long long temp = rsum - lsum;
      high = min(high, max(temp, (long long) a[0] - 1));
    }
  }
  int parity = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] & 1) {
      parity ^= 1;
    }
  }
  if ((low & 1) != parity) {
    ++low;
  }
  if ((high & 1) != parity) {
    --high;
  }
  if (low > high) {
    puts("-1");
  } else {
    for (int i = low; i <= high; i += 2) {
      printf("%d%c", i, i == high ? '\n' : ' ');
    }
  }
  return 0;
}