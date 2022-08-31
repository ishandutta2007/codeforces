#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n << 1);
  for (int i = 0; i < n << 1; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
  ll answer = (ll)(a[n - 1] - a[0]) * (a[(n << 1) - 1] - a[n]);
  for (int i = 1; i < n; ++i) {
    answer = min(answer, (ll)(a[(n << 1) - 1] - a[0]) * (a[i + n - 1] - a[i]));
  }
  printf("%lld\n", answer);
  return 0;
}