#include <bits/stdc++.h>

void solve(std::istream&, std::ostream&);

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve(std::cin, std::cout);
}

// https://kopricky.github.io/code/DataStructure_Advanced/convex_hull_trick.html
namespace kopricky {

using namespace std;

// f[j](x) = a[j]x + b[j]aj
//x
template <typename T>
class CHT {
 private:
  using ptt = pair<T, T>;
  bool check(ptt l1, ptt l2, ptt l3) {
    return (l2.first - l1.first) * (l3.second - l2.second) >=
           (l2.second - l1.second) * (l3.first - l2.first);
  }
  T f(int i, T x) { return lines[i].first * x + lines[i].second; }

 public:
  vector<ptt> lines;
  int head;
  CHT() : head(0){};
  void add(T a, T b) {
    ptt line(a, b);
    while ((int)lines.size() - head >= 2 &&
           check(*(lines.end() - 2), lines.back(), line)) {
      lines.pop_back();
    }
    lines.emplace_back(line);
  }
  T get(T x) {
    while ((int)lines.size() - head >= 2 && f(head, x) >= f(head + 1, x)) {
      head++;
    }
    return f(head, x);
    // int low = -1, high = lines.size() - 1;
    // while (high - low > 1) {
    // 	int mid = (high + low) / 2;
    //     if(f(mid, x) >= f(mid+1, x)){
    //         low = mid;
    //     }else{
    //         high = mid;
    //     }
    // }
    // return f(high, x);
  }
};

}  // namespace kopricky

using namespace std::literals;

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  int n, m, k;
  is >> n >> m >> k;

  std::vector<std::vector<std::pair<int, int>>> g(n);
  while (m--) {
    int u, v, w;
    is >> u >> v >> w;
    --u;
    --v;

    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  i64 const inf = std::numeric_limits<i64>::max();

  std::vector<i64> d(n, inf);
  d[0] = 0;

  auto dijkstra = [&] {
    std::priority_queue pq{std::greater(), std::vector<std::pair<i64, int>>()};
    for (int v = 0; v < n; ++v) {
      if (d[v] < inf) {
        pq.emplace(d[v], v);
      }
    }
    while (!pq.empty()) {
      auto [dv, v] = pq.top();
      pq.pop();
      if (d[v] < dv) {
        continue;
      }
      for (auto [u, w] : g[v]) {
        if (d[v] + w < d[u]) {
          d[u] = d[v] + w;
          pq.emplace(d[u], u);
        }
      }
    }
  };

  dijkstra();

  while (k--) {
    {
      kopricky::CHT<i64> cht;
      for (int u = 0; u < n; ++u) {
        if (d[u] < inf) {
          cht.add(-2 * u, d[u] + i64(u) * u);
        }
      }

      for (int v = 0; v < n; ++v) {
        d[v] = cht.get(v) + i64(v) * v;
      }
    }

    dijkstra();
  }

  for (int v = 0; v < n; ++v) {
    os << d[v] << " \n"[v + 1 == n];
  }
}