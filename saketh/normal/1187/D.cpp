#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define F0R(i, a)       for (int i = 0; i < (a); i++)
#define FORd(i, a, b)   for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a)      for (int i = (a)-1; i >= 0; i--)
#define trav(a, x)      for (auto& a : x)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <size_t I> struct index_t {};

#define _i(i, v) const index_t<i> v{}
_i(0, _0); _i(1, _1); _i(2, _2); _i(3, _3); _i(4, _4);
template<typename... T> struct tp {
    std::tuple<T...> elts;
    tp() {}
    tp(std::tuple<T...> _t) : elts(_t) {}
    template<typename T1, typename... Ts> tp(T1 t1, Ts... ts) : elts(t1, ts...) {}
    template <size_t I> decltype(auto) operator[](index_t<I>) {
        return get<I>(this->elts);
    }
    template <size_t I> decltype(auto) operator[](index_t<I>) const {
        return get<I>(this->elts);
    }
    friend bool operator <(const tp& a, const tp& b) { return a.elts < b.elts; }
};

namespace __input {
    template<typename T, size_t... I> void read_tuple(istream& i, T& t, index_sequence<I...>) {
        ((i >> get<I>(t)), ...);
    }
    template<typename... T> istream& operator>>(istream& i, tp<T...>& t) {
        read_tuple(i, t.elts, index_sequence_for<T...>{}); return i;
    }
    template<typename T1, typename T2> istream& operator >>(istream& i, pair<T1, T2>& p) {
        i >> p.first >> p.second; return i;
    }
    template<typename T, size_t N> istream& operator >>(istream& i, array<T, N>& v) {
        for (auto& e : v) { i >> e; } return i;
    }
    template<typename T> istream& operator >>(istream& i, vector<T>& v) {
        for (auto& e : v) { i >> e; } return i;
    }
}
using namespace __input;

namespace __output {
    template<typename T, size_t... I> void write_tuple(ostream& o, const T& t, index_sequence<I...>) {
        o << "("; ((o << (I ? ", " : "") << get<I>(t)), ...); o << ")";
    }
    template<typename... T> ostream& operator<<(ostream& o, const tp<T...>& t) {
        write_tuple(o, t.elts, index_sequence_for<T...>{}); return o;
    }
    template<typename T1, typename T2> ostream& operator<<(ostream& o, const pair<T1, T2>& t) {
        return o << "(" << t.first << ", " << t.second << ")";
    }
    template<typename T, size_t N> ostream& operator<<(ostream& o, const array<T, N>& a) {
        o << "["; for (int i = 0; i < N; i++) { if (i) o << ", "; o << a[i]; } return o << "]";
    }
    template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
        o << "["; for (int i = 0; i < sz(v); i++) { if (i) o << ", "; o << v[i]; } return o << "]";
    }
}
using namespace __output;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct sp64_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = splitmix64(((uint64_t) new char | 1)
            * chrono::steady_clock::now().time_since_epoch().count());
        return splitmix64(x ^ FIXED_RANDOM);
    }
};
template<class K, class V> using umap = gp_hash_table<K, V, sp64_hash>;

/*
 * Supports range sum queries on a mutable array of Ts.
 * Requires that T's + operator is associative and that T() is the
 * additive identity: T() + t = t = t + T() for any T t.
 */
template<typename T> struct segment_tree {
    int S;
    vector<T> table;

    segment_tree<T>(int _S) : S(_S) {
        table.resize(2 * S);
    }

    segment_tree<T>(auto begin, auto end) : segment_tree(distance(begin, end)) {
        copy(begin, end, table.begin() + S);
        for (int i = S - 1; i > 0; i--)
            table[i] = table[2 * i] + table[2 * i + 1];
    }

    // Replaces the element at index i with v
    void replace(int i, T v) {
        table[i += S] = v;
        for (i /= 2; i > 0; i /= 2) {
            table[i] = table[2 * i] + table[2 * i + 1];
        }
    }

    // Returns the value of the element at index i
    const T& operator()(int i) const { return table[S + i]; }

    // Returns the sum of the elements at indices in [i, j)
    T operator()(int i, int j) const {
        T left{}, right{};
        for (i += S, j += S; i < j; i /= 2, j /= 2) {
            if (i&1) left = left + table[i++];
            if (j&1) right = table[--j] + right;
        }
        return left + right;
    }
};

struct node {
    int v;
    node (int _v = 0) : v(_v) {}
    node operator+(const node& o) const {
        return node(max(v, o.v));
    }
};

void solve() {
    int N;
    cin >> N;

    vi a(N), b(N);
    cin >> a >> b;

    segment_tree<node> st(N);
    F0R (i, N) st.replace(i, node(a[i]));

    umap<int, vi> locs;
    F0R (i, N) {
        locs[a[i]].pb(i);
    }

    F0Rd (i, N) {
        if (locs[b[i]].empty()) {
            cout << "NO\n"; return;
        } else {
            int use = locs[b[i]].back();

            if (st(use, N).v > b[i]) {
                cout << "NO\n"; return;
            }

            st.replace(locs[b[i]].back(), node(0));
            locs[b[i]].pop_back();
        }
    }

    cout << "YES\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    F0R (t, T) solve();

    return 0;
}