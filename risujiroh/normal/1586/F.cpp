using namespace std;

#ifndef OJ
#define OJ 1
#define NDEBUG
#endif

#include <bits/stdc++.h>
#include <x86intrin.h>

#define INC_DEC(op) \
  template <class T> vector<T>& operator op(vector<T>& v) { \
    for (T & e : v) op e; \
    return v; \
  } \
  template <class T> vector<T>&& operator op(vector<T>&& v) { return move(op v); } \
  template <class T> enable_if_t<__is_tuple_like<T>{}, T&&> operator op(T&& t) { \
    apply([](auto&... es) { (..., op es); }, t); \
    return forward<T>(t); \
  }
INC_DEC(++)
INC_DEC(--)
#undef INC_DEC
template <class T> istream& operator>>(istream& i, vector<T>& v) {
  for (T& e : v) i >> e;
  return i;
}
template <class T> enable_if_t<__is_tuple_like<T>{}, istream&> operator>>(istream& i, T& t) {
  apply([&](auto&... es) { (i >> ... >> es); }, t);
  return i;
}
template <class T> ostream& operator<<(ostream& o, const vector<T>& v) {
  string_view s;
  for (const T& e : v) o << exchange(s, " ") << e;
  return o;
}
template <class T> enable_if_t<__is_tuple_like<T>{}, ostream&> operator<<(ostream& o, const T& t) {
  string_view s;
  apply([&](const auto&... es) { (..., (o << exchange(s, " ") << es)); }, t);
  return o;
}
template <class T = int, class... Args> T input(Args&&... args) {
  T r(forward<Args>(args)...);
  cin >> r;
  return r;
}
template <class... Ts> enable_if_t<sizeof...(Ts) >= 2, tuple<Ts...>> input() {
  tuple<Ts...> r;
  apply([](auto&... es) { (cin >> ... >> es); }, r);
  return r;
}

using i64 = long long;

template <class F> struct Fix : F {
  explicit Fix(F f) : F(move(f)) {}
  template <class... Args> decltype(auto) operator()(Args&&... args) const {
    return F::operator()(ref(*this), forward<Args>(args)...);
  }
};

template <class R> int sz(const R& r) { return int(size(r)); }
template <class I> int sz(I b, I e) { return int(distance(b, e)); }
template <class T> T div_floor(T x, T y) { return assert(y), x / y - ((x ^ y) < 0 && x % y); }
template <class T> T div_ceil(T x, T y) { return assert(y), x / y + ((x ^ y) >= 0 && x % y); }
template <class T, class U = T> bool chmin(T& x, U&& y) { return y < x ? x = forward<U>(y), true : false; }
template <class T, class U = T> bool chmax(T& x, U&& y) { return x < y ? x = forward<U>(y), true : false; }

mt19937_64 rng(_rdtsc() * OJ);
template <class T> T rnd(T x, T y) { return uniform_int_distribution(x, y)(rng); }

#define fn(...) [&]([[maybe_unused]] auto&& _) -> decltype(auto) { return (__VA_ARGS__); }
#define dump(...) OJ ? cerr : cerr << __LINE__ << ": [" #__VA_ARGS__ "]: " << __VA_ARGS__ << '\n'

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int n, k; cin >> n >> k;) {
    vector<array<int, 10>> v(n);
    for (int i : views::iota(0, n)) {
      int t = i;
      for (int z : views::iota(0, 10)) {
        v[i][z] = t % k;
        t /= k;
      }
    }
    vector<int> ans;
    ans.reserve(n * (n - 1) / 2);
    for (int i : views::iota(0, n)) {
      for (int j : views::iota(i + 1, n)) {
        for (int t : views::iota(0, 10) | views::reverse) {
          if (v[i][t] != v[j][t]) {
            ans.push_back(t);
            break;
          }
        }
      }
    }
    ++ans;
    cout << *ranges::max_element(ans) << '\n';
    cout << ans << '\n';
  }
}