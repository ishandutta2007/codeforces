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

const int N = 2e5 + 5;

int n, k, a[N], p[N];
bool vis[N];

int main() {
  int T; read(T);
  while (T--) {
  	read(n); read(k);
  	for (int i = 1; i <= n; i++) read(a[i]), p[i] = i, vis[i] = 0;
  	std::sort(p + 1, p + n + 1, [&](int x, int y)
	  {return a[x] + x > a[y] + y;});
	for (int i = 1; i <= k; i++) vis[p[i]] = 1;
	ll ans = 0;
	for (int i = 1, cur = 0; i <= n; i++)
	  if (vis[i]) cur++;
	  else ans += a[i] + cur;
	printf("%lld\n", ans);
  }
  return 0;
}