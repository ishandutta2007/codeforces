#include <bits/stdc++.h>

typedef long long ll;

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 1e5 + 5;

char s[N];
int x, y, n, a[N], b[N], cnt0, cnt1, L[N][2], R[N][2];
ll pre01, pre10, ans = 1e18, Z[N][2], Lk[N][2], Rk[N][2];

int main() {
  scanf("%s", s + 1); n = strlen(s + 1);
  std::cin >> x >> y;
  for (int i = 1; i <= n; i++)
    if (s[i] == '1') pre01 += cnt0;
	else if (s[i] == '0') cnt0++;
  for (int i = 1; i <= n; i++)
    if (s[i] == '0') pre10 += cnt1;
	else if (s[i] == '1') cnt1++;
  for (int i = 1; i <= n; i++) a[i] = a[i - 1] + (s[i] == '?');
  for (int i = n; i >= 1; i--) b[i] = b[i + 1] + (s[i] == '?');
  for (int i = 1; i <= n; i++) {
  	L[i][0] = L[i - 1][0] + (s[i] == '0');
  	L[i][1] = L[i - 1][1] + (s[i] == '1');
  }
  for (int i = n; i >= 1; i--) {
  	R[i][0] = R[i + 1][0] + (s[i] == '0');
  	R[i][1] = R[i + 1][1] + (s[i] == '1');
  }
  for (int i = 1; i <= n; i++) if (s[i] == '?')
    Z[i][0] = 1ll * L[i - 1][1] * y + 1ll * R[i + 1][1] * x,
    Z[i][1] = 1ll * L[i - 1][0] * x + 1ll * R[i + 1][0] * y;
  for (int i = 1; i <= n; i++)
    Lk[i][0] = Lk[i - 1][0] + Z[i][0], Lk[i][1] = Lk[i - 1][1] + Z[i][1];
  for (int i = n; i >= 1; i--)
    Rk[i][0] = Rk[i + 1][0] + Z[i][0], Rk[i][1] = Rk[i + 1][1] + Z[i][1];
  for (int i = 0; i <= n; i++) {
    ans = Min(ans, (pre01 + 1ll * a[i] * b[i + 1]) * x
	  + pre10 * y + Lk[i][0] + Rk[i + 1][1]);
    ans = Min(ans, (pre10 + 1ll * a[i] * b[i + 1]) * y
	  + pre01 * x + Lk[i][1] + Rk[i + 1][0]);
  }
  return std::cout << ans << std::endl, 0;
}