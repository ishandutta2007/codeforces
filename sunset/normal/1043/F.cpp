#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  int g = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    g = __gcd(g, a[i]);
  }
  if (g != 1) {
    cout << -1 << endl;
    return 0;
  }
  int m = *max_element(a.begin(), a.end());
  vector<long long> b(m + 1), c(m + 1), d(m + 1);
  for (int i = 0; i < n; ++i) {
    b[a[i]] = c[a[i]] = 1;
  }
  int answer = 1;
  while (true) {
    if (b[1]) {
      cout << answer << endl;
      return 0;
    }
    for (int i = 1; i <= m; ++i) {
      int sumb = 0, sumc = 0;
      for (int j = i; j <= m; j += i) {
        sumb += b[j];
        sumc += c[j];
      }
      d[i] = (long long)sumb * sumc;
    }
    for (int i = m; i; --i) {
      for (int j = i << 1; j <= m; j += i) {
        d[i] -= d[j];
      }
    }
    for (int i = 1; i <= m; ++i) {
      b[i] = d[i] > 0;
    }
    ++answer;
  }
  return 0;
}