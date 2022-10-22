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

const int N = 2005;

int n, X[N], Y[N], A[N], O, fa[N], pt[N], tmp[N];
std::vector<std::pair<int, int> > ans;

inline bool comp(int u, int v) {
  return atan2(Y[u] - Y[O], X[u] - X[O]) < atan2(Y[v] - Y[O], X[v] - X[O]);
}

ll cross(int u, int v) {
  return 1ll * (X[u] - X[O]) * (Y[v] - Y[O]) - 1ll * (X[v] - X[O]) * (Y[u] - Y[O]);
}

int cx(int x) {
  if (fa[x] != x) fa[x] = cx(fa[x]);
  return fa[x];
}

bool zm(int x, int y) {
  if ((x = cx(x)) != (y = cx(y))) return fa[y] = x, 1;
  return 0;
}

int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(X[i]), read(Y[i]), read(A[i]), fa[i] = i;
  for (int i = 1; i <= n; i++) if (A[i] != i) O = i;
  if (!O) return puts("0"), 0;
  for (int i = 1; i < n; i++) pt[i] = i < O ? i : i + 1;
  std::sort(pt + 1, pt + n, comp);
  for (int i = 1; i <= n; i++) zm(i, A[i]);
  int k = 0;
  for (int i = 1; i < n - 1; i++)
    if (cross(pt[i], pt[i + 1]) < 0) k = i;
  if (k) {
  	int tot = 0;
  	for (int i = k + 1; i < n; i++) tmp[++tot] = pt[i];
  	for (int i = 1; i <= k; i++) tmp[++tot] = pt[i];
  	for (int i = 1; i < n; i++) pt[i] = tmp[i];
  }
  for (int i = 1; i < n - 1; i++)
    if (cx(pt[i]) != cx(pt[i + 1]))
      zm(pt[i], pt[i + 1]), ans.push_back(std::make_pair(pt[i], pt[i + 1])),
        std::swap(A[pt[i]], A[pt[i + 1]]);
  for (int i = 1; i < n; i++)
    ans.push_back(std::make_pair(O, A[O])), A[O] = A[A[O]];
  std::cout << ans.size() << std::endl;
  for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}