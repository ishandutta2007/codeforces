#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)

using ll = long long;

const int N = 200005;

int n, m, nc;

namespace rect_union {
  struct node {
    int cov, sum;
  } t[N * 4];

  void cover(int x, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
      t[x].cov += val;
      return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) cover(x << 1, l, mid, ql, qr, val);
    if (qr > mid) cover(x << 1 | 1, mid + 1, r, ql, qr, val);
    t[x].sum = (t[x << 1].cov ? mid - l + 1 : t[x << 1].sum) + (t[x << 1 | 1].cov ? r - mid : t[x << 1 | 1].sum);
  }

  struct line {
    int x;
    int yl, yr;
    int coef;
  } l[N * 8];
  line *lp = l;

  bool vis[105][105];

  void add(int xl, int xr, int yl, int yr) {
    if (xl > xr || yl > yr) return;
    *(lp++) = {xl, yl, yr, 1};
    *(lp++) = {xr + 1, yl, yr, -1};
  }

  ll solve() {
    sort(l, lp, [](const line &a, const line &b) { return a.x < b.x; });
    line *p = l;
    ll ans = 0;
    for (int i = 1; i <= nc; ++i) {
      for (; p != lp && p->x == i; ++p)
        cover(1, 1, nc, p->yl, p->yr, p->coef);
      ans += t[1].cov ? nc : t[1].sum;
    }
    return ans;
  }
}

vector<int> G[N];
char s[N];
int lb[N], rb[N], rt[N], dfc = 0;

void link(int x1, int y1, int x2, int y2) {
  if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) return;
  int idx = x1 * m + y1, idy = x2 * m + y2;
  G[idx].push_back(idy);
  G[idy].push_back(idx);
}

void DFS(int u, int root) {
  lb[u] = ++dfc; rt[u] = root;
  for (int v : G[u])
    if (!lb[v]) DFS(v, root);
  rb[u] = dfc;
}

void add_subt(int x, int y, int fx, int fy, pair<int, int> *r) {
  int u = x * m + y, f = fx * m + fy;
  int root = rt[u];
  if (fx < 0 || fx >= n || fy < 0 || fy >= m)
    r[0] = {lb[root], rb[root]};
  else if (lb[f] < lb[u])
    r[0] = {lb[u], rb[u]};
  else {
    int root = rt[u];
    r[0] = {lb[root], lb[f] - 1};
    r[1] = {rb[f] + 1, rb[root]};
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  nc = n * m;
  char *inp = s;
  for (int i = 0; i < n; ++i)
    scanf("%s", inp), inp += m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (s[i * m + j] == 'U') link(i, j, i + 2, j);
      else if (s[i * m + j] == 'D') link(i, j, i - 2, j);
      else if (s[i * m + j] == 'L') link(i, j, i, j + 2);
      else if (s[i * m + j] == 'R') link(i, j, i, j - 2);
    }
  for (int i = 0; i < nc; ++i)
    if (!lb[i]) DFS(i, i);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      static pair<int, int> xr[2], yr[2];
      int rtx = -1, rty = -1;
      memset(xr, -1, sizeof(xr));
      memset(yr, -1, sizeof(yr));
      if (s[i * m + j] == 'U') {
        rtx = rt[i * m + j];
        rty = rt[(i + 1) * m + j];
        add_subt(i, j, i + 2, j, xr);
        add_subt(i + 1, j , i - 1, j, yr);
      }
      else if (s[i * m + j] == 'L') {
        rtx = rt[i * m + j];
        rty = rt[i * m + j + 1];
        add_subt(i, j, i, j + 2, xr);
        add_subt(i, j + 1, i, j - 1, yr);
      }
      if (rtx == -1) continue;
      if (rtx > rty)
        swap(xr, yr);
      for (int p : {0, 1})
        for (int q : {0, 1})
          if (~xr[p].first && ~yr[q].first)
            rect_union::add(xr[p].first, xr[p].second, yr[q].first, yr[q].second);
    }
  ll ans = rect_union::solve();
  printf("%lld\n", ans);
  return 0;
}