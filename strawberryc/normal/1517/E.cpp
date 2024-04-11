#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

typedef long long ll;

const int N = 2e5 + 5, wd = 998244353;

int n, a[N], ans;
ll s[N];

int calc(int l, int r, ll mx) {
  ll cur = a[l];
  int ans = 0;
  for (int i = l, j = l; i <= r; cur += a[i + 1], i += 2) {
  	if (j < i) j = i;
  	while (j + 2 <= r && cur <= mx) j += 2, cur += a[j];
  	while (j > i && cur > mx) cur -= a[j], j -= 2;
  	if (cur > mx) break;
  	ans = (ans + (j - i) / 2 + 1) % wd;
  	if (j == i) cur += a[i + 2];
  }
  cur = a[l] + a[l + 1];
  for (int i = l + 1, j = l + 1; i <= r; cur += a[i + 1], i += 2) {
  	if (j < i) j = i;
  	while (j + 2 <= r && cur <= mx) j += 2, cur += a[j];
  	while (j > i && cur > mx) cur -= a[j], j -= 2;
  	if (cur > mx) break;
  	ans = (ans + (j - i) / 2 + 1) % wd;
  	if (j == i) cur += a[i + 2];
  }
  return ans;
}

void yhjssa() {
  read(n); ans = 0;
  for (int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] + a[i];
  if (n == 1) return (void) puts("1");
  for (int i = 1; i <= n; i++) if (2 * s[i] > s[n]) ans++;
  ans = (ans + calc(1, n - 1, s[n] - 1 >> 1)) % wd;
  ans = (ans + calc(1, n - 2, (s[n] - 1 >> 1) - a[n])) % wd;
  ans = (ans + calc(2, n - 1, s[n] - 1 >> 1)) % wd;
  ans = (ans + calc(2, n - 2, (s[n] - 1 >> 1) - a[n])) % wd;
  printf("%d\n", ans);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}