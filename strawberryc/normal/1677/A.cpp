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

const int N = 5005;

int n, a[N], s[N][N], inv[N][N];

int main() {
  int T; read(T);
  while (T--) {
  	read(n);
  	for (int i = 1; i <= n; i++) read(a[i]);
  	for (int i = 1; i <= n; i++)
  	  for (int j = 1; j <= n; j++)
  	    s[i][j] = s[i][j - 1] + (a[j] > i);
  	for (int i = 1; i <= n; i++)
  	  for (int j = i; j <= n; j++)
  	    inv[i][j] = inv[i][j - 1] + s[a[j]][j - 1] - s[a[j]][i - 1];
  	ll ans = 0;
  	for (int i = 1; i <= n - 3; i++)
  	  for (int j = i + 2; j < n; j++)
  	    if (a[i] < a[j])
  	      ans += inv[i + 1][n] - inv[i + 1][j - 1] - inv[j + 1][n]
  	        - s[a[j]][j - 1] + s[a[j]][i] - n + j + s[a[j]][n] - s[a[j]][j];
  	printf("%lld\n", ans);
  }
  return 0;
}