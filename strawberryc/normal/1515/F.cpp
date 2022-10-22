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

const int N = 3e5 + 5;

int n, m, x, fa[N], cur = 1;
ll a[N], sum;
std::vector<int> out[N], outs[N];
std::set<int> que;

int cx(int x) {
  if (fa[x] != x) fa[x] = cx(fa[x]);
  return fa[x];
}

int main() {
  int u, v;
  read(n); read(m); read(x);
  for (int i = 1; i <= n; i++) fa[i] = i, read(a[i]), a[i] -= x,
    sum += a[i];
  for (int i = 1; i <= n; i++) if (a[i] >= 0) que.insert(i);
  for (int i = 1; i <= m; i++) read(u), read(v), out[u].push_back(v),
    out[v].push_back(u), outs[u].push_back(i), outs[v].push_back(i);
  if (sum < -x) return puts("NO"), 0;
  puts("YES");
  for (int i = 1; i < n; i++) {
  	int u;
  	if (!que.empty()) u = *que.begin();
  	else {
  	  while (fa[cur] != cur) cur++;
  	  u = cur;
	}
	while (cx(u) == cx(out[u][out[u].size() - 1])) out[u].pop_back(),
	  outs[u].pop_back();
	int ix = out[u].size() - 1, v = cx(out[u][ix]), w = outs[u][ix];
	if (!que.empty()) que.erase(que.begin());
	if (a[v] >= 0) que.erase(que.find(v));
	if (out[u].size() < out[v].size()) std::swap(u, v);
	fa[v] = u; if ((a[u] += a[v]) >= 0) que.insert(u);
	for (int i = 0; i < out[v].size(); i++)
	  out[u].push_back(out[v][i]), outs[u].push_back(outs[v][i]);
	printf("%d\n", w);
  }
  return 0;
}