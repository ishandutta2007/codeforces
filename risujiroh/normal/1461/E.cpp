#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

struct Splitmix64Hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t r =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + r);
  }
};
template <class Key, class T>
using HashMap = __gnu_pbds::gp_hash_table<Key, T, Splitmix64Hash>;
template <class Key>
using HashSet = HashMap<Key, __gnu_pbds::null_type>;

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

using i128 = __int128_t;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  i128 k = scan<int64_t>();
  i128 l = scan<int64_t>();
  i128 r = scan<int64_t>();
  i128 t = scan<int64_t>();
  i128 x = scan<int64_t>();
  i128 y = scan<int64_t>();
  if (k - x * t >= l) {
    cout << "Yes\n";
    exit(0);
  }
  if (k + (y - x) * t < l) {
    cout << "No\n";
    exit(0);
  }
  auto cur = k;
  HashSet<int64_t> h;
  for (bool first = true; t > 0;) {
    if (cur - x * t >= l) break;
    if (h.find(cur) != end(h)) break;
    h.insert(cur);
    i128 ng = 0, ok = 2e18;
    if (exchange(first, false)) ng = -1;
    while (ok - ng > 1) {
      auto mid = (ng + ok) / 2;
      (cur - x * mid + y <= r ? ok : ng) = mid;
    }
    if (cur - x * ok < l) {
      cout << "No\n";
      exit(0);
    }
    DUMP(ok);
    cur -= x * ok;
    cur += y;
    t -= ok;
  }
  cout << "Yes\n";
}