#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include <unistd.h>
#include <x86intrin.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <charconv>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#ifndef DUMP
#define DUMP(...) void(0)
#endif

namespace std {

#if __cplusplus <= 201703L
template <class T> struct type_identity { using type = T; };
template <class T> using type_identity_t = typename type_identity<T>::type;
#endif

template <class Fun> class y_combinator_result {
  Fun fun_;

 public:
  template <class T> explicit y_combinator_result(T&& fun) : fun_(forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args&&... args) {
    return fun_(ref(*this), forward<Args>(args)...);
  }
};
template <class Fun> decltype(auto) y_combinator(Fun&& fun) {
  return y_combinator_result<decay_t<Fun>>(forward<Fun>(fun));
}

}  // namespace std

using namespace std;

template <class T> class Rep {
  struct Iter {
    T i;
    void operator++() { ++i; }
    T operator*() const { return i; }
    bool operator!=(Iter o) const { return i < *o; }
  } b, e;

 public:
  Rep(type_identity_t<T> l, T r) : b{l}, e{r} {}
  Rep(T n) : Rep(0, n) {}
  Iter begin() const { return b; }
  Iter end() const { return e; }
};
template <class T> class Per {
  struct Iter {
    T i;
    void operator++() { --i; }
    T operator*() const { return i; }
    bool operator!=(Iter o) const { return i > *o; }
  } b, e;

 public:
  Per(type_identity_t<T> l, T r) : b{r - 1}, e{l - 1} {}
  Per(T n) : Per(0, n) {}
  Iter begin() const { return b; }
  Iter end() const { return e; }
};

__attribute__((target("popcnt"))) int popcnt(uint64_t x) { return int(_mm_popcnt_u64(x)); }
__attribute__((target("bmi"))) int bsf(uint64_t x) { return int(_tzcnt_u64(x)); }
__attribute__((target("lzcnt"))) int bsr(uint64_t x) { return 63 - int(_lzcnt_u64(x)); }
__attribute__((target("bmi2"))) uint64_t pdep(uint64_t x, uint64_t mask) { return _pdep_u64(x, mask); }
__attribute__((target("bmi2"))) uint64_t pext(uint64_t x, uint64_t mask) { return _pext_u64(x, mask); }
template <class T> bool has_single_bit(T x) { return x && (x & (x - 1)) == 0; }
template <class T> T bit_width(T x) {
  assert(x >= 0);
  return bsr(x) + 1;
}
template <class T> T bit_floor(T x) {
  assert(x >= 1);
  return T(1) << bsr(x);
}
template <class T> T bit_ceil(T x) { return x <= 1 ? 1 : T(1) << bit_width(x - 1); }

template <class C> constexpr auto len(const C& c) -> decltype(int(c.size())) { return int(c.size()); }
template <class T, int N> constexpr int len(const T (&)[N]) { return N; }

template <class C, class Pred> bool all_of(const C& c, Pred pred) { return all_of(begin(c), end(c), pred); }
template <class C, class Pred> bool any_of(const C& c, Pred pred) { return any_of(begin(c), end(c), pred); }
template <class C, class Pred> bool none_of(const C& c, Pred pred) { return none_of(begin(c), end(c), pred); }
template <class C, class Fun> Fun for_each(C& c, Fun f) { return for_each(begin(c), end(c), f); }
template <class C, class T> int count(const C& c, const T& val) { return int(count(begin(c), end(c), val)); }
template <class C, class Pred> int count_if(const C& c, Pred pred) { return int(count_if(begin(c), end(c), pred)); }
template <class C1, class C2, class Pred = equal_to<>> int mismatch(const C1& c1, const C2& c2, Pred pred = Pred{}) {
  return int(distance(begin(c1), mismatch(begin(c1), end(c1), begin(c2), end(c2), pred).first));
}
template <class C, class T> int find(const C& c, const T& val) {
  return int(distance(begin(c), find(begin(c), end(c), val)));
}
template <class C, class Pred> int find_if(const C& c, Pred pred) {
  return int(distance(begin(c), find_if(begin(c), end(c), pred)));
}
template <class C, class Pred> int find_if_not(const C& c, Pred pred) {
  return int(distance(begin(c), find_if_not(begin(c), end(c), pred)));
}
template <class C1, class C2, class Pred = equal_to<>> int find_end(const C1& c1, const C2& c2, Pred pred = Pred{}) {
  return int(distance(begin(c1), find_end(begin(c1), end(c1), begin(c2), end(c2), pred)));
}
template <class C1, class C2, class Pred = equal_to<>>
int find_first_of(const C1& c1, const C2& c2, Pred pred = Pred{}) {
  return int(distance(begin(c1), find_first_of(begin(c1), end(c1), begin(c2), end(c2), pred)));
}
template <class C, class Pred = equal_to<>> int adjacent_find(const C& c, Pred pred = Pred{}) {
  return int(distance(begin(c), adjacent_find(begin(c), end(c), pred)));
}
template <class C1, class C2, class Pred = equal_to<>> int search(const C1& c1, const C2& c2, Pred pred = Pred{}) {
  return int(distance(begin(c1), search(begin(c1), end(c1), begin(c2), end(c2), pred)));
}
template <class C, class Iter> Iter copy(const C& c, Iter res) { return copy(begin(c), end(c), res); }
template <class C, class Iter, class Pred> Iter copy_if(const C& c, Iter res, Pred pred) {
  return copy_if(begin(c), end(c), res, pred);
}
template <class C, class Iter> Iter copy_backward(const C& c, Iter res) { return copy_backward(begin(c), end(c), res); }
template <class C, class Iter> Iter move(const C& c, Iter res) { return move(begin(c), end(c), res); }
template <class C, class Iter> Iter move_backward(const C& c, Iter res) { return move_backward(begin(c), end(c), res); }
template <class C, class T> void fill(C& c, const T& val) { fill(begin(c), end(c), val); }
template <class C, class Iter, class Op> Iter transform(const C& c, Iter res, Op op) {
  return transform(begin(c), end(c), res, op);
}
template <class C1, class C2, class Iter, class Op> Iter transform(const C1& c1, const C2& c2, Iter res, Op op) {
  assert(len(c1) == len(c2));
  return transform(begin(c1), end(c1), begin(c2), res, op);
}
template <class C, class Gen> void generate(C& c, Gen gen) { generate(begin(c), end(c), gen); }
template <class C, class T> int remove(C& c, const T& val) {
  return int(distance(begin(c), remove(begin(c), end(c), val)));
}
template <class C, class Pred> int remove_if(C& c, Pred pred) {
  return int(distance(begin(c), remove_if(begin(c), end(c), pred)));
}
template <class C, class Iter, class T> Iter remove_copy(const C& c, Iter res, const T& val) {
  return remove_copy(begin(c), end(c), res, val);
}
template <class C, class Iter, class Pred> Iter remove_copy_if(const C& c, Iter res, Pred pred) {
  return remove_copy_if(begin(c), end(c), res, pred);
}
template <class C, class T> void replace(C& c, const T& old_val, const T& new_val) {
  replace(begin(c), end(c), old_val, new_val);
}
template <class C, class Pred, class T> void replace_if(C& c, Pred pred, const T& new_val) {
  replace_if(begin(c), end(c), pred, new_val);
}
template <class C, class Iter, class T> Iter replace_copy(const C& c, Iter res, const T& old_val, const T& new_val) {
  return replace_copy(begin(c), end(c), res, old_val, new_val);
}
template <class C, class Iter, class Pred, class T>
Iter replace_copy_if(const C& c, Iter res, Pred pred, const T& new_val) {
  return replace_copy_if(begin(c), end(c), res, pred, new_val);
}
template <class C1, class C2> int swap_ranges(C1& c1, C2& c2) {
  assert(len(c1) == len(c2));
  return int(distance(begin(c2), swap_ranges(begin(c1), end(c1), begin(c2))));
}
template <class C> void reverse(C& c) { reverse(begin(c), end(c)); }
template <class C, class Iter> Iter reverse_copy(const C& c, Iter res) { return reverse_copy(begin(c), end(c), res); }
template <class C> void rotate(C& c, int n) {
  assert(0 <= n && n <= len(c));
  rotate(begin(c), next(begin(c), n), end(c));
}
template <class C, class Iter> Iter rotate_copy(const C& c, int n, Iter res) {
  assert(0 <= n && n <= len(c));
  return rotate_copy(begin(c), next(begin(c), n), end(c), res);
}
template <class C, class Gen> void shuffle(C& c, Gen&& g) { shuffle(begin(c), end(c), forward<Gen>(g)); }
template <class C, class Iter, class Gen> Iter sample(const C& c, Iter res, int n, Gen&& g) {
  assert(n >= 0);
  return sample(begin(c), end(c), res, n, forward<Gen>(g));
}
template <class C, class Pred = equal_to<>> int unique(C& c, Pred pred = Pred{}) {
  return int(distance(begin(c), unique(begin(c), end(c), pred)));
}
template <class C, class Iter, class Pred = equal_to<>> Iter unique_copy(const C& c, Iter res, Pred pred = Pred{}) {
  return unique_copy(begin(c), end(c), res, pred);
}
template <class C, class Pred> bool is_partitioned(const C& c, Pred pred) {
  return is_partitioned(begin(c), end(c), pred);
}
template <class C, class Pred> int partition(C& c, Pred pred) {
  return int(distance(begin(c), partition(begin(c), end(c), pred)));
}
template <class C, class Iter1, class Iter2, class Pred>
pair<Iter1, Iter2> partition_copy(const C& c, Iter1 res_true, Iter2 res_false, Pred pred) {
  return partition_copy(begin(c), end(c), res_true, res_false, pred);
}
template <class C, class Pred> int stable_partition(C& c, Pred pred) {
  return int(distance(begin(c), stable_partition(begin(c), end(c), pred)));
}
template <class C, class Pred> int partition_point(const C& c, Pred pred) {
  return int(distance(begin(c), partition_point(begin(c), end(c), pred)));
}
template <class C, class Comp = less<>> bool is_sorted(const C& c, Comp comp = Comp{}) {
  return is_sorted(begin(c), end(c), comp);
}
template <class C, class Comp = less<>> int is_sorted_until(const C& c, Comp comp = Comp{}) {
  return int(distance(begin(c), is_sorted_until(begin(c), end(c), comp)));
}
template <class C, class Comp = less<>> void sort(C& c, Comp comp = Comp{}) { sort(begin(c), end(c), comp); }
template <class C, class Comp = less<>> void partial_sort(C& c, int n, Comp comp = Comp{}) {
  assert(0 <= n && n <= len(c));
  partial_sort(begin(c), next(begin(c), n), end(c), comp);
}
template <class C, class Res, class Comp = less<>> int partial_sort_copy(const C& c, Res& res, Comp comp = Comp{}) {
  return int(distance(begin(res), partial_sort_copy(begin(c), end(c), begin(res), end(res), comp)));
}
template <class C, class Comp = less<>> void stable_sort(C& c, Comp comp = Comp{}) {
  stable_sort(begin(c), end(c), comp);
}
template <class C, class Comp = less<>> void nth_element(C& c, int n, Comp comp = Comp{}) {
  assert(0 <= n && n <= len(c));
  nth_element(begin(c), next(begin(c), n), end(c), comp);
}
template <class C, class T, class Comp = less<>> int lower_bound(const C& c, const T& val, Comp comp = Comp{}) {
  return int(distance(begin(c), lower_bound(begin(c), end(c), val, comp)));
}
template <class C, class T, class Comp = less<>> int upper_bound(const C& c, const T& val, Comp comp = Comp{}) {
  return int(distance(begin(c), upper_bound(begin(c), end(c), val, comp)));
}
template <class C, class T, class Comp = less<>> bool binary_search(const C& c, const T& val, Comp comp = Comp{}) {
  return binary_search(begin(c), end(c), val, comp);
}
template <class C, class T, class Comp = less<>>
pair<int, int> equal_range(const C& c, const T& val, Comp comp = Comp{}) {
  auto [lb, ub] = equal_range(begin(c), end(c), val, comp);
  return {int(distance(begin(c), lb)), int(distance(begin(c), ub))};
}
template <class C1, class C2, class Iter, class Comp = less<>>
Iter merge(const C1& c1, const C2& c2, Iter res, Comp comp = Comp{}) {
  return merge(begin(c1), end(c1), begin(c2), end(c2), res, comp);
}
template <class C, class Comp = less<>> void inplace_merge(C& c, int n, Comp comp = Comp{}) {
  assert(0 <= n && n <= len(c));
  inplace_merge(begin(c), next(begin(c), n), end(c), comp);
}
template <class C1, class C2, class Comp = less<>> bool includes(const C1& c1, const C2& c2, Comp comp = Comp{}) {
  return includes(begin(c1), end(c1), begin(c2), end(c2), comp);
}
template <class C1, class C2, class Iter, class Comp = less<>>
Iter set_difference(const C1& c1, const C2& c2, Iter res, Comp comp = Comp{}) {
  return set_difference(begin(c1), end(c1), begin(c2), end(c2), res, comp);
}
template <class C1, class C2, class Iter, class Comp = less<>>
Iter set_intersection(const C1& c1, const C2& c2, Iter res, Comp comp = Comp{}) {
  return set_intersection(begin(c1), end(c1), begin(c2), end(c2), res, comp);
}
template <class C1, class C2, class Iter, class Comp = less<>>
Iter set_symmetric_difference(const C1& c1, const C2& c2, Iter res, Comp comp = Comp{}) {
  return set_symmetric_difference(begin(c1), end(c1), begin(c2), end(c2), res, comp);
}
template <class C1, class C2, class Iter, class Comp = less<>>
Iter set_union(const C1& c1, const C2& c2, Iter res, Comp comp = Comp{}) {
  return set_union(begin(c1), end(c1), begin(c2), end(c2), res, comp);
}
template <class C, class Comp = less<>> bool is_heap(const C& c, Comp comp = Comp{}) {
  return is_heap(begin(c), end(c), comp);
}
template <class C, class Comp = less<>> int is_heap_until(const C& c, Comp comp = Comp{}) {
  return int(distance(begin(c), is_heap_until(begin(c), end(c), comp)));
}
template <class C, class Comp = less<>> void make_heap(C& c, Comp comp = Comp{}) { make_heap(begin(c), end(c), comp); }
template <class C, class Comp = less<>> void push_heap(C& c, Comp comp = Comp{}) { push_heap(begin(c), end(c), comp); }
template <class C, class Comp = less<>> void pop_heap(C& c, Comp comp = Comp{}) { pop_heap(begin(c), end(c), comp); }
template <class C, class Comp = less<>> void sort_heap(C& c, Comp comp = Comp{}) { sort_heap(begin(c), end(c), comp); }
template <class C, class Comp = less<>> int max_element(const C& c, Comp comp = Comp{}) {
  return int(distance(begin(c), max_element(begin(c), end(c), comp)));
}
template <class C, class Comp = less<>> int min_element(const C& c, Comp comp = Comp{}) {
  return int(distance(begin(c), min_element(begin(c), end(c), comp)));
}
template <class C, class Comp = less<>> pair<int, int> minmax_element(const C& c, Comp comp = Comp{}) {
  auto [mn, mx] = minmax_element(begin(c), end(c), comp);
  return {int(distance(begin(c), mn)), int(distance(begin(c), mx))};
}
template <class C1, class C2, class Pred = equal_to<>> bool equal(const C1& c1, const C2& c2, Pred pred = Pred{}) {
  return equal(begin(c1), end(c1), begin(c2), end(c2), pred);
}
template <class C1, class C2, class Comp = less<>>
bool lexicographical_compare(const C1& c1, const C2& c2, Comp comp = Comp{}) {
  return lexicographical_compare(begin(c1), end(c1), begin(c2), end(c2), comp);
}
template <class C1, class C2, class Pred = equal_to<>>
bool is_permutation(const C1& c1, const C2& c2, Pred pred = Pred{}) {
  return is_permutation(begin(c1), end(c1), begin(c2), end(c2), pred);
}
template <class C, class Comp = less<>> bool next_permutation(C& c, Comp comp = Comp{}) {
  return next_permutation(begin(c), end(c), comp);
}
template <class C, class Comp = less<>> bool prev_permutation(C& c, Comp comp = Comp{}) {
  return prev_permutation(begin(c), end(c), comp);
}
template <class C, class T> void iota(C& c, T val) { iota(begin(c), end(c), move(val)); }
template <class C, class T, class Op = plus<>> T accumulate(const C& c, T init, Op op = Op{}) {
  return accumulate(begin(c), end(c), move(init), op);
}
template <class C1, class C2, class T, class Op1 = plus<>, class Op2 = multiplies<>>
T inner_product(const C1& c1, const C2& c2, T init, Op1 op1 = Op1{}, Op2 op2 = Op2{}) {
  assert(len(c1) == len(c2));
  return inner_product(begin(c1), end(c1), begin(c2), move(init), op1, op2);
}
template <class C, class Iter, class Op = minus<>> Iter adjacent_difference(const C& c, Iter res, Op op = Op{}) {
  return adjacent_difference(begin(c), end(c), res, op);
}
template <class C, class Iter, class Op = plus<>> Iter partial_sum(const C& c, Iter res, Op op = Op{}) {
  return partial_sum(begin(c), end(c), res, op);
}

template <class T> vector<T>& operator++(vector<T>& a) {
  for (auto&& e : a) ++e;
  return a;
}
template <class T> vector<T>& operator--(vector<T>& a) {
  for (auto&& e : a) --e;
  return a;
}
template <class T> vector<T> operator++(vector<T>& a, int) {
  auto res = a;
  return ++a, move(res);
}
template <class T> vector<T> operator--(vector<T>& a, int) {
  auto res = a;
  return --a, move(res);
}
template <class T> vector<T> operator+(vector<T> a) {
  for (auto&& e : a) e = +e;
  return a;
}
template <class T> vector<T> operator-(vector<T> a) {
  for (auto&& e : a) e = -e;
  return a;
}
template <class T> vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
  if (len(a) < len(b)) a.reserve(len(b)), a.resize(len(b));
  for (int i : Rep(len(b))) a[i] += b[i];
  return a;
}
template <class T, class U> vector<T>& operator+=(vector<T>& a, const U& b) {
  for (auto&& e : a) e += b;
  return a;
}
template <class T> vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
  if (len(a) < len(b)) a.reserve(len(b)), a.resize(len(b));
  for (int i : Rep(len(b))) a[i] -= b[i];
  return a;
}
template <class T, class U> vector<T>& operator-=(vector<T>& a, const U& b) {
  for (auto&& e : a) e -= b;
  return a;
}
template <class T> vector<T>& operator*=(vector<T>& a, const vector<T>& b) {
  assert(len(a) == len(b));
  for (int i : Rep(len(a))) a[i] *= b[i];
  return a;
}
template <class T, class U> vector<T>& operator*=(vector<T>& a, const U& b) {
  for (auto&& e : a) e *= b;
  return a;
}
template <class T> vector<T>& operator/=(vector<T>& a, const vector<T>& b) {
  assert(len(a) == len(b));
  for (int i : Rep(len(a))) a[i] /= b[i];
  return a;
}
template <class T, class U> vector<T>& operator/=(vector<T>& a, const U& b) {
  for (auto&& e : a) e /= b;
  return a;
}
template <class T> vector<T> operator+(vector<T> a, const vector<T>& b) { return move(a += b); }
template <class T, class U> vector<T> operator+(vector<T> a, const U& b) { return move(a += b); }
template <class T, class U> vector<T> operator+(const U& a, vector<T> b) {
  for (auto&& e : b) e = a + e;
  return b;
}
template <class T> vector<T> operator-(vector<T> a, const vector<T>& b) { return move(a -= b); }
template <class T, class U> vector<T> operator-(vector<T> a, const U& b) { return move(a -= b); }
template <class T, class U> vector<T> operator-(const U& a, vector<T> b) {
  for (auto&& e : b) e = a - e;
  return b;
}
template <class T> vector<T> operator*(vector<T> a, const vector<T>& b) { return move(a *= b); }
template <class T, class U> vector<T> operator*(vector<T> a, const U& b) { return move(a *= b); }
template <class T, class U> vector<T> operator*(const U& a, vector<T> b) {
  for (auto&& e : b) e = a * e;
  return b;
}
template <class T> vector<T> operator/(vector<T> a, const vector<T>& b) { return move(a /= b); }
template <class T, class U> vector<T> operator/(vector<T> a, const U& b) { return move(a /= b); }
template <class T, class U> vector<T> operator/(const U& a, vector<T> b) {
  for (auto&& e : b) e = a / e;
  return b;
}

template <class T, int Ndim = -1> struct Tensor : vector<T> {
  using Index = conditional_t<Ndim == -1, vector<int>, array<int, Ndim>>;
  Index shape, strides;
  constexpr int ndim() const { return len(shape); }
  Tensor() {}
  explicit Tensor(const Index& shape_, const T& val = T{})
      : vector<T>::vector(accumulate(shape_, 1, multiplies{}), val), shape(shape_), strides(shape) {
    for (int axis : Per(ndim())) strides[axis] = axis + 1 < ndim() ? shape[axis + 1] * strides[axis + 1] : 1;
  }
  using vector<T>::operator[];
  T& operator[](const Index& i) { return (*this)[inner_product(i, strides, 0)]; }
  const T& operator[](const Index& i) const { return (*this)[inner_product(i, strides, 0)]; }
};

template <class T> constexpr T inf = numeric_limits<T>::max() / 2;
template <class T, class U = T> bool chmin(T& a, U&& b) { return b < a ? a = forward<U>(b), true : false; }
template <class T, class U = T> bool chmax(T& a, U&& b) { return a < b ? a = forward<U>(b), true : false; }

#ifdef NDEBUG
mt19937_64 rng(_rdtsc());
#else
mt19937_64 rng;
#endif

struct Scan {
  char buf[1 << 15], temp;
  int l = len(buf), r = l;
  bool go(char& c) {
    for (;; ++l) {
      if (r - l < 64) r = (r - l) + read(STDIN_FILENO, move(buf + l, buf + r, buf), len(buf) - (r - l)), l = 0;
      if (l == r) return c = {}, false;
      if (buf[l] > ' ') return c = buf[l++], true;
    }
  }
  bool go(string& s) {
    if (!go(temp)) return s = {}, false;
    for (s = temp; buf[l] > ' '; s += temp) go(temp);
    return true;
  }
  template <class T, enable_if_t<is_integral_v<T>, int> = 0> bool go(T& x) {
    if (!go(temp)) return x = {}, false;
    make_unsigned_t<T> u = (temp == '-' ? buf[l++] : temp) & 15;
    for (; buf[l] > ' '; ++l) (u *= 10) += buf[l] & 15;
    return x = temp == '-' ? -u : u, true;
  }
  template <class T, enable_if_t<is_floating_point_v<T>, int> = 0> bool go(T& x) {
    if (!go(temp)) return x = {}, false;
    char* endptr;
    if constexpr (is_same_v<T, float>) x = strtof(buf + (l - 1), &endptr);
    if constexpr (is_same_v<T, double>) x = strtod(buf + (l - 1), &endptr);
    if constexpr (is_same_v<T, long double>) x = strtold(buf + (l - 1), &endptr);
    return l = int(endptr - buf), true;
  }
  template <class C, enable_if_t<!is_same_v<typename C::value_type, char>, int> = 0> bool go(C& c) {
    for (auto&& e : c)
      if (!go(e)) return c = {}, false;
    return true;
  }
  template <class T> bool go(vector<T>& v) {
    for (auto&& e : v)
      if (!go(e)) return v = {}, false;
    return true;
  }
  template <class... Args> bool operator()(Args&... args) { return (..., go(args)); }
} scan;
struct Print {
  char buf[1 << 15], temp;
  int p = 0;
  void go(char c = '\0') {
    if (len(buf) - p < 64 || c == -1) write(STDOUT_FILENO, buf, p), p = 0;
    if (c > 0) buf[p++] = c;
  }
  void go(string_view sv) {
    for (char c : sv) go(c);
  }
  template <class T, enable_if_t<is_integral_v<T>, int> = 0> void go(T x) {
    go(), p = int(to_chars(buf + p, end(buf), x).ptr - buf);
  }
  template <class T, enable_if_t<is_floating_point_v<T>, int> = 0> void go(T x) {
    go(), p += snprintf(buf + p, len(buf) - p, "%.20Lf", (long double)(x));
  }
  template <class C, enable_if_t<!is_same_v<typename C::value_type, char>, int> = 0> void go(const C& c) {
    temp = '\0';
    for (auto&& e : c) go(exchange(temp, ' ')), go(e);
  }
  template <class... Args> void operator()(const Args&... args) {
    temp = '\0', (..., (go(exchange(temp, ' ')), go(args))), go('\n');
  }
  ~Print() { go(char(-1)); }
} print;

#undef NDEBUG
#include <cassert>

int main() {
  int tt;
  scan(tt);
  while (tt--) {
    string s;
    scan(s);
    int n = len(s);
    if (count(s, '1') == n) {
      print(0);
    } else {
      int l = find(s, '0');
      int r = l;
      while (r < n && s[l] == s[r]) {
        ++r;
      }
      if (count(s, '0') == r - l) {
        print(1);
      } else {
        print(2);
      }
    }
  }
}