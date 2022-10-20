#include <bits/stdc++.h>
using namespace std;

char readchar() {
  static char buf[1 << 15], *ptr = buf, *end = buf;
  if (ptr == end) ptr = buf, end = buf + fread(buf, 1, 1 << 15, stdin);
  return *ptr++;
}
void writechar(char c = 0) {
  static char buf[1 << 15], *ptr = buf;
  if (ptr == end(buf) or c == 0) fwrite(buf, 1, ptr - buf, stdout), ptr = buf;
  *ptr++ = c;
}
template <class Z = int> Z getint() {
  char c = readchar();
  bool neg = c == '-';
  Z res = neg ? 0 : c - '0';
  while (isdigit(c = readchar())) res = res * 10 + (c - '0');
  return neg ? -res : res;
}
template <class Z> void putint(Z a, char delim = '\n') {
  if (a < 0) writechar('-'), a = -a;
  int d[40], i = 0;
  do d[i++] = a % 10; while (a /= 10);
  while (i--) writechar('0' + d[i]);
  writechar(delim);
}

template <class T, bool SortEdges = false> class static_graph {
  struct edge {
    int to;
    operator int() const { return to; }
  };
  template <class It> struct edge_list {
    const It first, last;
    It begin() const { return first; }
    It end() const { return last; }
    auto&& operator[](size_t i) const { return first[i]; }
    size_t size() const { return last - first; }
  };
  vector<pair<int, edge>> edge_pool;
  vector<int> head;
  void build() {
    partial_sum(begin(head), end(head), begin(head));
    for (auto&& [v, e] : edge_pool) edges[--head[v]] = e;
    decltype(edge_pool)().swap(edge_pool);
    if (not SortEdges) return;
    for (int v = 0; v < (int)size(); ++v)
      sort(begin((*this)[v]), end((*this)[v]),
           [](const auto& a, const auto& b) { return a.to < b.to; });
  }
public:
  vector<edge> edges;
  static_graph(int n, int m) : head(n + 1), edges(m) {}
  void add(int from, int to) {
    static size_t edge_count = 0;
    assert(edge_count < std::size(edges));
    edge_pool.push_back({from, {to}});
    ++head[from];
    if (++edge_count == std::size(edges)) build();
  }
  edge_list<class vector<edge>::const_iterator> operator[](int v) const {
    return {begin(edges) + head[v], begin(edges) + head[v + 1]};
  }
  edge_list<class vector<edge>::iterator> operator[](int v) {
    return {begin(edges) + head[v], begin(edges) + head[v + 1]};
  }
  size_t size() const { return std::size(head) - 1; }
};

int main() {
  int n = getint(), m = getint();
  static_graph<int> g(n, 2 * m);
  while (m--) {
    int a = getint() - 1, b = getint() - 1;
    g.add(a, b);
    g.add(b, a);
  }
  int k = 0;
  while (k * k < n) {
    ++k;
  }
  vector dep(n, -1), par(n, -1);
  auto dfs = [&](auto&& self, int v) -> void {
    for (int u : g[v]) {
      if (dep[u] == -1) {
        dep[u] = dep[v] + 1;
        par[u] = v;
        self(self, u);
      } else if (dep[v] - dep[u] >= k - 1) {
        putint(2);
        putint(dep[v] - dep[u] + 1);
        while (v != u) {
          putint(v + 1, ' ');
          v = par[v];
        }
        putint(u + 1);
        writechar();
        exit(0);
      }
    }
  };
  dep[0] = 0;
  dfs(dfs, 0);
  vector<vector<int>> vs(k - 1);
  for (int v = 0; v < n; ++v) {
    vs[dep[v] % (k - 1)].push_back(v);
  }
  for (auto&& e : vs) {
    if ((int)size(e) >= k) {
      putint(1);
      for (int i = 0; i < k; ++i) {
        putint(e[i] + 1, " \n"[i == k - 1]);
      }
      break;
    }
  }
  writechar();
}