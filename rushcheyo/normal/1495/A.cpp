#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a, b;
    for (int i = 1; i <= 2 * n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (x == 0) a.push_back(abs(y));
      else b.push_back(abs(x));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    double ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i) {
      ans1 += sqrt(1ll * a[i] * a[i] + 1ll * b[i] * b[i]);
      ans2 += sqrt(1ll * a[i] * a[i] + 1ll * b[n - i - 1] * b[n - i - 1]);
    }
    printf("%.15lf\n", min(ans1, ans2));
  }
}