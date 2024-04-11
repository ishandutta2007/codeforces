#include <cstdio>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long ll;
 
const int N = 5005;
const ll INF = 1e18;
int t[N], x[N], id[N], disc[N];
ll mint[N];
bool f[N][N];
 
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", t + i, x + i);
  copy(x + 1, x + 1 + n, disc + 1);
  sort(disc + 1, disc + 1 + n);
  for (int i = 1; i <= n; ++i)
    id[i] = lower_bound(disc + 1, disc + 1 + n, x[i]) - disc;
  mint[0] = 0;
  fill(mint + 1, mint + 1 + n, INF);
  auto up = [](ll &x, ll y) { if (x > y) x = y; };
  for (int i = 0; i < n; ++i) {
    if (mint[i] <= t[i]) {
      up(mint[i + 1], max<ll>(t[i], mint[i] + abs(x[i + 1] - x[i])));
      for (int j = i + 2; j <= n; ++j)
        if ((ll)max<ll>(t[i], mint[i] + abs(x[j] - x[i])) + abs(x[j] - x[i + 1]) <= t[i + 1])
          f[i + 1][id[j]] = true;
    }
    if (f[i][id[i + 1]]) {
      up(mint[i + 2], max(t[i + 1], t[i] + abs(x[i + 2] - x[i])));
      for (int j = i + 3; j <= n; ++j)
        if ((ll)max(t[i + 1], t[i] + abs(x[j] - x[i])) + abs(x[j] - x[i + 2]) <= t[i + 2])
          f[i + 2][id[j]] = true;
    }
    if (t[i] + abs(x[i + 1] - x[i]) <= t[i + 1])
      for (int j = 1; j <= n; ++j)
        f[i + 1][j] |= f[i][j];
  }
  if (mint[n] <= t[n] || f[n - 1][id[n]]) puts("YES");
  else puts("NO");
  return 0;
}