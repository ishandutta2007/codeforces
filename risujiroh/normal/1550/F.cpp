#include <bits/stdc++.h>
#include <x86intrin.h>

namespace bit_op {

__attribute__((target("popcnt"))) int popcnt(uint64_t a) { return _mm_popcnt_u64(a); }
__attribute__((target("bmi"))) int bsf(uint64_t a) { return _tzcnt_u64(a); }
__attribute__((target("lzcnt"))) int bsr(uint64_t a) { return 63 - _lzcnt_u64(a); }
__attribute__((target("bmi2"))) uint64_t pdep(uint64_t a, uint64_t mask) { return _pdep_u64(a, mask); }
__attribute__((target("bmi2"))) uint64_t pext(uint64_t a, uint64_t mask) { return _pext_u64(a, mask); }

}  // namespace bit_op

class FenwickSet {
 public:
  FenwickSet() {}
  explicit FenwickSet(int n) : n_(n), dat(n / 64 + 1), tree(n / 64 + 1) {}
  template <class Generator> FenwickSet(int n, Generator gen) : FenwickSet(n) {
    for (int i = 0; i < n; ++i)
      if (gen(i)) dat[i / 64] |= uint64_t(1) << i % 64;
    for (int i = 0; i < int(std::size(tree)); ++i) tree[i] = bit_op::popcnt(dat[i]);
    for (int i = 0; i < int(std::size(tree)); ++i)
      if (int j = i | (i + 1); j < int(std::size(tree))) tree[j] += tree[i];
  }
  int size() const { return n_; }
  bool operator[](int i) const {
    __glibcxx_assert(0 <= i && i < size());
    return dat[i / 64] >> i % 64 & 1;
  }
  void set() {
    std::fill(std::begin(dat), std::end(dat), -1);
    for (int i = 0; i < int(std::size(tree)); ++i) tree[i] = 64 << bit_op::bsf(i + 1);
  }
  void set(int i) {
    __glibcxx_assert(0 <= i && i < size());
    if ((*this)[i]) return;
    dat[i / 64] |= uint64_t(1) << i % 64;
    for (i /= 64; i < int(std::size(tree)); i |= i + 1) ++tree[i];
  }
  void reset() { std::fill(std::begin(dat), std::end(dat), 0), std::fill(std::begin(tree), std::end(tree), 0); }
  void reset(int i) {
    __glibcxx_assert(0 <= i && i < size());
    if (!(*this)[i]) return;
    dat[i / 64] &= ~(uint64_t(1) << i % 64);
    for (i /= 64; i < int(std::size(tree)); i |= i + 1) --tree[i];
  }
  int rank(int i) const {
    i = std::clamp(i, 0, size());
    int res = bit_op::popcnt(dat[i / 64] & ~-(uint64_t(1) << i % 64));
    for (i /= 64; i; i &= i - 1) res += tree[i - 1];
    return res;
  }
  int select(int k) const {
    if (k < 0) return -1;
    int i = 0;
    for (int step = 1 << std::__lg(std::size(tree)); step; step /= 2)
      if (i + step <= int(std::size(tree)) && tree[i + step - 1] <= k) k -= tree[(i += step) - 1];
    if (i == int(std::size(tree)) || k >= bit_op::popcnt(dat[i])) return size();
    return bit_op::bsf(bit_op::pdep(uint64_t(1) << k, dat[i])) + 64 * i;
  }
  int pred(int i) const { return select(rank(i) - 1); }
  int succ(int i) const { return select(rank(i + 1)); }

 private:
  int n_;
  std::vector<uint64_t> dat;
  std::vector<int> tree;
};

template <class Key, class T> class RadixHeap {
 public:
  static_assert(std::is_integral_v<Key> && !std::is_same_v<Key, bool>);
  bool empty() const { return sz == 0; }
  void emplace(Key key, const T& val) {
    __glibcxx_assert(key >= last);
    v[lg(key ^ last) + 1].emplace_back(key, val);
    ++sz;
  }
  const std::pair<Key, T>& pop() {
    pull();
    --sz;
    return v[0][ptr++];
  }

 private:
  static int lg(Key a) { return a ? std::__lg(a) : -1; }
  std::array<std::vector<std::pair<Key, T>>, 8 * sizeof(Key) + 1> v;
  Key last = 0;
  size_t sz = 0, ptr = 0;
  void pull() {
    if (ptr < std::size(v[0])) return;
    v[0].clear();
    ptr = 0;
    auto&& t = *std::find_if_not(std::begin(v) + 1, std::end(v), [](auto&& e) { return std::empty(e); });
    last = std::min_element(std::begin(t), std::end(t), [](auto&& a, auto&& b) { return a.first < b.first; })->first;
    for (auto&& e : t) v[lg(e.first ^ last) + 1].push_back(e);
    t.clear();
  }
};

char scanc() {
  static char buf[1 << 15], *ptr = std::end(buf);
  if (ptr == std::end(buf)) fread(buf, 1, std::size(buf), stdin), ptr = buf;
  return *ptr++;
}
void printc(char c) {
  static char buf[1 << 15], *ptr = buf;
  if (ptr == std::end(buf) || c == -1) fwrite(buf, 1, ptr - buf, stdout), ptr = buf;
  *ptr++ = c;
}
__attribute__((destructor)) void printc_destructor() { printc(-1); }
template <class Int> Int scan() {
  char c = scanc();
  bool neg = c == '-';
  Int res = neg ? 0 : c & 0xf;
  while ((c = scanc()) >= '0') (res *= 10) += c & 0xf;
  return neg ? -res : res;
}
template <class Int> void print(Int a, char delimiter = '\n') {
  if (a < 0) printc('-'), a = -a;
  char buf[40], *ptr = buf;
  do *ptr++ = '0' | a % 10;
  while (a /= 10);
  while (ptr-- > buf) printc(*ptr);
  printc(delimiter);
}

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  constexpr int L = 1e6;
  int n = scan<int>();
  int q = scan<int>();
  int s = scan<int>() - 1;
  int d = scan<int>();
  vector<int> a(n), ia(L);
  for (int i = 0; i < n; ++i) {
    a[i] = scan<int>() - 1;
    ia[a[i]] = i;
  }
  vector<int> f(n, numeric_limits<int>::max());
  RadixHeap<int, int> rh;
  FenwickSet unvisited(L), pos(L + L + L);
  for (auto&& e : a) unvisited.set(e);
  auto push = [&](int i, int x) {
    if (x >= f[i]) return;
    rh.emplace(f[i] = x, i);
  };
  for (push(s, 0); !empty(rh);) {
    auto [fi, i] = rh.pop();
    if (fi > f[i]) continue;
    unvisited.reset(a[i]);
    for (int x : {unvisited.pred(a[i]), unvisited.succ(a[i])})
      if (0 <= x && x < L) {
        int mn = 1e9;
        if (int t = pos.pred(L + x + 1); t != -1) mn = min(mn, x - (t - L));
        if (int t = pos.succ(L + x - 1); t != L + L + L) mn = min(mn, (t - L) - x);
        push(ia[x], max(f[i], mn));
      }
    for (int c : {a[i] - d, a[i] + d}) {
      if (pos[L + c]) continue;
      pos.set(L + c);
      for (int x : {unvisited.pred(c + 1), unvisited.succ(c - 1)})
        if (0 <= x && x < L) push(ia[x], max(f[i], abs(x - c)));
    }
  }
  while (q--) {
    int i = scan<int>() - 1;
    int k = scan<int>();
    for (char c : string_view(k >= f[i] ? "Yes\n" : "No\n")) printc(c);
  }
}