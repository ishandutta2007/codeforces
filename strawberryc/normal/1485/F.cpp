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

const int N = 2e5 + 5, EI = 1e9 + 7;

int n, b[N], f[N], nxt[N], a[N];
ll s[N];

void work() {
  read(n); int ans = 0;
  for (int i = 1; i <= n; i++) read(b[i]), s[i] = s[i - 1] + b[i], a[i] = 0;
  f[0] = 1; std::map<ll, int> oo;
  for (int i = n; i >= 0; i--) oo[s[i]] = i + 1,
  	nxt[i] = oo[s[i] - b[i]] ? oo[s[i] - b[i]] - 1 : -1;
  for (int i = 0, cur = 0; i < n; i++)
  {
    cur = (cur + f[i]) % EI;
    if (nxt[i] != -1 && nxt[i] <= n - 2)
	  a[nxt[i] + 2] = (a[nxt[i] + 2] - f[i] + EI) % EI;
	cur = (cur + a[i + 1]) % EI; f[i + 1] = cur;
  }
  for (int i = 0; i <= n; i++) if (nxt[i] == -1 || nxt[i] == n)
    ans = (ans + f[i]) % EI;
  printf("%d\n", ans);
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}