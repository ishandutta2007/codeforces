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

const int N = 3e5 + 5;

int n, a[N], b[N], H, T, Q[N], d[N], pre[N], ans = -1, res[N];
std::set<int> wd;

int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) read(b[i]);
  Q[T = 1] = n;
  for (int i = 0; i < n; i++) wd.insert(i);
  while (H < T) {
  	int u = Q[++H], i = u + b[u]; bool is = 0;
  	for (std::set<int>::iterator it = wd.lower_bound(i - a[i]);
	  it != wd.end() && *it <= i;) {
	  	std::set<int>::iterator ti = it; ti++;
	  	Q[++T] = *it; d[*it] = d[u] + 1; pre[*it] = u;
	  	if (*it == 0) {ans = d[*it]; is = 1; break;}
	  	wd.erase(it); it = ti;
	  }
	if (is) break;
  }
  if (printf("%d\n", ans), ans == -1) return 0;
  int u = 0;
  for (int i = 1; i <= ans; i++) res[i] = u, u = pre[u];
  for (int i = ans; i >= 1; i--) printf("%d ", res[i]);
  return 0;
}