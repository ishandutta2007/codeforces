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

const int N = 1005, wd = 998244353;

int n, m, a[N], H, T, Q[N], f[N], cnt[N], ans;
std::vector<int> out[N], in[N];

void yhjssa() {
  int x, y; bool all0 = 1;
  read(n); read(m); ans = n;
  for (int i = 1; i <= n; i++) read(a[i]), out[i].clear(), in[i].clear(),
    all0 &= !a[i];
  while (m--) read(x), read(y), out[x].push_back(y), in[y].push_back(x);
  if (all0) return (void) puts("0");
  for (int i = 1; i <= n; i++) cnt[i] = out[i].size();
  for (int T = 1; T <= n; T++) {
  	std::vector<int> S;
  	for (int u = 1; u <= n; u++) if (a[u]) S.push_back(u);
  	for (int i = 0; i < S.size(); i++) {
  	  int u = S[i]; a[u]--;
  	  for (int j = 0; j < out[u].size(); j++)
  	    a[out[u][j]]++;
	}
	bool is0 = 1;
	for (int i = 1; i <= n; i++) is0 &= !a[i];
	if (is0) return (void) printf("%d\n", T);
  }
  for (int i = 1; i <= n; i++) f[i] = 0;
  H = T = 0;
  for (int i = 1; i <= n; i++) if (!cnt[i]) f[Q[++T] = i] = 1;
  while (H < T) {
  	int u = Q[++H];
  	for (int i = 0; i < in[u].size(); i++) {
  	  int v = in[u][i];
  	  if (!(--cnt[v])) Q[++T] = v;
  	  f[v] = (f[v] + f[u]) % wd;
	}
  }
  for (int i = 1; i <= n; i++) ans = (1ll * f[i] * a[i] + ans) % wd;
  printf("%d\n", ans);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}