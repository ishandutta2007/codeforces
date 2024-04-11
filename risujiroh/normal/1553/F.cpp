#include <bits/stdc++.h>

namespace atcoder {
namespace internal {
template <class T> using is_integral =
    typename std::conditional<std::is_integral<T>::value || std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __uint128_t>::value,
                              std::true_type, std::false_type>::type;
template <class T> using is_signed_int =
    typename std::conditional<(is_integral<T>::value && std::is_signed<T>::value) || std::is_same<T, __int128_t>::value,
                              std::true_type, std::false_type>::type;
template <class T> using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value) ||
                                  std::is_same<T, __uint128_t>::value,
                              std::true_type, std::false_type>::type;
template <class T> using to_unsigned = typename std::conditional<
    std::is_same<T, __int128_t>::value, __uint128_t,
    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>, std::common_type<T>>::type>::type;
template <class T> using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
}  // namespace internal
}  // namespace atcoder
namespace atcoder {
template <class T> struct fenwick_tree {
  using U = internal::to_unsigned_t<T>;

 public:
  fenwick_tree() : _n(0) {}
  explicit fenwick_tree(int n) : _n(n), data(n) {}
  void add(int p, T x) {
    p++;
    while (p <= _n) {
      data[p - 1] += U(x);
      p += p & -p;
    }
  }
  T sum(int l, int r) { return sum(r) - sum(l); }
  T sum_(int r) { return sum(r); }

 private:
  int _n;
  std::vector<U> data;
  U sum(int r) {
    U s = 0;
    while (r > 0) {
      s += data[r - 1];
      r -= r & -r;
    }
    return s;
  }
};
}  // namespace atcoder

struct Div {
  uint64_t inv;
  Div() {}
  Div(int b) : inv((uint64_t(1) << 40 | (b - 1)) / b) {}
  friend int operator/(int a, const Div& b) { return a * b.inv >> 40; }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  constexpr int L = 3e5;
  vector<Div> div(L + 1);
  for (int i = 1; i <= L; ++i) div[i] = i;
  int n;
  cin >> n;
  int64_t ans = 0;
  atcoder::fenwick_tree<int> cnt(L + 1);
  atcoder::fenwick_tree<int64_t> f(L + 1);
  int64_t sum = 0;
  for (int k = 0; k < n; ++k) {
    int a = L - k;
    cin >> a;
    {
      int64_t cur = 0;
      for (int q = 1; q * a <= L; ++q) {
        cur += k - cnt.sum_(q * a);
      }
      ans += sum - a * cur;
    }
    {
      ans += int64_t(k) * a;
      int64_t sum_l = 0;
      for (int l = 1; l <= min(L, a - 1);) {
        int q = a / div[l];
        int r = a / div[q] + 1;
        auto t = f.sum_(r);
        ans -= q * (t - sum_l);
        l = r;
        sum_l = t;
      }
    }
    cnt.add(a, 1);
    f.add(a, a);
    sum += a;
    cout << ans << " \n"[k + 1 == n];
  }
}