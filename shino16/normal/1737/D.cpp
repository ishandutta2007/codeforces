#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3")
/* #pragma GCC target("avx2") */
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define repr2(i, m, n) for (auto i = (n); i-- > (m);)
#define repr(i, n) repr2(i, 0, n)
#define all(x) begin(x), end(x)
template <class T>
auto ndvec(size_t n, T&& x) { return vector(n, forward<T>(x)); }
template <class... Ts>
auto ndvec(size_t n, Ts&&... xs) { return vector(n, ndvec(forward<Ts>(xs)...)); }
#line 3 "lib/io.hpp"

struct int1 {
  int val;
  int1(int a = 1) : val(a - 1) {}
  operator int() const { return val; }
};

template <size_t BufSize = 1 << 26>
class stdin_reader {
 public: stdin_reader() { buf[fread(buf, 1, sizeof(buf), stdin)] = 0; } template <class T> enable_if_t<is_integral_v<T>> read(T& x) { skip(); [[maybe_unused]] bool neg = false; if constexpr (is_signed_v<T>) neg = *p == '-' ? (p++, true) : false; x = 0; while (*p > ' ') x = x * 10 + (*p++ & 0x0F); if constexpr (is_signed_v<T>) x = neg ? -x : x; } template <class T> void_t<decltype(&T::val)> read(T& x) { x = T((unsigned)(*this)); } void read(char*& q) { skip(); q = p; while (*p > ' ') p++; *p = 0; } template <size_t N> void read(char (&s)[N]) { read(s); } void read(string& s) { skip(); char* p0 = p; while (*p > ' ') p++; s.assign(p0, p); } template <class T, void_t<decltype(tuple_size<T>::value)>* = nullptr> void read(T& x) { read_tuple_impl(x, make_index_sequence<tuple_size_v<T>>{}); } template <class T, class U> void read(pair<T, U>& x) { read(x.first), read(x.second); } template <class T, size_t N> void read(T (&a)[N]) { for (auto& e : a) read(e); } template <class T> operator T() { T x; return read(x), x; } template <class... Ts> void operator()(Ts&... xs) { (read(xs), ...); } int operator--() { return (int)*this - 1; } template <class T> T* arr(int n) { T* p = new T[n + 1]; rep(i, n) read(p[i]); return p; } template <class T> void vec(vector<T>& v, int n) { v.resize(n); for (auto& e : v) read(e); } template <class T> vector<T> vec(int n) { vector<T> v; return vec(v, n), v; } template <class... Ts> tuple<vector<Ts>...> vecs(int n) { tuple<vector<Ts>...> res; vecs_impl(res, n, make_index_sequence<sizeof...(Ts)>{}); return res; } template <class T> void vvec(vector<vector<T>>& v, int n, int m) { v.resize(n); for (auto& e : v) vec(e, m); } template <class T> vector<vector<T>> vvec(int n, int m) { vector<vector<T>> v; return vvec(v, n, m), v; } template <class... Ts> auto cols(int n) { return transpose(vec<tuple<Ts...>>(n)); } private: char buf[BufSize], *p = buf; void skip() { while (*p <= ' ') p++; } template <class T, size_t... Is> void read_tuple_impl(T& x, index_sequence<Is...>) { (*this)(get<Is>(x)...); } template <class T, size_t... Is> void vecs_impl(T& x, int n, index_sequence<Is...>) { (vec(get<Is>(x), n), ...); } template <class T, size_t... Is> static auto transpose_impl(const vector<T>& v, index_sequence<Is...>) { tuple<vector<decay_t<tuple_element_t<Is, T>>>...> w; (get<Is>(w).reserve(v.size()), ...); for (const auto& row : v) (get<Is>(w).push_back(get<Is>(row)), ...); return w; } template <class T> static auto transpose(const vector<T>& v) { return transpose_impl(v, make_index_sequence<tuple_size_v<T>>{}); }
};

template <size_t BufSize = 1 << 26>
class stdout_writer {
 public: ~stdout_writer() { flush(); } void flush() { fwrite(buf, 1, p - buf, stdout), p = buf; } void write_char(char c) { *p++ = c; } void write(char c) { write_char(c); } template <class T> enable_if_t<is_integral_v<T>> write(T x) { if (!x) return write_char('0'); if constexpr (is_signed_v<T>) if (x < 0) write_char('-'), x = -x; static char tmp[16]; char* q = end(tmp); while (x >= 10000) memcpy(q -= 4, digits.data + x % 10000 * 4, 4), x /= 10000; if (x < 10) write_char('0' + x); else if (x < 100) write_char('0' + (uint8_t)x / 10), write_char('0' + (uint8_t)x % 10); else if (x < 1000) memcpy(p, digits.data + x * 4 + 1, 3), p += 3; else memcpy(p, digits.data + x * 4, 4), p += 4; memcpy(p, q, end(tmp) - q), p += end(tmp) - q; } template <class T> void_t<decltype(&T::val)> write(T x) { write(x.val()); } void write(double x) { static char tmp[40]; sprintf(tmp, "%.15f", x); write(tmp); } void write(const char* s) { while (*s) *p++ = *s++; } void write(const string& s) { memcpy(p, s.c_str(), s.size()), p += s.size(); } template <class T, class U> void write(const pair<T, U>& x) { write(x.first), write_char(' '), write(x.second); } template <class... Ts> void write(const tuple<Ts...>& x) { write_tuple(x, make_index_sequence<sizeof...(Ts)>{}); } template <class... Ts> void write(const Ts&... xs) { ((write(xs), write_char(' ')), ...), --p; } template <class... Ts> void writeln(const Ts&... xs) { write(xs...), write_char('\n'); } template <class... Ts> void operator()(const Ts&... xs) { writeln(xs...); } template <class It> void iter(It first, It last, char sep = ' ') { if (first == last) write_char('\n'); else { while (first != last) write(*first++), write_char(sep); p[-1] = '\n'; } } void Yes(bool b = true) { writeln(b ? "Yes" : "No"); } void YES(bool b = true) { writeln(b ? "YES" : "NO"); } void Takahashi(bool b = true) { writeln(b ? "Takahashi" : "Aoki"); } private: char buf[BufSize], *p = buf; template <class T, size_t... Is> void write_tuple(const T& x, index_sequence<Is...>) { ((write(get<Is>(x)), write_char(' ')), ...), --p; } struct four_digits { char data[40000]; constexpr four_digits() : data() { for (int i = 0; i < 10000; i++) for (int n = i, j = 4; j--;) data[i * 4 + j] = n % 10 + '0', n /= 10; } } static constexpr digits{}; public:
#define INSTANT(s) void s() { writeln(#s); }
  INSTANT(No) INSTANT(NO) INSTANT(Aoki) INSTANT(possible) INSTANT(Possible) INSTANT(POSSIBLE) INSTANT(impossible) INSTANT(Impossible) INSTANT(IMPOSSIBLE)
#undef INSTANT
};

stdin_reader<> in;
stdout_writer<> out;

#line 3 "lib/graph/traits.hpp"

struct unit_edge {
  int to;
  operator int() const { return to; }
  int w() const { return 1; }
};

template <class Weight>
struct weighted_edge {
  int to;
  Weight weight;
  operator int() const { return to; }
  Weight w() const { return weight; }
};

template <class Inner>
struct basic_graph {
  using weight_type = void;
  const Inner& inner;
  basic_graph(const Inner& g) : inner(g) { }
  template <class F>
  void adj(int v, F f) const {
    for (auto u : inner[v]) f(unit_edge{u});
  }
  int deg(int v) const { return inner[v].size(); }
};

template <class Inner, class Weight>
struct basic_weighted_graph {
  using weight_type = Weight;
  const Inner& inner;
  basic_weighted_graph(const Inner& g) : inner(g) { }
  template <class F>
  void adj(int v, F f) const {
    for (auto [u, w] : inner[v]) f(weighted_edge<weight_type>{u, w});
  }
  int deg(int v) const { return inner[v].size(); }
};

template <class Inner>
struct graph_trait {
  using weight_type = typename Inner::weight_type;
  const Inner& g;
  graph_trait(const Inner& g) : g(g) { }
  int size() const { return g.size(); }
  template <class F>
  void adj(int v, F f) const {
    g.adj(v, f);
  }
};

template <class T>
constexpr bool is_weighted_v =
    !is_same_v<typename graph_trait<T>::weight_type, void>;

template <class T>
using weight_t =
    conditional_t<is_weighted_v<T>, typename graph_trait<T>::weight_type, int>;

template <class T>
using edge_t =
    conditional_t<is_weighted_v<T>, weighted_edge<weight_t<T>>, unit_edge>;

template <size_t N>
struct graph_trait<vector<int>[N]> : basic_graph<vector<int>[N]> {
  using basic_graph<vector<int>[N]>::basic_graph;
  int size() const { return N; }
};

template <>
struct graph_trait<vector<vector<int>>> : basic_graph<vector<vector<int>>> {
  using basic_graph<vector<vector<int>>>::basic_graph;
  int size() const { return this->inner.size(); }
};

template <size_t N, class Weight>
struct graph_trait<vector<pair<int, Weight>>[N]>
    : basic_weighted_graph<vector<pair<int, Weight>>[N], Weight> {
      using basic_weighted_graph<
          vector<pair<int, Weight>>[N], Weight>::basic_weighted_graph;
      int size() const { return N; }
    };

template <class Weight>
struct graph_trait<vector<vector<pair<int, Weight>>>>
    : basic_weighted_graph<vector<vector<pair<int, Weight>>>, Weight> {
  using basic_weighted_graph<
      vector<vector<pair<int, Weight>>>, Weight>::basic_weighted_graph;
  int size() const { return this->inner.size(); }
};
#line 3 "lib/range.hpp"

template <class It>
struct range : pair<It, It> {
  using pair<It, It>::pair;
  It begin() const { return this->first; }
  It end() const { return this->second; }
  It cbegin() const { return begin(); }
  It cend() const { return end(); }
  int size() const { return this->second - this->first; }
};
#line 4 "lib/graph/csr.hpp"

template <size_t> struct stdin_reader;

template <class Weight = void, bool Directed = false, bool OneBased = true>
class csr_graph {
 public:
  using weight_type = Weight;

  template <class It>
  csr_graph(int n, It e, It e_last) : n(n), m(distance(e, e_last)) {
    init(e, e_last);
  }
  template <size_t Size = 1 << 26>
  csr_graph(int n, int m, stdin_reader<Size>& read) : n(n), m(m) {
    auto e = read_e(read);
    init(all(e));
  }
  template <size_t Size = 1 << 26>
  csr_graph(stdin_reader<Size>& read) : n(read), m(read) {
    auto e = read_e(read);
    init(all(e));
  }
  template <size_t Size = 1 << 26>
  static csr_graph tree(int n, stdin_reader<Size>& read) {
    return csr_graph(n, n - 1, read);
  }
  template <size_t Size = 1 << 26>
  static csr_graph tree(stdin_reader<Size>& read) {
    int n = read;
    return csr_graph(n, n - 1, read);
  }

  int size() const { return n; }
  range<typename vector<edge_t<csr_graph>>::iterator> operator[](int v) const {
    return {ls[v], rs[v]};
  }
  int deg(int v) { return rs[v] - ls[v]; }
  template <class F>
  void adj(int v, F f) const {
    for_each(ls[v], rs[v], f);
  }

 private:
  int n, m;
  vector<edge_t<csr_graph>> es;
  vector<typename vector<edge_t<csr_graph>>::iterator> ls, rs;
  template <size_t Size = 1 << 26>
  auto read_e(stdin_reader<Size>& read) {
    using E = conditional_t<is_weighted_v<csr_graph>, tuple<int, int, Weight>,
                            pair<int, int>>;
    vector<E> res(m);
    for (auto& e : res) {
      read(e);
      if (OneBased) get<0>(e)--, get<1>(e)--;
    }
    return res;
  }
  template <class It>
  void init(It e, It e_last) {
    if (!Directed) m *= 2;
    es.resize(m);
    ls.resize(n), rs.resize(n);
    vector<int> sz(n);
    for (auto it = e; it != e_last; it++) {
      int from = get<0>(*it), to = get<1>(*it);
      sz[from]++;
      if (!Directed) sz[to]++;
    }
    partial_sum(all(sz), sz.begin());
    rep(v, n) ls[v] = rs[v] = es.begin() + sz[v];
    for (auto it = e; it != e_last; it++) {
      int from = get<0>(*it), to = get<1>(*it);
      if constexpr (is_weighted_v<csr_graph>)
        *--ls[from] = edge_t<csr_graph>{to, get<2>(*it)};
      else
        *--ls[from] = edge_t<csr_graph>{to};
      if (!Directed) {
        if constexpr (is_weighted_v<csr_graph>)
          *--ls[to] = edge_t<csr_graph>{from, get<2>(*it)};
        else
          *--ls[to] = edge_t<csr_graph>{from};
      }
    }
  }
};
#line 3 "lib/func/id.hpp"

struct identity {
  template <class T>
  T operator()(T x) const { return x; }
};
#line 3 "lib/ds/heap.hpp"

template <class T, class Cmp = less<>>
class heap {
 public:
  heap(Cmp cmp = Cmp()) : cmp(cmp), data(1) { }
  heap(int n, Cmp cmp = Cmp()) : cmp(cmp), data(1), pos(n, -1) { }
  // moves out from [second, last)
  template <class It>
  heap(It second, It last, Cmp cmp = Cmp()) : cmp(cmp) {
    init(second, last);
  }
  // moves out from [second, last)
  template <class It>
  void init(It second, It last) {
    data.resize(1), pos.clear();
    int n = distance(second, last);
    data.reserve(n), pos.resize(n);
    for (auto it = second; it != last; it++)
      data.emplace_back(data.size(), move(*it));
    iota(all(pos), 1);
    repr2(v, 1, n / 2 + 1) merge(v);
  }

  bool empty() const { return data.size() == 1; }
  void reserve(int n) { pos.resize(max<size_t>(pos.size(), n), -1); }
  bool contains(int i) const { return i < pos.size() && pos[i] != -1; }
  void insert(int i, T x) {
    assert(!contains(i));
    reserve(i + 1);
    pos[i] = data.size(), data.emplace_back(i, x);
    pushup(pos[i]);
  }
  void modify(int i, T x) {
    assert(contains(i));
    int v = pos[i];
    bool decrease = cmp(x, exchange(data[v].second, x));
    return decrease ? merge(v) : pushup(v);
  }
  void insert_or_modify(int i, T x) {
    return contains(i) ? modify(i, x) : insert(i, x);
  }
  const T& top() const { return data[1].second; }
  pair<int, T> pop() {
    pair<int, T> res = move(data[1]);
    pos[res.first] = -1;
    if (data.size() == 2) {
      data.pop_back();
      return res;
    }
    data[1] = move(data.back()), data.pop_back(), pos[data[1].first] = 1;
    merge(1);
    return res;
  }

 private:
  Cmp cmp;
  vector<pair<int, T>> data;
  vector<int> pos;
  void merge(int v) {
    if (v * 2 >= data.size()) return;
    int l = v * 2, r = v * 2 + 1;
    int c = r < data.size() && cmp(data[l].second, data[r].second) ? r : l;
    if (cmp(data[v].second, data[c].second)) {
      swap(data[v], data[c]), swap(pos[data[v].first], pos[data[c].first]);
      merge(c);
    }
  }
  void pushup(int v) {
    for (int p = v / 2; p && cmp(data[p].second, data[v].second);
         v /= 2, p /= 2)
      swap(data[p], data[v]), swap(pos[data[p].first], pos[data[v].first]);
  }
};
#line 4 "lib/graph/dijkstra.hpp"

template <class G, class Iter>
vector<weight_t<G>> dijkstra(
    const G& graph, Iter s_it, Iter s_last,
    weight_t<G> M = numeric_limits<weight_t<G>>::max()) {
  graph_trait<G> g(graph);
  vector<weight_t<G>> dist(g.size(), M);
  heap<weight_t<G>, greater<>> hp;
  while (s_it != s_last)
    hp.insert(*s_it, weight_t<G>(0)), dist[*s_it++] = weight_t<G>(0);
  while (!hp.empty()) {
    auto [v, w] = hp.pop();
    g.adj(v, [&, v = v](auto&& e) {
      if (dist[e.to] > dist[v] + e.w())
        hp.insert_or_modify(e.to, dist[e.to] = dist[v] + e.w());
    });
  }
  return dist;
}

template <class G>
vector<weight_t<G>> dijkstra(
    const G& graph, int s, weight_t<G> M = numeric_limits<weight_t<G>>::max()) {
  return dijkstra(graph, &s, &s + 1, M);
}
#line 4 "main.cpp"

int dist[500][500];
void solve() {
  int n = in, m = in;
  auto es = in.vec<tuple<int, int, int>>(m);
  vector<pair<int, int>> es2(m);
  rep(i, m) es2[i] = pair(--get<0>(es[i]), --get<1>(es[i]));

  fill(dist[0], dist[n], INT_MAX / 2);
  rep(v, n) dist[v][v] = 0;
  for (auto [u, v] : es2) dist[u][v] = dist[v][u] = 1;
  rep(k, n) rep(i, n) rep(j, n) dist[i][j] =
      min(dist[i][j], dist[i][k] + dist[k][j]);

  auto& d0 = dist[0];
  auto& dn = dist[n-1];
  ll ans = LLONG_MAX;
  for (auto [u, v, w] : es) {
    ans = min(ans, (d0[u] + dn[v] + 1) * 1LL * w);
    ans = min(ans, (d0[v] + dn[u] + 1) * 1LL * w);
  }
  rep(s, n) for (auto [u, v, w] : es) {
    ans = min(ans, (d0[s] + dn[s] + dist[s][u] + 2) * 1LL * w);
    ans = min(ans, (d0[s] + dn[s] + dist[s][v] + 2) * 1LL * w);
  }
  out(ans);
}

int main() {
  int T = in;
  while (T--) solve();
}