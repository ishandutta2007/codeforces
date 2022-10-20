// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt")
// #define NDEBUG

#include <bits/extc++.h>
#include <x86intrin.h>

struct rep {
  struct iter {
    int i;
    constexpr void operator++() { ++i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr rep(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr rep(int n) : rep(0, n) {}
  constexpr iter begin() const { return {l}; }
  constexpr iter end() const { return {r}; }
};
struct per {
  struct iter {
    int i;
    constexpr void operator++() { --i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr per(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr per(int n) : per(0, n) {}
  constexpr iter begin() const { return {r - 1}; }
  constexpr iter end() const { return {l - 1}; }
};
template <class T, class U>
constexpr bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

namespace atcoder {

namespace internal {

template <class T>
struct simple_queue {
  std::vector<T> payload;
  int pos = 0;
  void reserve(int n) { payload.reserve(n); }
  int size() const { return int(payload.size()) - pos; }
  bool empty() const { return pos == int(payload.size()); }
  void push(const T& t) { payload.push_back(t); }
  T& front() { return payload[pos]; }
  void clear() {
    payload.clear();
    pos = 0;
  }
  void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

template <class Cap>
struct mf_graph {
 public:
  mf_graph() : _n(0) {}
  mf_graph(int n) : _n(n), g(n) {}

  int add_edge(int from, int to, Cap cap) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    assert(0 <= cap);
    int m = int(pos.size());
    pos.push_back({from, int(g[from].size())});
    int from_id = int(g[from].size());
    int to_id = int(g[to].size());
    if (from == to) to_id++;
    g[from].push_back(_edge{to, to_id, cap});
    g[to].push_back(_edge{from, from_id, 0});
    return m;
  }

  struct edge {
    int from, to;
    Cap cap, flow;
  };

  edge get_edge(int i) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    auto _e = g[pos[i].first][pos[i].second];
    auto _re = g[_e.to][_e.rev];
    return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
  }
  std::vector<edge> edges() {
    int m = int(pos.size());
    std::vector<edge> result;
    for (int i = 0; i < m; i++) {
      result.push_back(get_edge(i));
    }
    return result;
  }
  void change_edge(int i, Cap new_cap, Cap new_flow) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    assert(0 <= new_flow && new_flow <= new_cap);
    auto& _e = g[pos[i].first][pos[i].second];
    auto& _re = g[_e.to][_e.rev];
    _e.cap = new_cap - new_flow;
    _re.cap = new_flow;
  }

  Cap flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }
  Cap flow(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);

    std::vector<int> level(_n), iter(_n);
    internal::simple_queue<int> que;

    auto bfs = [&]() {
      std::fill(level.begin(), level.end(), -1);
      level[s] = 0;
      que.clear();
      que.push(s);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto e : g[v]) {
          if (e.cap == 0 || level[e.to] >= 0) continue;
          level[e.to] = level[v] + 1;
          if (e.to == t) return;
          que.push(e.to);
        }
      }
    };
    auto dfs = [&](auto self, int v, Cap up) {
      if (v == s) return up;
      Cap res = 0;
      int level_v = level[v];
      for (int& i = iter[v]; i < int(g[v].size()); i++) {
        _edge& e = g[v][i];
        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
        Cap d = self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
        if (d <= 0) continue;
        g[v][i].cap += d;
        g[e.to][e.rev].cap -= d;
        res += d;
        if (res == up) break;
      }
      return res;
    };

    Cap flow = 0;
    while (flow < flow_limit) {
      bfs();
      if (level[t] == -1) break;
      std::fill(iter.begin(), iter.end(), 0);
      while (flow < flow_limit) {
        Cap f = dfs(dfs, t, flow_limit - flow);
        if (!f) break;
        flow += f;
      }
    }
    return flow;
  }

  std::vector<bool> min_cut(int s) {
    std::vector<bool> visited(_n);
    internal::simple_queue<int> que;
    que.push(s);
    while (!que.empty()) {
      int p = que.front();
      que.pop();
      visited[p] = true;
      for (auto e : g[p]) {
        if (e.cap && !visited[e.to]) {
          visited[e.to] = true;
          que.push(e.to);
        }
      }
    }
    return visited;
  }

 private:
  int _n;
  struct _edge {
    int to, rev;
    Cap cap;
  };
  std::vector<std::pair<int, int>> pos;
  std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder

template <class Cap>
struct max_flow {
  struct result {
    bool feasible;
    Cap total_flow;
    std::vector<Cap> flow;
  };

  max_flow() {}
  explicit max_flow(int n) : g(n + 2), b(n) {}

  int size() const { return std::size(b); }
  int add_edge(int src, int dst, Cap lower, Cap upper) {
    assert(0 <= src), assert(src < size());
    assert(0 <= dst), assert(dst < size());
    assert(lower <= upper);
    b[src] -= lower;
    b[dst] += lower;
    res.flow.push_back(lower);
    return g.add_edge(src, dst, upper - lower);
  }

  result flow() {
    int source = size(), sink = source + 1;
    Cap to_flow{};
    for (int v = 0; v < size(); ++v)
      if (b[v] > 0) {
        g.add_edge(source, v, b[v]);
        to_flow += b[v];
      } else if (b[v] < 0) {
        g.add_edge(v, sink, -b[v]);
      }
    to_flow -= g.flow(source, sink);
    if (to_flow) return {};
    res.feasible = true;
    for (int i = 0; i < int(std::size(res.flow)); ++i)
      res.flow[i] += g.get_edge(i).flow;
    return res;
  }
  result flow(int s, int t, int objective = 0) {
    assert(0 <= s), assert(s < size());
    assert(0 <= t), assert(t < size());
    assert(-1 <= objective), assert(objective <= 1);
    int id = g.add_edge(t, s, std::numeric_limits<Cap>::max());
    int source = size(), sink = source + 1;
    Cap to_flow{};
    for (int v = 0; v < size(); ++v)
      if (b[v] > 0) {
        g.add_edge(source, v, b[v]);
        to_flow += b[v];
      } else if (b[v] < 0) {
        g.add_edge(v, sink, -b[v]);
      }
    to_flow -= g.flow(source, sink);
    if (to_flow) return {};
    res.feasible = true;
    res.total_flow = g.get_edge(id).flow;
    if (objective > 0) {
      g.change_edge(id, 0, 0);
      res.total_flow += g.flow(s, t);
    } else if (objective < 0) {
      g.change_edge(id, 0, 0);
      res.total_flow -= g.flow(t, s);
    }
    for (int i = 0; i < id; ++i) res.flow[i] += g.get_edge(i).flow;
    return res;
  }

  atcoder::mf_graph<Cap> g;

 private:
  std::vector<Cap> b;
  result res{};
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  constexpr array di{1, 0, -1, 0};
  constexpr array dj{0, 1, 0, -1};

  int tt;
  cin >> tt;
  while (tt--) {
    int h, w;
    cin >> h >> w;
    vector s(h, vector<int>(w));
    for (int i : rep(h))
      for (int j : rep(w)) cin >> s[i][j];

    auto in = [&](int i, int j) -> bool {
      return 0 <= i and i < h and 0 <= j and j < w;
    };

    auto good = [&](int i, int j) -> bool {
      for (int k : rep(4)) {
        int ni = i + di[k], nj = j + dj[k];
        if (in(ni, nj) and s[ni][nj] < s[i][j]) return true;
      }
      return false;
    };

    int source = h * w, sink = source + 1;
    max_flow<int> g(sink + 1);
    vector<int> id(h * w);
    for (int i : rep(h))
      for (int j : rep(w)) {
        int v = i * w + j;
        if (i and s[i - 1][j] == s[i][j]) {
          int u = (i - 1) * w + j;
          if ((i + j) & 1)
            g.add_edge(u, v, 0, 1);
          else
            g.add_edge(v, u, 0, 1);
        }
        if (j and s[i][j - 1] == s[i][j]) {
          int u = i * w + (j - 1);
          if ((i + j) & 1)
            g.add_edge(u, v, 0, 1);
          else
            g.add_edge(v, u, 0, 1);
        }
        int lower = not good(i, j);
        if ((i + j) & 1)
          id[v] = g.add_edge(v, sink, lower, 1);
        else
          id[v] = g.add_edge(source, v, lower, 1);
      }

    auto res = g.flow(source, sink);
    if (not res.feasible) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";

    vector<int> match(h * w, -1);
    for (int i : rep(size(res.flow))) {
      auto e = g.g.get_edge(i);
      if (e.flow == 0) continue;
      if (e.from == source) continue;
      if (e.to == sink) continue;
      match[e.from] = e.to;
      match[e.to] = e.from;
    }

    vector<string> ans(h, string(w, '?'));
    for (int i : rep(h))
      for (int j : rep(w))
        if (match[i * w + j] != -1) {
          if ((i + j) & 1) {
            cout << 1 << " \n"[j == w - 1];
          } else {
            cout << s[i][j] - 1 << " \n"[j == w - 1];
          }
          int ni = match[i * w + j] / w;
          int nj = match[i * w + j] % w;
          for (int k : rep(4))
            if (ni == i + di[k] and nj == j + dj[k]) {
              ans[i][j] = "DRUL"[k];
              break;
            }
        } else {
          for (int k : rep(4)) {
            int ni = i + di[k], nj = j + dj[k];
            if (in(ni, nj) and s[ni][nj] < s[i][j]) {
              cout << s[i][j] - s[ni][nj] << " \n"[j == w - 1];
              ans[i][j] = "DRUL"[k];
              break;
            }
          }
        }

    for (int i : rep(h))
      for (int j : rep(w)) cout << ans[i][j] << " \n"[j == w - 1];
  }
}