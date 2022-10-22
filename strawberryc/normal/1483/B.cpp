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

const int N = 1e5 + 5;

int n, a[N], tot, ans[N];

struct wdtj {
  int pre[N], nxt[N];
  
  void link(int x, int y) {
  	nxt[x] = y; pre[y] = x;
  }
  
  void del(int x) {
  	int y = pre[x], z = nxt[x];
  	nxt[y] = z; pre[z] = y;
  }
  
  void rep(int x, int m) {
  	int y = pre[x], z = nxt[x];
  	if (y == x && x == z) return (void) (pre[m] = nxt[m] = m);
  	link(y, m); link(m, z);
  }
} A, B;

void yhjssa() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  tot = 0;
  for (int i = 1; i < n; i++) A.link(i, i + 1);
  A.link(n, 1);
  std::vector<int> wd;
  int cur = 0;
  for (int i = 2; i <= n; i++) if (std::__gcd(a[i - 1], a[i]) == 1) {
  	if (!cur) cur = i;
  	wd.push_back(i);
  }
  if (std::__gcd(a[n], a[1]) == 1) {
  	if (!cur) cur = 1;
  	wd.push_back(1);
  }
  for (int i = 0; i + 1 < wd.size(); i++) B.link(wd[i], wd[i + 1]);
  if (!wd.empty()) B.link(wd[wd.size() - 1], wd[0]);
  while (cur) {
  	int x = A.pre[cur], y = A.nxt[cur];
  	if (B.nxt[cur] == y) B.del(y);
  	A.del(ans[++tot] = cur);
  	if (cur == x && x == y) break;
  	if (std::__gcd(a[x], a[y]) == 1) B.rep(cur, y), cur = B.nxt[y];
  	else if (B.nxt[cur] == cur) break;
  	else B.del(cur), cur = B.nxt[cur];
  }
  printf("%d ", tot);
  for (int i = 1; i <= tot; i++) printf("%d ", ans[i]);
  puts("");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}