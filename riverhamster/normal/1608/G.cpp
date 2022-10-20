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
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
 
using ll = long long;
using ull = unsigned long long;
 
template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }
 
const int N = 200005;
const int M = 0x7fffffff;
const int B = 181;
const int logN = 18;

int reduce(ull x) {
  x = (x >> 31) + (x & M);
  return x >= M ? x - M : x;
}
 
char _get() {
  char c;
  while (isspace(c = getchar()));
  return c;
}
 
int bit[N];
void insert(int p, int v) {
  for (; p < N; p += p & -p)
    bit[p] += v;
}
int query(int p) {
  int s = 0;
  for (; p; p &= p - 1)
    s += bit[p];
  return s;
}
 
struct q2d {
  int id, coef;
  int x, l, r;
};
vector<q2d> que;
 
char s[N];
int sa[N], rk[N], tp[N], ht[N], len, m;
int bel[N];
int n, sc, qc;
int ans[N];
int st[logN][N];
 
void radixSort() {
  static int pos[N];
  fill_n(pos, m + 1, 0);
  for (int i = 0; i < len; i++)
    ++pos[rk[i]];
  for (int i = 1; i <= m; i++)
    pos[i] += pos[i - 1];
  for (int i = len - 1; i >= 0; i--)
    sa[--pos[rk[tp[i]]]] = tp[i];
}
void buildSA() {
  m = 27;
  for (int i = 0; i < len; i++)
    rk[i] = s[i] - 'a', tp[i] = i;
  radixSort();
 
  for (int w = 1, p = 0; p + 1 < len; m = p, w <<= 1) {
    p = 0;
    for (int i = len - w; i < len; i++)
      tp[p++] = i;
    for (int i = 0; i < len; i++)
      if (sa[i] >= w)
        tp[p++] = sa[i] - w;
    radixSort();
 
    copy_n(rk, len, tp);
    rk[sa[0]] = 0;
    p = 0;
    for (int i = 1; i < len; i++)
      if (tp[sa[i]] == tp[sa[i - 1]] && sa[i] + w < len && sa[i - 1] + w < len &&
          tp[sa[i] + w] == tp[sa[i - 1] + w])
        rk[sa[i]] = p;
      else
        rk[sa[i]] = ++p;
  }
 
  int p = 0;
  for (int i = 0; i < len; i++) {
    if (p)
      --p;
    if (rk[i] == 0)
      continue;
    int j = sa[rk[i] - 1];
    while (s[i + p] == s[j + p])
      ++p;
    ht[rk[i] - 1] = p;
  }
}
 
void buildST() {
  for (int i = 0; i < len; i++)
    st[0][i] = ht[i];
  for (int i = 1; i <= __lg(len); i++)
    for (int j = 0; j + (1 << i) - 1 < len; j++)
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
 
vector<pair<int, char>> G[100005];
int fa[100005][logN], up[100005][logN];
int down[100005];
int npb[N], pb[N];
int h[N * 2];
int dep[N];
 
int range(int l, int r) { // [l, r)
  return reduce(h[r] + (ll)npb[r - l] * h[l]);
}
 
void DFS(int u) {
  for (int i = 1; i <= 16; ++i)
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = 1; i <= 16; ++i)
    up[u][i] = reduce((ull)up[u][i - 1] * pb[1 << (i - 1)] + up[fa[u][i - 1]][i - 1]);
  for (auto [v, c] : G[u]) {
    if (v == fa[u][0]) continue;
    fa[v][0] = u;
    up[v][0] = c;
    down[v] = reduce((ull)down[u] * B + c);
    dep[v] = dep[u] + 1;
    DFS(v);
  }
}
 
int LCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int d = dep[u] - dep[v], i = 0; d; d >>= 1, ++i)
    if (d & 1) u = fa[u][i];
  if (u == v) return u;
  for (int i = 16; i >= 0; --i)
    if (fa[u][i] != fa[v][i])
      u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
 
int checkgt(int pr, int u, int v, int L) {
  for (int i = __lg(dep[u] - dep[L]); i >= 0; --i) {
    if (dep[u] - dep[L] < (1 << i)) continue;
    int hsh = range(pr, pr + (1 << i));
    if (hsh == up[u][i]) u = fa[u][i], pr += 1 << i;
  }
  if (u != L) return s[pr] >= up[u][0];
  if (v == L) return 3;
  for (int i = __lg(dep[v] - dep[L]); i >= 0; --i) {
    if (dep[v] - dep[L] < (1 << i)) continue;
    int rem = dep[v] - dep[L] - (1 << i);
    int _v = fa[v][i];
    int str_hsh = range(pr, pr + rem);
    int tree_hsh = reduce(down[_v] + (ull)npb[rem] * down[L]);
    if (str_hsh != tree_hsh)
      v = _v;
  }
  pr += dep[v] - dep[L] - 1;
  if (s[pr] == up[v][0]) return 3;
  return s[pr] >= up[v][0];
}
 
void solve(int u, int v, int ql, int qr, int qid) {
  int l = 0, r = len - 1, mid, resl = 0, resr = 0;
  int L = LCA(u, v);
  int dist = dep[u] + dep[v] - 2 * dep[L];
  bool equ = false;
  while (l <= r) {
    mid = (l + r) >> 1;
    int ret = checkgt(sa[mid], u, v, L);
    if (ret) {
      resl = mid;
      equ |= ret & 2;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  if (!equ) return;
  resr = resl;
  
  for (int i = 16; i >= 0; --i) {
    int p = resr + (1 << i);
    if (p < len && st[i][resr] >= dist)
      resr = p;
  }
  if (resl) que.push_back(q2d{qid, -1, resl - 1, ql, qr});
  que.push_back(q2d{qid, 1, resr, ql, qr});
}
 
void count2d() {
  sort(all(que), [](q2d a, q2d b) { return a.x < b.x; });
  auto it = que.begin();
 
  for (int i = 0; i < len; ++i) {
    insert(bel[sa[i]], 1);
    while (it != que.end() && it->x == i) {
      ans[it->id] += it->coef * (query(it->r) - query(it->l - 1));
      ++it;
    }
  }
}
 
int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, sc, qc);
  for (int i = 1; i < n; ++i) {
    int u, v;
    char c;
    read(u, v);
    c = _get();
    G[u].emplace_back(v, c); G[v].emplace_back(u, c);
  }
  pb[0] = 1;
  for (int i = 1; i <= n; ++i)
    pb[i] = reduce((ll)pb[i - 1] * B);
  for (int i = 0; i <= n; ++i)
    npb[i] = M - pb[i];
  DFS(1);
 
  char *_p = s;
  for (int i = 1; i <= sc; ++i) {
    scanf("%s", _p);
    while (*_p) {
      bel[_p - s] = i;
      ++_p;
    }
    bel[_p - s] = sc + 1;
    *(_p++) = 'z' + 1;
  }
  len = _p - s;
  for (int i = 0; i < len; ++i)
    h[i + 1] = reduce((ull)h[i] * B + s[i]);
  for (int i = len; i < N * 2; ++i)
    h[i + 1] = reduce((ull)h[i] * B + 1);
 
  buildSA();
  buildST();
 
  for (int i = 1; i <= qc; ++i) {
    int u, v, l, r;
    read(u, v, l, r);
    solve(u, v, l, r, i);
  }
  count2d();
  for (int i = 1; i <= qc; ++i)
    printf("%d\n", ans[i]);
  return 0;
}