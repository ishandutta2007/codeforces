#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}

template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << ' ' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

constexpr int inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  struct Edge {
    int to, w;
  };
  vector< vector<Edge> > g(n + 2);
  int odd = n, even = n + 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] & 1) {
      g[odd].emplace_back(Edge{i, 0});
    } else {
      g[even].emplace_back(Edge{i, 0});
    }
    if (i - a[i] >= 0) {
      g[i - a[i]].emplace_back(Edge{i, 1});
    }
    if (i + a[i] < n) {
      g[i + a[i]].emplace_back(Edge{i, 1});
    }
  }
  auto bfs = [&](int s) {
    deque<int> deq{s};
    vector<int> d(n + 2, inf);
    d[s] = 0;
    while (not deq.empty()) {
      int v = deq.front();
      deq.pop_front();
      for (auto e : g[v]) {
        if (d[e.to] <= d[v] + e.w) {
          continue;
        }
        d[e.to] = d[v] + e.w;
        if (e.w == 0) {
          deq.push_front(e.to);
        } else {
          deq.push_back(e.to);
        }
      }
    }
    return d;
  };
  auto d_odd = bfs(odd);
  auto d_even = bfs(even);
  DEBUG(d_odd);
  DEBUG(d_even);
  for (int i = 0; i < n; ++i) {
    int res = -1;
    if (a[i] & 1) {
      res = d_even[i];
    } else {
      res = d_odd[i];
    }
    if (res == inf) {
      res = -1;
    }
    cout << res << " \n"[i == n - 1];
  }
}