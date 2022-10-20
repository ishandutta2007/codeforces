#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x), read(args...); }

template<class cap_t, class val_t, size_t node_c, size_t edge_c>
struct maxflow_graph {
  static_assert(sizeof(val_t) >= sizeof(cap_t), "result may overflow");

  struct edge {
    int v;
    cap_t f;
  } E[edge_c * 2];
  vector<int> G[node_c];
  size_t cur[node_c];
  int ec = 0;
  int s, t, nc;
  int h[node_c];

  void clear() {
    ec = 0;
    for (size_t i = 0; i < node_c; ++i) G[i].clear();
  }

  void link(int x, int y, int flow) {
    G[x].push_back(ec); E[ec++] = {y, flow};
    G[y].push_back(ec); E[ec++] = {x, 0};
  }

  bool bfs() {
    memset(h, -1, sizeof(int) * nc);
    h[s] = 0;
    int *q = new int[node_c], *ql = q - 1, *qr = q;
    *qr = s;
    while (ql != qr) {
      int x = *(++ql);
      if (x == t) break;
      for (int i : G[x]) {
        if (E[i].f != 0 && h[E[i].v] == -1)
          h[E[i].v] = h[x] + 1, *(++qr) = E[i].v;
      }
    }
    delete[] q;
    return h[t] != -1;
  }

  val_t augment(int x, val_t flow) {
    if (x == t) return flow;
    val_t res = 0;
    for (size_t &i = cur[x]; i != G[x].size(); ++i) {
      edge &e = E[G[x][i]];
      if (!e.f || h[e.v] != h[x] + 1) continue;
      cap_t aug = min<val_t>(e.f, flow);
      aug = augment(e.v, aug);
      res += aug; flow -= aug;
      e.f -= aug; E[G[x][i] ^ 1].f += aug;
      if (!flow) break;
    }
    if (!res) h[x] = -1;
    return res;
  }

  val_t maxflow() {
    int round = 0;
    val_t flow = 0;
    while (bfs()) {
      memset(cur, 0, sizeof(size_t) * nc);
      flow += augment(s, numeric_limits<val_t>::max());
      ++round;
    }
    return flow;
  }
};

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

maxflow_graph<int, ll, 2005, 3005> F;

map<pair<int, int>, pair<int, int>> P;

int id(int x, int y) { return ((y & 1) << 1) | ((x & 1) ^ (y & 1) ^ 1); }

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  ll sum = 0;
  F.s = 0; F.t = 2 * n + 1; F.nc = 2 * n + 2;
  for (int i = 1; i <= n; ++i) {
    int x, y, wt;
    read(x, y, wt);
    sum += wt;
    P[{x, y}] = {i, wt};
    F.link(2 * i - 1, 2 * i, wt);
  }
  for (const auto &[co, val] : P) {
    int ID = id(co.first, co.second);
    if (ID == 0) F.link(F.s, val.first * 2 - 1, numeric_limits<int>::max());
    if (ID == 3) F.link(val.first * 2, F.t, numeric_limits<int>::max());
    for (int d = 0; d < 4; ++d) {
      int x = co.first + dx[d], y = co.second + dy[d];
      auto it = P.find({x, y});
      if (it != P.end()) {
        if (id(x, y) == ID + 1)
          F.link(val.first * 2, it->second.first * 2 - 1, numeric_limits<int>::max());
      }
    }
  }
  printf("%lld\n", sum - F.maxflow());
  return 0;
}