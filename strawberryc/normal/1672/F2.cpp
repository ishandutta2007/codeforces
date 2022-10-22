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

const int N = 2e5 + 5;

int n, a[N], cnt[N], ecnt, nxt[N], adj[N], st[N], go[N], d[N], H, T, Q[N], id[N], w[N];
bool isin[N], isout[N], f1[N], f2[N], s1[N], s2[N];

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; st[ecnt] = u; go[ecnt] = v;
}

int main() {
  int WDJ; read(WDJ);
  while (WDJ--) {
  	read(n); ecnt = 0;
  	for (int i = 1; i <= n; i++) read(a[i]), cnt[i] = adj[i] = 0;
  	for (int i = 1; i <= n; i++) cnt[a[i]]++;
  	int mx = 0, c = 0, x, S;
  	for (int i = 1; i <= n; i++) if (cnt[i] > mx) mx = cnt[i];
  	for (int i = 1; i <= n; i++) if (cnt[i] == mx) c++;
  	for (int i = 1; i <= n; i++) read(x), add_edge(a[i], x);
    bool ans = 1;
    for (int i = 1; i <= n; i++) if (cnt[i] == mx) S = i;
    H = T = 0;
    for (int u = 1; u <= n; u++) d[u] = w[u] = 0, isin[u] = isout[u] = f1[u] = f2[u] = 0;
    for (int e = 1; e <= ecnt; e++)
      if (st[e] != S && go[e] != S) d[go[e]]++;
    for (int u = 1; u <= n; u++) if (u != S && !d[u]) Q[++T] = u;
    while (H < T) {
      int u = Q[++H];
      for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
      	if (v != S && !(--d[v])) Q[++T] = v;
	}
	if (T < n - 1) {puts("WA"); continue;}
	for (int e = 1; e <= ecnt; e++)
	  if (st[e] == S) isin[go[e]] = 1;
	  else if (go[e] == S) isout[st[e]] = 1;
	for (int i = 1; i < n; i++) id[Q[i]] = i;
	for (int i = 1; i < n; i++) {
	  int u = Q[i]; if (isin[u]) f1[u] = 1;
	  if (f1[u]) for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
	    f1[v] = 1;
	}
	for (int i = n - 1; i >= 1; i--) {
	  int u = Q[i]; if (isout[u]) f2[u] = 1;
	  for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
	    f2[u] |= f2[v];
	}
	s1[0] = s2[n] = 0;
	for (int i = 1; i < n; i++) s1[i] = s1[i - 1] | (f1[Q[i]] && isout[Q[i]]);
	for (int i = n - 1; i >= 1; i--) s2[i] = s2[i + 1] | (f2[Q[i]] && isin[Q[i]]);
	for (int e = 1; e <= ecnt; e++) {
	  int u = st[e], v = go[e];
	  if (u == S || v == S) continue;
	  if (id[u] > id[v]) std::swap(u, v);
	  if (f1[u] && f2[v]) w[id[u] + 1]++, w[id[v]]--;
	}
	for (int i = 1; i < n; i++) w[i] += w[i - 1];
	for (int i = 1; i < n; i++) {
	  int u = Q[i];
	  if (cnt[u] == mx && (s1[i - 1] || s2[i + 1] || w[i]))
	    {ans = 0; break;}
	}
	puts(ans ? "AC" : "WA");
  }
  return 0;
}