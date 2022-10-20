#ifndef OJ
#define OJ 1
#define NDEBUG
#define DUMP(...) void()
#endif

#include <bits/stdc++.h>

#define LAMBDA(...)                                                                                                 \
  [&]<class T1 = int, class T2 = int>([[maybe_unused]] T1&& _1 = 0, [[maybe_unused]] T2&& _2 = 0)->decltype(auto) { \
    return __VA_ARGS__;                                                                                             \
  }

namespace rng = std::ranges;
namespace vw = rng::views;
template <class T, class Alloc = std::allocator<T>> using Vec = std::vector<T, Alloc>;
using std::cin, std::cout;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int n; cin >> n;) {
    ++n;
    Vec<int> a(n), b(n);
    for (int i : vw::iota(1, n)) cin >> a[i];
    for (int i : vw::iota(1, n)) cin >> b[i];

    Vec<Vec<std::pair<int, int>>> g(3 * n);
    for (int i : vw::iota(1, n)) {
      g[n + i].emplace_back(n + n + (i + b[i]), 0);
    }
    for (int i : vw::iota(1, n)) {
      g[i].emplace_back(2 * i, 0);
      g[i].emplace_back(2 * i + 1, 0);
    }
    for (int i : vw::iota(1, n)) {
      int l = i - a[i];
      int r = i + 1;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) g[n + n + i].emplace_back(l++, 1);
        if (r & 1) g[n + n + i].emplace_back(--r, 1);
      }
    }

    int s = n + (n - 1);
    const int inf = 1e9;
    Vec<int> dist(3 * n, inf);
    dist[s] = 0;
    Vec<int> prev(3 * n, -1);
    std::deque deq{s};
    while (!deq.empty()) {
      int v = deq.front();
      deq.pop_front();
      for (auto [u, w] : g[v]) {
        if (int t = dist[v] + w; t < dist[u]) {
          dist[u] = t;
          prev[u] = v;
          if (w)
            deq.push_back(u);
          else
            deq.push_front(u);
        }
      }
    }

    if (dist[n] == inf) {
      cout << "-1\n";
    } else {
      cout << dist[n] << '\n';
      Vec<int> ans;
      ans.reserve(dist[n]);
      for (int v = n; v != s; v = prev[v]) {
        if (n <= v && v < n + n) ans.push_back(v - n);
      }
      rng::reverse(ans);
      assert(int(ans.size()) == dist[n]);
      for (int i : vw::iota(0, dist[n])) cout << ans[i] << " \n"[i + 1 == dist[n]];
    }
  }
}