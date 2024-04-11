#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t[500005], p[500005];
int c[500005];

int n;
void ins(int p) {
  for (; p <= n; p += p & -p)
    ++t[p];
}
int query(int p) {
  int s = 0;
  for (; p; p &= p - 1)
    s += t[p];
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    fill(t + 1, t + 1 + n, 0);
    ll invs = 0;
    for (int i = 1; i <= n; ++i)
      cin >> p[i];
    for (int i = n; i >= 1; --i) {
      ins(p[i]);
      int q = query(p[i] - 1);
      invs += q;
      c[i] = -2 * q;
    }
    fill(t + 1, t + 1 + n, 0);
    for (int i = 1; i <= n; ++i) {
      ins(p[i]);
      int q = query(p[i] - 1);
      c[i] += (i - 1 - q) - q;
    }
    sort(c + 1, c + 1 + n, greater<>());
    ll ans = invs;
    for (int i = 0; i <= n; ++i) {
      if (i) ans -= c[i];
      cout << ans - (ll)i * (i - 1) / 2 << " \n"[i == n];
    }
  }
}