#include <bits/stdc++.h>

namespace atcoder {

namespace internal {

std::vector<int> sa_naive(const std::vector<int>& s) {
  int n = int(s.size());
  std::vector<int> sa(n);
  std::iota(sa.begin(), sa.end(), 0);
  std::sort(sa.begin(), sa.end(), [&](int l, int r) {
    if (l == r) return false;
    while (l < n && r < n) {
      if (s[l] != s[r]) return s[l] < s[r];
      l++;
      r++;
    }
    return l == n;
  });
  return sa;
}

std::vector<int> sa_doubling(const std::vector<int>& s) {
  int n = int(s.size());
  std::vector<int> sa(n), rnk = s, tmp(n);
  std::iota(sa.begin(), sa.end(), 0);
  for (int k = 1; k < n; k *= 2) {
    auto cmp = [&](int x, int y) {
      if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
      int rx = x + k < n ? rnk[x + k] : -1;
      int ry = y + k < n ? rnk[y + k] : -1;
      return rx < ry;
    };
    std::sort(sa.begin(), sa.end(), cmp);
    tmp[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
      tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
    }
    std::swap(tmp, rnk);
  }
  return sa;
}

// SA-IS, linear-time suffix array construction
// Reference:
// G. Nong, S. Zhang, and W. H. Chan,
// Two Efficient Algorithms for Linear Time Suffix Array Construction
template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
std::vector<int> sa_is(const std::vector<int>& s, int upper) {
  int n = int(s.size());
  if (n == 0) return {};
  if (n == 1) return {0};
  if (n == 2) {
    if (s[0] < s[1]) {
      return {0, 1};
    } else {
      return {1, 0};
    }
  }
  if (n < THRESHOLD_NAIVE) {
    return sa_naive(s);
  }
  if (n < THRESHOLD_DOUBLING) {
    return sa_doubling(s);
  }

  std::vector<int> sa(n);
  std::vector<bool> ls(n);
  for (int i = n - 2; i >= 0; i--) {
    ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
  }
  std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
  for (int i = 0; i < n; i++) {
    if (!ls[i]) {
      sum_s[s[i]]++;
    } else {
      sum_l[s[i] + 1]++;
    }
  }
  for (int i = 0; i <= upper; i++) {
    sum_s[i] += sum_l[i];
    if (i < upper) sum_l[i + 1] += sum_s[i];
  }

  auto induce = [&](const std::vector<int>& lms) {
    std::fill(sa.begin(), sa.end(), -1);
    std::vector<int> buf(upper + 1);
    std::copy(sum_s.begin(), sum_s.end(), buf.begin());
    for (auto d : lms) {
      if (d == n) continue;
      sa[buf[s[d]]++] = d;
    }
    std::copy(sum_l.begin(), sum_l.end(), buf.begin());
    sa[buf[s[n - 1]]++] = n - 1;
    for (int i = 0; i < n; i++) {
      int v = sa[i];
      if (v >= 1 && !ls[v - 1]) {
        sa[buf[s[v - 1]]++] = v - 1;
      }
    }
    std::copy(sum_l.begin(), sum_l.end(), buf.begin());
    for (int i = n - 1; i >= 0; i--) {
      int v = sa[i];
      if (v >= 1 && ls[v - 1]) {
        sa[--buf[s[v - 1] + 1]] = v - 1;
      }
    }
  };

  std::vector<int> lms_map(n + 1, -1);
  int m = 0;
  for (int i = 1; i < n; i++) {
    if (!ls[i - 1] && ls[i]) {
      lms_map[i] = m++;
    }
  }
  std::vector<int> lms;
  lms.reserve(m);
  for (int i = 1; i < n; i++) {
    if (!ls[i - 1] && ls[i]) {
      lms.push_back(i);
    }
  }

  induce(lms);

  if (m) {
    std::vector<int> sorted_lms;
    sorted_lms.reserve(m);
    for (int v : sa) {
      if (lms_map[v] != -1) sorted_lms.push_back(v);
    }
    std::vector<int> rec_s(m);
    int rec_upper = 0;
    rec_s[lms_map[sorted_lms[0]]] = 0;
    for (int i = 1; i < m; i++) {
      int l = sorted_lms[i - 1], r = sorted_lms[i];
      int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
      int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
      bool same = true;
      if (end_l - l != end_r - r) {
        same = false;
      } else {
        while (l < end_l) {
          if (s[l] != s[r]) {
            break;
          }
          l++;
          r++;
        }
        if (l == n || s[l] != s[r]) same = false;
      }
      if (!same) rec_upper++;
      rec_s[lms_map[sorted_lms[i]]] = rec_upper;
    }

    auto rec_sa = sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

    for (int i = 0; i < m; i++) {
      sorted_lms[i] = lms[rec_sa[i]];
    }
    induce(sorted_lms);
  }
  return sa;
}

}  // namespace internal

std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
  assert(0 <= upper);
  for (int d : s) {
    assert(0 <= d && d <= upper);
  }
  auto sa = internal::sa_is(s, upper);
  return sa;
}

template <class T>
std::vector<int> suffix_array(const std::vector<T>& s) {
  int n = int(s.size());
  std::vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
  std::vector<int> s2(n);
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (i && s[idx[i - 1]] != s[idx[i]]) now++;
    s2[idx[i]] = now;
  }
  return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
  int n = int(s.size());
  std::vector<int> s2(n);
  for (int i = 0; i < n; i++) {
    s2[i] = s[i];
  }
  return internal::sa_is(s2, 255);
}

// Reference:
// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,
// Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its
// Applications
template <class T>
std::vector<int> lcp_array(const std::vector<T>& s,
                           const std::vector<int>& sa) {
  int n = int(s.size());
  assert(n >= 1);
  std::vector<int> rnk(n);
  for (int i = 0; i < n; i++) {
    rnk[sa[i]] = i;
  }
  std::vector<int> lcp(n - 1);
  int h = 0;
  for (int i = 0; i < n; i++) {
    if (h > 0) h--;
    if (rnk[i] == 0) continue;
    int j = sa[rnk[i] - 1];
    for (; j + h < n && i + h < n; h++) {
      if (s[j + h] != s[i + h]) break;
    }
    lcp[rnk[i] - 1] = h;
  }
  return lcp;
}

std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
  int n = int(s.size());
  std::vector<int> s2(n);
  for (int i = 0; i < n; i++) {
    s2[i] = s[i];
  }
  return lcp_array(s2, sa);
}

// Reference:
// D. Gusfield,
// Algorithms on Strings, Trees, and Sequences: Computer Science and
// Computational Biology
template <class T>
std::vector<int> z_algorithm(const std::vector<T>& s) {
  int n = int(s.size());
  if (n == 0) return {};
  std::vector<int> z(n);
  z[0] = 0;
  for (int i = 1, j = 0; i < n; i++) {
    int& k = z[i];
    k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
    while (i + k < n && s[k] == s[i + k]) k++;
    if (j + z[j] < i + z[i]) j = i;
  }
  z[0] = n;
  return z;
}

std::vector<int> z_algorithm(const std::string& s) {
  int n = int(s.size());
  std::vector<int> s2(n);
  for (int i = 0; i < n; i++) {
    s2[i] = s[i];
  }
  return z_algorithm(s2);
}

}  // namespace atcoder

namespace ecnerwala {

// https://github.com/ecnerwala/cp-book/blob/master/src/rmq.hpp
template <typename T, class Compare = std::less<T>>
class RangeMinQuery : private Compare {
  static const int BUCKET_SIZE = 32;
  static const int BUCKET_SIZE_LOG = 5;
  static_assert(BUCKET_SIZE == (1 << BUCKET_SIZE_LOG),
                "BUCKET_SIZE should be a power of 2");
  static const int CACHE_LINE_ALIGNMENT = 64;
  int n = 0;
  std::vector<T> data;
  std::vector<T> pref_data;
  std::vector<T> suff_data;
  std::vector<T> sparse_table;
  std::vector<uint32_t> range_mask;

 private:
  int num_buckets() const { return n >> BUCKET_SIZE_LOG; }
  int num_levels() const {
    return num_buckets() ? 32 - __builtin_clz(num_buckets()) : 0;
  }
  int sparse_table_size() const { return num_buckets() * num_levels(); }

 private:
  const T& min(const T& a, const T& b) const {
    return Compare::operator()(a, b) ? a : b;
  }
  void setmin(T& a, const T& b) const {
    if (Compare::operator()(b, a)) a = b;
  }

  template <typename Vec>
  static int get_size(const Vec& v) {
    using std::size;
    return int(size(v));
  }

 public:
  RangeMinQuery() {}
  template <typename Vec>
  explicit RangeMinQuery(const Vec& data_, const Compare& comp_ = Compare())
      : Compare(comp_),
        n(get_size(data_)),
        data(n),
        pref_data(n),
        suff_data(n),
        sparse_table(sparse_table_size()),
        range_mask(n) {
    for (int i = 0; i < n; i++) data[i] = data_[i];
    for (int i = 0; i < n; i++) {
      if (i & (BUCKET_SIZE - 1)) {
        uint32_t m = range_mask[i - 1];
        while (m &&
               !Compare::operator()(
                   data[(i | (BUCKET_SIZE - 1)) - __builtin_clz(m)], data[i])) {
          m -= uint32_t(1) << (BUCKET_SIZE - 1 - __builtin_clz(m));
        }
        m |= uint32_t(1) << (i & (BUCKET_SIZE - 1));
        range_mask[i] = m;
      } else {
        range_mask[i] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      pref_data[i] = data[i];
      if (i & (BUCKET_SIZE - 1)) {
        setmin(pref_data[i], pref_data[i - 1]);
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      suff_data[i] = data[i];
      if (i + 1 < n && ((i + 1) & (BUCKET_SIZE - 1))) {
        setmin(suff_data[i], suff_data[i + 1]);
      }
    }
    for (int i = 0; i < num_buckets(); i++) {
      sparse_table[i] = data[i * BUCKET_SIZE];
      for (int v = 1; v < BUCKET_SIZE; v++) {
        setmin(sparse_table[i], data[i * BUCKET_SIZE + v]);
      }
    }
    for (int l = 0; l + 1 < num_levels(); l++) {
      for (int i = 0; i + (1 << (l + 1)) <= num_buckets(); i++) {
        sparse_table[(l + 1) * num_buckets() + i] =
            min(sparse_table[l * num_buckets() + i],
                sparse_table[l * num_buckets() + i + (1 << l)]);
      }
    }
  }

  T query(int l, int r) const {
    assert(l <= r);
    int bucket_l = (l >> BUCKET_SIZE_LOG);
    int bucket_r = (r >> BUCKET_SIZE_LOG);
    if (bucket_l == bucket_r) {
      uint32_t msk =
          range_mask[r] & ~((uint32_t(1) << (l & (BUCKET_SIZE - 1))) - 1);
      int ind = (l & ~(BUCKET_SIZE - 1)) + __builtin_ctz(msk);
      return data[ind];
    } else {
      T ans = min(suff_data[l], pref_data[r]);
      bucket_l++;
      if (bucket_l < bucket_r) {
        int level = (32 - __builtin_clz(bucket_r - bucket_l)) - 1;
        setmin(ans, sparse_table[level * num_buckets() + bucket_l]);
        setmin(ans,
               sparse_table[level * num_buckets() + bucket_r - (1 << level)]);
      }
      return ans;
    }
  }
};

}  // namespace ecnerwala

template <uint32_t Modulus>
class ModularInt {
  using M = ModularInt;

 public:
  static_assert(int(Modulus) >= 1, "Modulus must be in the range [1, 2^31)");
  static constexpr int modulus() { return Modulus; }
  static M raw(uint32_t v) {
    M res;
    res.v_ = v;
    return res;
  }

  ModularInt() : v_(0) {}
  ModularInt(int64_t v) : v_(v % Modulus) {
    v_ = int(v_) < 0 ? v_ + Modulus : v_;
  }

  template <class T>
  explicit operator T() const {
    return v_;
  }
  M& operator++() { return v_ = ++v_ == Modulus ? 0 : v_, *this; }
  M& operator--() { return --(v_ ? v_ : v_ = Modulus), *this; }
  M operator+() const { return *this; }
  M operator-() const { return raw(v_ ? Modulus - v_ : 0); }
  M& operator*=(M o) { return v_ = uint64_t(v_) * o.v_ % Modulus, *this; }
  M& operator/=(M o) {
    auto [inv, gcd] = extgcd(o.v_, Modulus);
    assert(gcd == 1);
    return *this *= inv;
  }
  M& operator+=(M o) {
    return v_ = int(v_ += o.v_ - Modulus) < 0 ? v_ + Modulus : v_, *this;
  }
  M& operator-=(M o) {
    return v_ = int(v_ -= o.v_) < 0 ? v_ + Modulus : v_, *this;
  }

  friend M operator++(M& a, int) { return std::exchange(a, ++M(a)); }
  friend M operator--(M& a, int) { return std::exchange(a, --M(a)); }
  friend M operator*(M a, M b) { return a *= b; }
  friend M operator/(M a, M b) { return a /= b; }
  friend M operator+(M a, M b) { return a += b; }
  friend M operator-(M a, M b) { return a -= b; }
  friend std::istream& operator>>(std::istream& is, M& x) {
    int64_t v;
    return is >> v, x = v, is;
  }
  friend std::ostream& operator<<(std::ostream& os, M x) { return os << x.v_; }
  friend bool operator==(M a, M b) { return a.v_ == b.v_; }
  friend bool operator!=(M a, M b) { return a.v_ != b.v_; }

 private:
  static std::array<int, 2> extgcd(int a, int b) {
    std::array x{1, 0};
    while (b) {
      int q = a / b;
      std::swap(x[0] -= q * x[1], x[1]);
      std::swap(a -= q * b, b);
    }
    return {x[0], a};
  }

  uint32_t v_;
};

template <class T>
struct Fenwick {
  Fenwick() {}
  Fenwick(int n) : tree(n) {}

  int size() const { return std::size(tree); }
  void add(int i, T a) {
    assert(0 <= i), assert(i < size());
    for (; i < size(); i |= i + 1) tree[i] += a;
  }
  T sum(int i) const {
    assert(0 <= i), assert(i <= size());
    T res{};
    for (; i; i &= i - 1) res += tree[i - 1];
    return res;
  }

 private:
  std::vector<T> tree;
};

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l, r;
  Rep(int _l, int _r) : l(_l), r(_r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l}; }
  I end() const { return {r}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l, r;
  Per(int _l, int _r) : l(_l), r(_r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r - 1}; }
  I end() const { return {l - 1}; }
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
  return std::cin >> res, res;
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

using Mint = ModularInt<int(1e9) + 7>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto s = scan<string>();
  auto t = scan<string>();
  int n = size(s), m = size(t);
  auto sa = atcoder::suffix_array(s + t);
  vector<int> isa(n + m);
  for (int k : Rep(n + m)) isa[sa[k]] = k;
  auto lcp = atcoder::lcp_array(s + t, sa);
  ecnerwala::RangeMinQuery<int> rmq(lcp);
  vector<int> pos;
  for (int p : Rep(n - m + 1)) {
    int l = isa[p], r = isa[n];
    if (l > r) swap(l, r);
    if (rmq.query(l, r - 1) >= m) pos.push_back(p);
  }

  Fenwick<Mint> dp(n + 1), aux(n + 1);
  dp.add(0, 1);
  for (int r : Rep(1, n + 1)) {
    auto it = upper_bound(ALL(pos), r - m);
    if (it == begin(pos)) continue;
    int p = *prev(it);
    auto temp = dp.sum(p + 1) * (p + 1) - aux.sum(p + 1);
    dp.add(r, temp);
    aux.add(r, temp * r);
  }
  cout << dp.sum(n + 1) - 1 << '\n';
}