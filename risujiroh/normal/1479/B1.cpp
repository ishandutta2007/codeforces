#include <bits/stdc++.h>

template <class ForwardIterator,
          class T = typename std::iterator_traits<ForwardIterator>::value_type>
std::vector<std::pair<T, int>> rle(ForwardIterator first,
                                   ForwardIterator last) {
  std::vector<std::pair<T, int>> res;
  int n = 0;
  for (auto it = first; it != last; ++it)
    n += std::next(it) == last or not(*it == *std::next(it));
  res.reserve(n);
  for (; first != last; ++first)
    if (std::empty(res) or not(res.back().first == *first))
      res.emplace_back(*first, 1);
    else
      ++res.back().second;
  return res;
}

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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector<int> a(n);
  generate(ALL(a), scan<>);

  auto v = rle(ALL(a));
  n = size(v);
  vector<int> pos;
  for (int i : Rep(n))
    if (v[i].second >= 2) pos.push_back(i);

  if (empty(pos)) {
    cout << n << '\n';
    exit(0);
  }

  int ans = n + size(pos);
  for (int z : Rep(1, size(pos))) {
    if (v[pos[z - 1]].first != v[pos[z]].first) continue;
    bool any = false;
    for (int i : Rep(pos[z - 1], pos[z] + 1))
      if ((~(i - pos[z - 1]) & 1) ^ (v[i].first == v[pos[z - 1]].first)) {
        any = true;
        break;
      }
    if (any) continue;
    --ans;
  }
  cout << ans << '\n';
}