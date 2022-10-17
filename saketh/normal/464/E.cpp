// modnum {{{
#include <cstdint>
#include <cassert>
#include <limits>
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <unordered_map>

using v_t = int;
using vv_t = int64_t;

template<v_t MOD> struct modnum {
    static_assert(std::numeric_limits<v_t>::max() / 2 >= MOD, "Addition overflows v_t");
    static_assert(std::numeric_limits<vv_t>::max() / MOD >= MOD, "Multiplication overflows vv_t");

    v_t v;
    modnum() : v(0) {}
    modnum(vv_t _v) : v(v_t(_v % MOD)) { if (v < 0) v += MOD; }
    explicit operator v_t() const { return v; }
    friend std::istream& operator >> (std::istream& i, modnum& n) { vv_t w; i >> w; n = modnum(w); return i; }
    friend std::ostream& operator << (std::ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
    friend bool operator <  (const modnum& a, const modnum& b) { return a.v <  b.v; }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // x must be less than 2^32 * m so that x / m fits in a 32-bit integer.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x), quot, rem;
        asm("divl %4\n"
                : "=a" (quot), "=d" (rem)
                : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = fast_mod(vv_t(v) * o.v); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(vv_t e) const {
        if (e < 0) return 1 / this->pow(-e);
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        v_t g = MOD, x = 0, y = 1;
        for (v_t r = v; r != 0; ) {
            v_t q = g / r;
            g %= r; std::swap(g, r);
            x -= q * y; std::swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }

    static constexpr v_t totient() {
        v_t tot = MOD, tmp = MOD;
        for (v_t p = 2; p * p <= tmp; p++) if (tmp % p == 0) {
            tot = tot / p * (p - 1);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot = tot / tmp * (tmp - 1);
        return tot;
    }

    static v_t primitive_root() {
        if (MOD == 1) return 0;
        if (MOD == 2) return 1;

        v_t tot = totient(), tmp = tot;
        std::vector<int> tot_pr;
        for (v_t p = 2; p * p <= tmp; p++) if (tot % p == 0) {
            tot_pr.push_back(p);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot_pr.push_back(tmp);

        for (v_t r = 2; r < MOD; r++) if (std::gcd(r, MOD) == 1) {
            bool root = true;
            for (v_t p : tot_pr) root &= modnum(r).pow(tot / p) != 1;
            if (root) return r;
        }
        assert(false);
    }

    static modnum generator() { static modnum g = primitive_root(); return g; }
    static v_t discrete_log(modnum v) {
        static const v_t M = ceil(std::sqrt(MOD));
        static std::unordered_map<v_t, v_t> table;
        if (table.empty()) {
            modnum e = 1;
            for (v_t i = 0; i < M; i++) { table[e.v] = i; e *= generator(); }
        }
        static modnum f = generator().pow(totient() - M);

        for (v_t i = 0; i < M; i++) {
            if (table.count(v.v)) return table[v.v] + i * M;
            v *= f;
        }
        assert(false);
    }

    static modnum unity_root(int deg) {
        assert(totient() % deg == 0);
        return generator().pow(totient() / deg);
    }

    static modnum unity_root(int deg, int pow) {
        static std::vector<modnum> table{ 0, 1 };
        while (int(table.size()) <= deg) {
            modnum w = unity_root(int(table.size()));
            for (int s = int(table.size()), i = s / 2; i < s; i++) {
                table.push_back(table[i]);
                table.push_back(table[i] * w);
            }
        }
        return table[deg + (pow < 0 ? deg + pow : pow)];
    }

    static modnum factorial(int n) {
        static std::vector<modnum> fact = {1};
        assert(n >= 0);
        if (int(fact.size()) <= n) {
            int had = fact.size();
            fact.resize(n + 1);
            for (int i = had; i <= n; i++) fact[i] = fact[i-1] * i;
        }
        return fact[n];
    }
    static modnum inverse_factorial(int n) {
        static std::vector<modnum> finv = {1};
        assert(n >= 0);
        if (int(finv.size()) <= n) {
            int had = finv.size();
            finv.resz(n + 1), finv[n] = factorial(n).inv();
            for (int i = n - 1; i >= had; i--) finv[i] = finv[i+1] * (i+1);
        }
        return finv[n];
    }

    static modnum small_inv(int n) {
        assert(n > 0); return factorial(n - 1) * inverse_factorial(n);
    }

    static modnum ncr(int n, int r) {
        if (r < 0 || n < r) return 0;
        return factorial(n) * inverse_factorial(r) * inverse_factorial(n - r);
    }
};
// }}}

// polynomial hash {{{
// {{{ numeric/modnum.cpp }}}

#include <vector>
#include <chrono>
#include <random>
#include <array>
#include <cassert>
#include <iostream>

template<typename x_t, int EvaluationPoints, int AlphabetSize>
struct polynomial_hash {
    static x_t pow(int point, int exponent) {
        static std::vector<x_t> x(EvaluationPoints, 1);

        if (int(x.size()) == EvaluationPoints) {
            x.push_back(AlphabetSize);

            std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

            for (int i = 1; i < EvaluationPoints; i++)
                x.push_back(AlphabetSize + rng() % std::max(256, AlphabetSize));
        }

        while (exponent * EvaluationPoints + point >= int(x.size()))
            for (int i = 0; i < EvaluationPoints; i++)
                x.push_back(*(x.end() - EvaluationPoints) * x[EvaluationPoints + i]);

        return x[exponent * EvaluationPoints + point];
    }

    int N;
    std::array<x_t, EvaluationPoints> data;

    polynomial_hash () : N(0) { data.fill(0); }

    polynomial_hash (x_t v) : N(1) { assert(v.v < AlphabetSize); data.fill(v); }

    polynomial_hash (int _N, std::array<x_t, EvaluationPoints> _data) : N(_N), data(_data) {}

    static polynomial_hash concatenate(polynomial_hash a, polynomial_hash b) {
        std::array<x_t, EvaluationPoints> res;
        for (int i = 0; i < EvaluationPoints; i++)
            res[i] = a.data[i] * pow(i, b.N) + b.data[i];
        return { a.N + b.N, res };
    }

    bool operator == (const polynomial_hash &o) const {
        return N == o.N && data == o.data;
    }

    bool operator < (const polynomial_hash &o) const {
        return N != o.N ? N < o.N : data < o.data;
    }

    friend std::ostream& operator << (std::ostream& o, const polynomial_hash& h) {
        o << h.N;
        for (int i = 0; i < EvaluationPoints; i++)
            o << " " << h.data[i];
        return o;
    }

    template<typename InputIterator>
    static std::vector<polynomial_hash> get_prefixes(InputIterator begin, InputIterator end) {
        std::vector<polynomial_hash> res = { polynomial_hash{} };
        for (InputIterator iter = begin; iter != end; iter = next(iter))
            res.push_back(concatenate(res.back(), polynomial_hash(x_t(*iter))));
        return res;
    }

    static polynomial_hash get_substring(const std::vector<polynomial_hash> &prefixes, int first, int last) {
        std::array<x_t, EvaluationPoints> res;
        for (int i = 0; i < EvaluationPoints; i++)
            res[i] = prefixes[last].data[i] - pow(i, last - first) * prefixes[first].data[i];
        return { last - first, res };
    }
};
// }}}

// bignum_addpow2_compare {{{
// {{{ strings/polynomial_hash }}}

#include <vector>
#include <cassert>
#include <iostream>

struct bignum_addpow2_compare {
    using hash_t = polynomial_hash<modnum<int(1e9 + 7)>, 3, 2>;

    struct binary_string {
        hash_t hash;
        int ct_trailing_ones;
        int left, right;

        binary_string(bool bit) : hash(bit), ct_trailing_ones(bit), left(-1), right(-1) {}

        binary_string(hash_t _hash, int _ct_trailing_ones, int _left, int _right)
            : hash(_hash), ct_trailing_ones(_ct_trailing_ones), left(_left), right(_right) {}

        int length() const { return hash.N; }
        bool is_all_ones() const { return hash.N == ct_trailing_ones; }
    };

    std::vector<binary_string> nums = { binary_string(0), binary_string(1) };

    const int one = 1;
    std::vector<int> zero = { 0 };

    int concatenate(int x, int y) {
        nums.emplace_back(
            hash_t::concatenate(nums[x].hash, nums[y].hash),
            nums[y].ct_trailing_ones + (nums[y].is_all_ones() ? nums[x].ct_trailing_ones : 0),
            x,
            y
        );
        return int(nums.size()) - 1;
    }

    int get_zero_of_width(int bit_width) {
        int index = __builtin_ctz(bit_width);
        while (index >= int(zero.size()))
            zero.push_back(concatenate(zero.back(), zero.back()));
        return zero[index];
    }

    int carry_count(int x, int pow) const {
        const int len = nums[x].length();

        if (len <= pow)
            return 0;

        if (nums[x].is_all_ones())
            return len - pow;

        if (len == 1)
            return nums[x].ct_trailing_ones;

        int res = carry_count(nums[x].right, pow);

        if (pow + res >= len / 2)
            res += carry_count(nums[x].left, pow + res - len / 2);

        return res;
    }

    int invert_range(int x, int L, int R) {
        const int len = nums[x].length();
        assert(0 <= L && L < R && R <= len);

        if (len == 1)
            return x ^ 1;

        if (0 == L && R == len && nums[x].is_all_ones())
            return get_zero_of_width(len);

        int right = L < len / 2 ? invert_range(nums[x].right, L, std::min(R, len / 2)) : nums[x].right;
        int left  = R > len / 2 ? invert_range(nums[x].left, std::max(0, L - len / 2), R - len / 2) : nums[x].left;

        return concatenate(left, right);
    }

    int add_pow2(int x, int pow) {
        int carries = carry_count(x, pow);
        while (nums[x].length() <= pow + carries)
            x = concatenate(get_zero_of_width(nums[x].length()), x);
        return invert_range(x, pow, pow + carries + 1);
    }

    bool less_than(int x, int y) const {
        if (nums[x].length() != nums[y].length())
            return nums[x].length() < nums[y].length();
        if (nums[x].length() == 1)
            return nums[x].ct_trailing_ones < nums[y].ct_trailing_ones;
        if (nums[nums[x].left].hash == nums[nums[y].left].hash)
            return less_than(nums[x].right, nums[y].right);
        return less_than(nums[x].left, nums[y].left);
    }

    void print_bits(int x) const {
        if (nums[x].length() == 1) {
            std::cout << nums[x].ct_trailing_ones;
        } else {
            print_bits(nums[x].left);
            print_bits(nums[x].right);
        }
    }
};
// }}}

// dijkstra {{{
#include <cstdlib>
#include <queue>
#include <cassert>
#include <algorithm>
#include <cstring>

template<typename EdgeWeight>
struct WeightedDirectedGraph {
    struct Edge {
        int neighbor;
        EdgeWeight weight;
    };

    int N;
    std::vector<std::vector<Edge>> adj;

    WeightedDirectedGraph (int _N) : N(_N), adj(_N) {}

    void add_directed_edge(int u, int v, EdgeWeight w) {
        adj[u].push_back({v, w});
    }
};

template<typename PathWeight>
struct ShortestPathTree {
    std::vector<int> parent;
    std::vector<PathWeight> shortest_path_wt;

    template<typename EdgeWeight, typename JoinPathAndEdge, typename PathWeightLessThan>
    ShortestPathTree(WeightedDirectedGraph<EdgeWeight> g, const std::vector<int> &sources,
            PathWeight init, JoinPathAndEdge join, PathWeightLessThan less_than) {
        struct Path {
            int destination;
            PathWeight weight;
        };

        auto path_cmp = [&less_than](const Path &a, const Path &b) {
            return less_than(b.weight, a.weight);
        };

        std::priority_queue<Path, std::vector<Path>, decltype(path_cmp)> pq(path_cmp);

        parent.assign(g.N, -1);
        shortest_path_wt.assign(g.N, init);

        for (int source : sources) {
            parent[source] = source;
            pq.push({ source, shortest_path_wt[source] });
        }

        while (!pq.empty()) {
            Path path = pq.top();
            pq.pop();

            if (memcmp(&path.weight, &shortest_path_wt[path.destination], sizeof(PathWeight)))
                continue;

            for (auto edge : g.adj[path.destination]) {
                PathWeight candidate = join(path.weight, edge.weight);
                if (parent[edge.neighbor] == -1 || less_than(candidate, shortest_path_wt[edge.neighbor])) {
                    parent[edge.neighbor] = path.destination;
                    shortest_path_wt[edge.neighbor] = candidate;
                    pq.push({ edge.neighbor, shortest_path_wt[edge.neighbor] });
                }
            }
        }
    }

    bool is_reachable(int destination) const {
        return parent[destination] != -1;
    }

    PathWeight distance(int destination) const {
        if (!is_reachable(destination)) assert(false);
        return shortest_path_wt[destination];
    }

    std::vector<int> list_vertices_on_path(int destination) const {
        if (!is_reachable(destination)) assert(false);

        std::vector<int> path;
        while (parent[destination] != destination) {
            path.push_back(destination);
            destination = parent[destination];
        }
        path.push_back(destination);

        std::reverse(path.begin(), path.end());
        return path;
    }
};
// }}}

#include <iostream>
using namespace std;

// {{{ numeric/bignum_addpow2_compare }}}

// {{{ graphs/dijkstra }}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    WeightedDirectedGraph<int> g(N);

    for (int e = 0; e < M; e++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;

        g.add_directed_edge(u, v, w);
        g.add_directed_edge(v, u, w);
    }

    int S, T;
    cin >> S >> T;
    --S, --T;

    bignum_addpow2_compare nums;

    ShortestPathTree sp(g, {S}, 0,
        [&](int path, int edge) { return nums.add_pow2(path, edge); },
        [&](int a, int b) { return nums.less_than(a, b); }
    );

    if (!sp.is_reachable(T)) {
        cout << -1 << endl;
        return 0;
    }

    int dist = sp.distance(T);
    vector<int> path = sp.list_vertices_on_path(T);

    cout << nums.nums[dist].hash.data[0] << endl;

    cout << path.size() << endl;

    for (int v : path)
        cout << v + 1 << " ";
    cout << endl;

    return 0;
}