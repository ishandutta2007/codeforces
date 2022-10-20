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
  int num_cases;
  cin >> num_cases;
  for (int n; cin >> n;) {
    Vec<int> count(30);
    for (int _ = n; _--;) {
      int a;
      cin >> a;
      for (int i : vw::iota(0, 30)) count[i] += a >> i & 1;
    }
    int g = std::accumulate(count.begin(), count.end(), 0, LAMBDA(std::gcd(_1, _2)));
    for (int k : vw::iota(1, n + 1) | vw::filter(LAMBDA(g % _1 == 0))) cout << k << ' ';
    cout << '\n';
  }
}