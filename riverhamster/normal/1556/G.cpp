#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <unistd.h>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int MAXM = 50005;
const int MAXN = 51;

namespace DSU {
  int fa[MAXN * MAXM * 2];
  int find(int x) {
    while (fa[x] != x)
      x = fa[x] = fa[fa[x]];
    return x;
  }
  void join(int u, int v) {
    if (!u || !v) return;
    u = find(u), v = find(v);
    if (u == v) return;
    fa[u] = v;
  }
  int nc;
}
using DSU::find;
using DSU::join;

int n, m;

struct operation {
  bool type;
  int t;
  ll l, r;
} a[MAXM];

struct node {
  int rep;
  int c[2];
  bool same;
} t[MAXN * MAXM * 6];
int tree_nc = 0;
int rt = 0;

vector<int> loc;
vector<int>::const_iterator loc_it;

void down(int x) {
  if (t[x].rep) {
    if (t[x].c[0]) t[t[x].c[0]].rep = t[x].rep;
    if (t[x].c[1]) t[t[x].c[1]].rep = t[x].rep;
  }
}

void locate(int &x, ll l, ll r, ll ql, ll qr) {
  if (!x) x = ++tree_nc;
  if (ql <= l && r <= qr) {
    t[x].rep = ++DSU::nc;
    DSU::fa[DSU::nc] = DSU::nc;
    loc.push_back(DSU::nc);
    return;
  }
  down(x);
  ll mid = (l + r) >> 1;
  if (ql <= mid) locate(t[x].c[0], l, mid, ql, qr);
  if (qr > mid) locate(t[x].c[1], mid + 1, r, ql, qr);
}

void join_subtree(int x, int dest) {
  if (t[x].rep) {
    join(t[x].rep, dest);
    t[x].rep = find(t[x].rep);
    return;
  }
  if (t[x].c[0]) join_subtree(t[x].c[0], dest);
  if (t[x].c[1]) join_subtree(t[x].c[1], dest);
}

int _bit_flip;
void bit_flip_locate(int x, ll l, ll r, ll ql, ll qr, int bit, int cover = 0) {
  if (ql <= l && r <= qr) {
    if (!x) join(cover, *(loc_it++));
    else join_subtree(x, *(loc_it++));
    return;
  }
  if (t[x].rep) cover = t[x].rep;
  down(x);
  ll mid = (l + r) >> 1;
  if (ql <= mid) bit_flip_locate(t[x].c[0 ^ (bit == _bit_flip)], l, mid, ql, qr, bit - 1, cover);
  if (qr > mid) bit_flip_locate(t[x].c[1 ^ (bit == _bit_flip)], mid + 1, r, ql, qr, bit - 1, cover);
}

void add(ll l, ll r) {
  assert(l <= r);
  loc.clear();
  locate(rt, 0, (1LL << n) - 1, l, r);
  for (_bit_flip = 0; _bit_flip < n; ++_bit_flip) {
    loc_it = cbegin(loc);
    bit_flip_locate(rt, 0, (1LL << n) - 1, l, r, n - 1);
  }
}

int _find_pass(int x, ll v) {
  if (t[x].rep)
    return find(t[x].rep);
  return _find_pass(t[x].c[(v >> (n - 1)) & 1], v << 1);
}
int tree_find(ll x) { return _find_pass(1, x); }

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, m);
  for (int i = 0; i < m; ++i) {
    static char opt[10];
    scanf("%s%lld%lld", opt, &a[i].l, &a[i].r);
    a[i].t = i;
    a[i].type = (*opt == 'b');
  }
  sort(a, a + m, [](const auto &a, const auto &b) { return a.l < b.l; });

  ll last = -1;
  for (int i = 0; i < m; ++i) {
    if (!a[i].type) continue;
    if (a[i].l > last + 1)
      add(last + 1, a[i].l - 1);
    last = a[i].r;
  }
  if (last < (1LL << n) - 1)
    add(last + 1, (1LL << n) - 1);

  sort(a, a + m, [](const auto &a, const auto &b) { return a.t > b.t; });

  vector<char> ans;
  for (int i = 0; i < m; ++i) {
    if (a[i].type)
      add(a[i].l, a[i].r);
    else
      ans.push_back(tree_find(a[i].l) == tree_find(a[i].r));
  }

  reverse(all(ans));
  for (char c : ans)
    putchar(c + '0'), putchar('\n');
  return 0;
}