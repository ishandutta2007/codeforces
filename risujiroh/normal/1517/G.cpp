#include <bits/stdc++.h>

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

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l_, r_;
  Rep(int l, int r) : l_(l), r_(r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l_}; }
  I end() const { return {r_}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l_, r_;
  Per(int l, int r) : l_(l), r_(r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r_ - 1}; }
  I end() const { return {l_ - 1}; }
};

template <class F>
struct Fix : private F {
  Fix(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T = int>
T scan() {
  T res;
  std::cin >> res;
  return res;
}

template <class T, class U = T>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

#ifndef LOCAL
#define DUMP(...) void(0)
template <int OnlineJudge, int Local>
constexpr int OjLocal = OnlineJudge;
#endif

using namespace std;

#define ALL(c) begin(c), end(c)

#pragma endregion

constexpr auto Inf = numeric_limits<int64_t>::max() / 2;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector<int> x(n), y(n), w(n);
  map<pair<int, int>, int> mp;
  for (int i : Rep(n)) {
    x[i] = scan();
    y[i] = scan();
    w[i] = scan();
    mp[{x[i], y[i]}] = i;
  }
  atcoder::mf_graph<int64_t> g(2 * n + 2);
  for (int i : Rep(n)) {
    g.add_edge(2 * i, 2 * i + 1, w[i]);
    if (x[i] & 1) {
      if (y[i] & 1)
        g.add_edge(2 * n, 2 * i, Inf);
      else
        g.add_edge(2 * i + 1, 2 * n + 1, Inf);
    }
    if ((x[i] + y[i]) & 1) {
      for (int ny : {y[i] + 1, y[i] - 1})
        if (mp.count({x[i], ny}))
          g.add_edge(2 * i + 1, 2 * mp[{x[i], ny}], Inf);
    } else {
      for (int nx : {x[i] + 1, x[i] - 1})
        if (mp.count({nx, y[i]}))
          g.add_edge(2 * i + 1, 2 * mp[{nx, y[i]}], Inf);
    }
  }
  cout << accumulate(ALL(w), int64_t(0)) - g.flow(2 * n, 2 * n + 1) << '\n';
}