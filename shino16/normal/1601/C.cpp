#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define repr2(i, m, n) for (auto i = (n); i-- > (m);)
#define repr(i, n) repr2(i, 0, n)
#define all(x) begin(x), end(x)
#line 3 "lib/io2.hpp"

struct IOPre {
    static constexpr int TEN = 10, SZ = TEN * TEN * TEN * TEN;
    array<char, 4 * SZ> num;
    constexpr IOPre() : num{} {
        for (int i = 0; i < SZ; i++) {
            int n = i;
            for (int j = 3; j >= 0; j--) {
                num[i * 4 + j] = static_cast<char>(n % TEN + '0');
                n /= TEN;
            }
        }
    }
};
struct IO {
#if !HAVE_DECL_FREAD_UNLOCKED
    #define fread_unlocked fread
#endif
#if !HAVE_DECL_FWRITE_UNLOCKED
    #define fwrite_unlocked fwrite
#endif
    static constexpr int SZ = 1 << 17, LEN = 32, TEN = 10, HUNDRED = TEN * TEN,
                         THOUSAND = HUNDRED * TEN, TENTHOUSAND = THOUSAND * TEN,
                         MAGIC_MULTIPLY = 205, MAGIC_SHIFT = 11, MASK = 15,
                         TWELVE = 12, SIXTEEN = 16;
    static constexpr IOPre io_pre = {};
    array<char, SZ> input_buffer, output_buffer;
    int input_ptr_left, input_ptr_right, output_ptr_right;

    IO()
        : input_buffer{},
          output_buffer{},
          input_ptr_left{},
          input_ptr_right{},
          output_ptr_right{} {}
    IO(const IO&) = delete;
    IO(IO&&) = delete;
    IO& operator=(const IO&) = delete;
    IO& operator=(IO&&) = delete;

    ~IO() { flush(); }

    template <class T>
    struct is_char {
        static constexpr bool value = is_same_v<T, char>;
    };

    template <class T>
    struct is_bool {
        static constexpr bool value = is_same_v<T, bool>;
    };

    template <class T>
    struct is_string {
        static constexpr bool value = is_same_v<T, string> ||
                                      is_same_v<T, const char*> ||
                                      is_same_v<T, char*>;
    };

    template <class T, class D = void>
    struct is_custom {
        static constexpr bool value = false;
    };

    template <class T>
    struct is_custom<T, void_t<typename T::internal_value_type>> {
        static constexpr bool value = true;
    };

    template <class T>
    struct is_default {
        static constexpr bool value = is_char<T>::value || is_bool<T>::value ||
                                      is_string<T>::value ||
                                      is_integral_v<T>;
    };

    template <class T, class D = void>
    struct is_iterable {
        static constexpr bool value = false;
    };

    template <class T>
    struct is_iterable<
        T, typename std::void_t<decltype(begin(declval<T>()))>> {
        static constexpr bool value = true;
    };

    template <class T, class D = void, class E = void>
    struct is_applyable {
        static constexpr bool value = false;
    };

    template <class T>
    struct is_applyable<T, void_t<typename tuple_size<T>::type>,
                        void_t<decltype(get<0>(declval<T>()))>> {
        static constexpr bool value = true;
    };

    template <class T>
    static constexpr bool needs_newline = (is_iterable<T>::value ||
                                           is_applyable<T>::value) &&
                                          (!is_default<T>::value);

    template <typename T, typename U>
    struct any_needs_newline {
        static constexpr bool value = false;
    };
    template <typename T>
    struct any_needs_newline<T, index_sequence<>> {
        static constexpr bool value = false;
    };
    template <typename T, size_t I, size_t... Is>
    struct any_needs_newline<T, index_sequence<I, Is...>> {
        static constexpr bool value =
            needs_newline<decltype(get<I>(declval<T>()))> ||
            any_needs_newline<T, index_sequence<Is...>>::value;
    };

    inline void load() {
        memmove(begin(input_buffer),
                begin(input_buffer) + input_ptr_left,
                input_ptr_right - input_ptr_left);
        input_ptr_right =
            input_ptr_right - input_ptr_left +
            static_cast<int>(fread_unlocked(
                begin(input_buffer) + input_ptr_right - input_ptr_left, 1,
                SZ - input_ptr_right + input_ptr_left, stdin));
        input_ptr_left = 0;
    }

    inline void read_char(char& c) {
        if (input_ptr_left + LEN > input_ptr_right) load();
        c = input_buffer[input_ptr_left++];
    }
    inline void read_string(string& x) {
        char c;
        while (read_char(c), c < '!') continue;
        x = c;
        while (read_char(c), c >= '!') x += c;
    }
    template <class T>
    inline enable_if_t<is_integral_v<T>, void> read_int(T& x) {
        if (input_ptr_left + LEN > input_ptr_right) load();
        char c = 0;
        do c = input_buffer[input_ptr_left++];
        while (c < '-');
        [[maybe_unused]] bool minus = false;
        if constexpr (is_signed<T>::value == true)
            if (c == '-') minus = true, c = input_buffer[input_ptr_left++];
        x = 0;
        while (c >= '0')
            x = x * TEN + (c & MASK), c = input_buffer[input_ptr_left++];
        if constexpr (is_signed<T>::value == true)
            if (minus) x = -x;
    }

    inline void skip_space() {
        if (input_ptr_left + LEN > input_ptr_right) load();
        while (input_buffer[input_ptr_left] <= ' ') input_ptr_left++;
    }

    inline void flush() {
        fwrite_unlocked(begin(output_buffer), 1, output_ptr_right, stdout);
        output_ptr_right = 0;
    }

    inline void write_char(char c) {
        if (output_ptr_right > SZ - LEN) flush();
        output_buffer[output_ptr_right++] = c;
    }

    inline void write_bool(bool b) {
        if (output_ptr_right > SZ - LEN) flush();
        output_buffer[output_ptr_right++] = b ? '1' : '0';
    }

    inline void write_string(const string& s) {
        for (auto x : s) write_char(x);
    }

    inline void write_string(const char* s) {
        while (*s) write_char(*s++);
    }

    inline void write_string(char* s) {
        while (*s) write_char(*s++);
    }

    template <typename T>
    inline enable_if_t<is_integral_v<T>, void> write_int(T x) {
        if (output_ptr_right > SZ - LEN) flush();
        if (!x) {
            output_buffer[output_ptr_right++] = '0';
            return;
        }
        if constexpr (is_signed<T>::value == true)
            if (x < 0) output_buffer[output_ptr_right++] = '-', x = -x;
        int i = TWELVE;
        array<char, SIXTEEN> buf{};
        while (x >= TENTHOUSAND) {
            memcpy(begin(buf) + i,
                   begin(io_pre.num) + (x % TENTHOUSAND) * 4, 4);
            x /= TENTHOUSAND;
            i -= 4;
        }
        if (x < HUNDRED) {
            if (x < TEN) {
                output_buffer[output_ptr_right++] = static_cast<char>('0' + x);
            } else {
                uint32_t q =
                    (static_cast<uint32_t>(x) * MAGIC_MULTIPLY) >>
                    MAGIC_SHIFT;
                uint32_t r = static_cast<uint32_t>(x) - q * TEN;
                output_buffer[output_ptr_right] = static_cast<char>('0' + q);
                output_buffer[output_ptr_right + 1] =
                    static_cast<char>('0' + r);
                output_ptr_right += 2;
            }
        } else {
            if (x < THOUSAND) {
                memcpy(begin(output_buffer) + output_ptr_right,
                       begin(io_pre.num) + (x << 2) + 1, 3),
                    output_ptr_right += 3;
            } else {
                memcpy(begin(output_buffer) + output_ptr_right,
                       begin(io_pre.num) + (x << 2), 4),
                    output_ptr_right += 4;
            }
        }
        memcpy(begin(output_buffer) + output_ptr_right,
               begin(buf) + i + 4, TWELVE - i);
        output_ptr_right += TWELVE - i;
    }
    template <typename T_>
    IO& operator<<(T_&& x) {
        using T = typename remove_cv<
            typename remove_reference<T_>::type>::type;
        static_assert(is_custom<T>::value or is_default<T>::value or
                      is_iterable<T>::value or is_applyable<T>::value);
        if constexpr (is_custom<T>::value) {
            write_int(x.get());
        } else if constexpr (is_default<T>::value) {
            if constexpr (is_bool<T>::value) {
                write_bool(x);
            } else if constexpr (is_string<T>::value) {
                write_string(x);
            } else if constexpr (is_char<T>::value) {
                write_char(x);
            } else if constexpr (is_integral_v<T>) {
                write_int(x);
            }
        } else if constexpr (is_iterable<T>::value) {
            // strings are immune
            using E = decltype(*begin(x));
            constexpr char sep = needs_newline<E> ? '\n' : ' ';
            int i = 0;
            for (const auto& y : x) {
                if (i++) write_char(sep);
                operator<<(y);
            }
        } else if constexpr (is_applyable<T>::value) {
            // strings are immune
            constexpr char sep =
                (any_needs_newline<
                    T, make_index_sequence<tuple_size_v<T>>>::value)
                    ? '\n'
                    : ' ';
            int i = 0;
            apply(
                [this, &sep, &i](auto const&... y) {
                    (((i++ ? write_char(sep) : void()), this->operator<<(y)),
                     ...);
                },
                x);
        }
        return *this;
    }
    template <typename T>
    IO& operator>>(T& x) {
        static_assert(is_custom<T>::value or is_default<T>::value or
                      is_iterable<T>::value or is_applyable<T>::value);
        static_assert(!is_bool<T>::value);
        if constexpr (is_custom<T>::value) {
            typename T::internal_value_type y;
            read_int(y);
            x = y;
        } else if constexpr (is_default<T>::value) {
            if constexpr (is_string<T>::value) {
                read_string(x);
            } else if constexpr (is_char<T>::value) {
                read_char(x);
            } else if constexpr (is_integral_v<T>) {
                read_int(x);
            }
        } else if constexpr (is_iterable<T>::value) {
            for (auto& y : x) operator>>(y);
        } else if constexpr (is_applyable<T>::value) {
            apply([this](auto&... y) { ((this->operator>>(y)), ...); }, x);
        }
        return *this;
    }

    IO* tie(nullptr_t) { return this; }
    void sync_with_stdio(bool) {}
};
IO io;
#define cin io
#define cout io

template <class... Ts> void read(Ts&... ts) { (cin >> ... >> ts); }
template <class T, class... Ts> void prtln(const T& t, const Ts&... ts) {
  cout << t;
  (void)(cout << ... << (cout << ' ', ts));
  cout << '\n';
}
#line 3 "lib/alg.hpp"

template <class Unit, class Op>
struct monoid : private Unit, private Op {
    using type = decltype(declval<Unit>()());
    monoid(Unit unit, Op op) : Unit(unit), Op(op) {}
    type unit() const { return Unit::operator()(); }
    type op(type a, type b) const { return Op::operator()(a, b); }
};

template <class Unit, class Op, class Inv>
struct group : monoid<Unit, Op>, private Inv {
    using type = typename monoid<Unit, Op>::type;
    group(Unit unit, Op op, Inv inv) : monoid<Unit, Op>(unit, op), Inv(inv) {}
    type inv(type a) const { return Inv::operator()(a); }
};

template <class T>
struct addition {
    using type = T;
    type unit() const { return 0; }
    type op(type a, type b) const { return a + b; }
    type inv(type a) const { return -a; }
};

template <class T>
struct maximum {
    using type = T;
    type unit() const { return numeric_limits<T>::min(); }
    type op(type a, type b) const { return a > b ? a : b; }
};

template <class T>
struct minimum {
    using type = T;
    type unit() const { return numeric_limits<T>::max(); }
    type op(type a, type b) const { return a > b ? b : a; }
};
#line 4 "lib/ds/fwk.hpp"

template <class M>
class fenwick_tree {
 public:
  using value_type = typename M::type;
  fenwick_tree(vector<value_type> data, M m = M()) : m(m), data(move(data)) {
    data.insert(data.cbegin(), m.unit());
    for (int i = 1; i < data.size(); i++) {
      if (i + lsb(i) < data.size())
        data[i + lsb(i)] = m.op(data[i + lsb(i)], data[i]);
    }
  }
  fenwick_tree(int n = 0, M m = M())
      : fenwick_tree(vector<value_type>(n, m.unit()), m) {}
  int size() const { return data.size() - 1; }
  void clear() { fill(data.begin(), data.end(), m.unit()); }
  void add(int i, value_type v) {
    for (i++; i < data.size(); i += lsb(i)) data[i] = m.op(data[i], v);
  }
  void sub(int i, value_type v) { add(i, m.inv(v)); }
  value_type sum(int r) const {
    value_type res = m.unit();
    for (; r; r -= lsb(r)) res = m.op(res, data[r]);
    return res;
  }
  value_type sum(int l, int r) const { return m.op(m.inv(sum(l)), sum(r)); }
  template <class F>
  int lower_bound(F pred = F()) const {
    int i = 0;
    value_type acc = m.unit();
    if (!pred(acc)) return i;
    for (int w = bit_ceil(data.size()); w >>= 1;) {
      if (i + w < data.size()) {
        value_type acc2 = m.op(acc, data[i + w]);
        if (pred(acc2)) i += w, acc = acc2;
      }
    }
    return i + 1;
  }

 private:
  M m;
  vector<value_type> data;
  static int lsb(int a) { return a & -a; }
};
#line 3 "lib/bit/ctz.hpp"

template <class T>
__attribute__ ((target ("bmi"))) int ctz(T x) {
    using uint = unsigned int;
    using ull = unsigned long long;
    if (!x) return sizeof(T) * 8;
    if constexpr (sizeof(T) <= sizeof(uint)) {
        return __builtin_ctz((uint)x);
    } else if constexpr (sizeof(T) <= sizeof(ull)) {
        return __builtin_ctzll((ull)x);
    } else if constexpr (sizeof(T) <= sizeof(ull) * 2) {
        int l = ctz((ull)x);
        return l != sizeof(ull) * 8 ? l : l + ctz((ull)(x >> sizeof(ull) * 8));
    }
}
#line 3 "lib/bit/clz.hpp"

template <class T>
__attribute__ ((target ("lzcnt"))) int clz(T x) {
    using uint = unsigned int;
    using ull = unsigned long long;
    if (!x) return sizeof(T) * 8;
    if constexpr (sizeof(T) <= sizeof(uint)) {
        return __builtin_clz((uint)x);
    } else if constexpr (sizeof(T) <= sizeof(ull)) {
        return __builtin_clzll((ull)x);
    } else if constexpr (sizeof(T) <= sizeof(ull) * 2) {
        int l = clz((ull)(x >> sizeof(ull) * 8));
        return l != sizeof(ull) * 8 ? l : l + clz((ull)x);
    }
}
#line 4 "lib/bit/ilog2.hpp"

template <class T>
int ilog2(T x) { assert(x != 0); return sizeof(T) * 8 - 1 - clz(x); }

template <class T>
int ilog2_ceil(T x) { return x == 0 || x == 1 ? 1 : ilog2(x - 1); }

template <class T>
T bit_floor(T x) { return T(1) << ilog2(x); }

template <class T>
T bit_ceil(T x) { return T(1) << ilog2_ceil(x); }
#line 6 "lib/ds/lazy_segtree.hpp"

template <class M, class A, class Act>
class lazy_segment_tree {
 public:
  using value_type = typename M::type;
  using actor_type = typename A::type;
  template <class Iter>
  lazy_segment_tree(Iter first, Iter last, M m = M(), A a = A(), Act f = Act())
      : m(m), a(a), f(f), data((last - first) * 2), lazy(last - first, a.unit()) {
    copy(first, last, data.begin() + (last - first));
    init();
  }
  lazy_segment_tree(const vector<value_type>& data, M m = M(), A a = A(),
                    Act f = Act())
      : lazy_segment_tree(all(data), m, a, f) {}
  lazy_segment_tree(int n = 0, M m = M(), A a = A(), Act f = Act())
      : m(m), a(a), f(f), data(n * 2, m.unit()), lazy(n, a.unit()) {}
  void init() {
    for (int i = size(); --i;) data[i] = m.op(data[i << 1], data[i << 1 | 1]);
  }
  int size() const { return data.size() / 2; }
  value_type prod(int l, int r) {
    flush(trunc(l + size()));
    flush(trunc(r + size()) - 1);
    value_type accl = m.unit(), accr = m.unit();
    for (l += size(), r += size(); l < r; l >>= 1, r >>= 1) {
      if (l & 1) accl = m.op(accl, data[l++]);
      if (r & 1) accr = m.op(data[--r], accr);
    }
    return m.op(accl, accr);
  }
  void apply(int l, int r, actor_type x) {
    if (x == a.unit()) return;
    flush(trunc(l + size()));
    flush(trunc(r + size()) - 1);
    for (int L = l + size(), R = r + size(); L < R; L >>= 1, R >>= 1) {
      if (L & 1) apply(L++, x);
      if (R & 1) apply(--R, x);
    }
    build(trunc(l + size()));
    build(trunc(r + size()) - 1);
  }
  void add(int i, value_type v) { exec(i, [=](value_type& e) { e = m.op(e, v); }); }
  void set(int i, value_type v) { exec(i, [=](value_type& e) { e = move(v); }); }
  template <class F>
  void exec(int i, F f) {
    flush(trunc(i + size()));
    f(data[i + size()]);
    build(trunc(i + size()));
  }

 private:
  M m;
  A a;
  Act f;
  vector<value_type> data;
  vector<actor_type> lazy;
  static int trunc(int a) { return a >> ctz(a); }
  void apply(int i, actor_type x) {
    data[i] = f(data[i], x);
    if (i < size()) lazy[i] = a.op(lazy[i], x);
  }
  void push(int i) {
    if (lazy[i] != a.unit()) {
      apply(i << 1, lazy[i]);
      apply(i << 1 | 1, lazy[i]);
      lazy[i] = a.unit();
    }
  }
  void upd(int i) { data[i] = m.op(data[i << 1], data[i << 1 | 1]); }
  void flush(int i) { if (i) for (int s = ilog2(i); s > 0; s--) push(i >> s); }
  void build(int i) { for (; i >>= 1;) upd(i); }
};
#line 5 "main.cpp"

using uint = unsigned int;

uint t, n, m, a[1000000], b[1000000], init[1000002];
uint acmp[1000000], *ap;
uint idx[1000000];

ll inv() {
  ap = copy(a, a + n, acmp);
  sort(acmp, ap);
  ap = unique(acmp, ap);
  fenwick_tree fwk(ap - acmp, addition<uint>{});
  ll ans = 0;
  repr(i, n) {
    uint j = lower_bound(acmp, ap, a[i]) - acmp;
    ans += fwk.sum(j);
    fwk.add(j, 1);
  }
  return ans;
}

int main() {
  read(t);
  iota(all(init), 0);
  while (t--) {
    read(n, m);
    rep(i, n) read(a[i]);
    rep(i, m) read(b[i]);
    sort(b, b + m);
    lazy_segment_tree seg(init, init + n + 1,
                          monoid([&] { return uint(1) << 30; },
                                 [&](uint a, uint b) { return min(a, b); }),
                          addition<uint>{}, plus<uint>{});
    iota(idx, idx + n, 0);
    sort(idx, idx + n, [](uint i, uint j) { return a[i] < a[j]; });
    ll ans = 0;
    uint *lt = idx, *leq = idx;
    rep(i, m) {
      while (leq != idx + n && b[i] >= a[*leq]) {
        uint j = *leq++;
        seg.apply(j + 1, n + 1, -1);
      }
      while (lt != idx + n && b[i] > a[*lt]) {
        uint j = *lt++;
        seg.apply(0, j + 1, 1);
      }
      ans += seg.prod(0, n + 1);
    }
    printf("%lld\n", ans + inv());
  }
}