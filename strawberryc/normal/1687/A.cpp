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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 2e5 + 5;

int n, k, a[N];

int main() {
  int T; read(T);
  while (T--) {
  	ll cur = 0, ans = 0;
  	read(n); read(k);
  	for (int i = 1; i <= n; i++) read(a[i]);
  	int m = k < n ? k : n;
  	for (int i = 1; i <= n; i++)
  	  if (cur += a[i], i >= m)
  	    ans = Max(ans, cur), cur -= a[i - m + 1];
  	printf("%lld\n", ans + 1ll * (k - 1) * m - 1ll * m * (m - 1) / 2);
  }
  return 0;
}