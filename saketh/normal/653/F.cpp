#include <bits/stdc++.h>
using namespace std;

// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const deque<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const deque<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

namespace __numeric {
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type floor(T n, T d) {
        assert(d != 0);
        if (d < 0) tie(n, d) = mp(-n, -d);
        return n / d - ((n < 0) && (n % d));
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type ceil(T n, T d) {
        assert(d != 0);
        if (d < 0) tie(n, d) = mp(-n, -d);
        return n / d + ((n > 0) && (n % d));
    }
};
using namespace __numeric;

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::iterator find(vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }
    template<typename C, typename T, typename OP> vector<T> prefixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0R (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0Rd (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
    }
}
using namespace __algorithm;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct monostate {
    friend istream& operator>>(istream& is, const monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const monostate& ms) { return os; }
    friend monostate operator+(const monostate& a, const monostate& b) { return a; }
} ms;
#pragma GCC diagnostic pop

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << fixed << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

template<typename T, typename F> struct sparse_table {
    int SZ;
    F tt; // idempotent
    vector<vector<T>> table;

    sparse_table() : SZ(0) {}
    template<typename I> sparse_table(int SZ_, F tt_, I init) : SZ(SZ_), tt(tt_) {
        const int L = 32 - __builtin_clz(max(SZ - 1, 1));
        table.resz(L, vector<T>(SZ));

        for (int i = 0; i < SZ; i++) table[0][i] = init(i);

        for (int l = 0; l + 1 < L; l++)
            for (int i = 0; i + (2 << l) <= SZ; i++)
                table[l+1][i] = tt(table[l][i], table[l][i + (1 << l)]);
    }

    // Accumulates the elements at indices in [i, j) in O(1)
    T operator()(int i, int j) const {
        assert(0 <= i && i < j && j <= SZ);
        int l = j - i - 1 ? 31 - __builtin_clz(j - i - 1) : 0;
        return tt(table[l][i], table[l][j - (1 << l)]);
    }
};

enum BACKFILL { CYCLIC, NEG_INF, POS_INF };
template<BACKFILL FILL>
struct suffix_array {
    int SZ;
    vector<int> input;
    vector<int> rank_of;
    vector<int> lcp_between_ranks;
    vector<int> first_suffix_with_rank;

    int read_rank(const vector<int>& v, int i) const {
        if (i < SZ) {
            return v[i];
        } else switch (FILL) {
            case CYCLIC:  return v[i - SZ];
            case NEG_INF: return -1;
            case POS_INF: return SZ;
        }
    }

    int rank_of_char  (int i) const { return read_rank(input, i); }
    int rank_of_suffix(int i) const { return read_rank(rank_of, i); }
    int suffix_at_rank(int r) const { return first_suffix_with_rank[r]; }

    template<typename I>
    suffix_array(I begin, I end) {
        vector<int> uniq(begin, end);
        sort(uniq.begin(), uniq.end());
        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());

        for (I iter = begin; iter != end; iter = next(iter))
            input.push_back(int((lower_bound(uniq.begin(), uniq.end(), *iter) - uniq.begin())));

        SZ = int(input.size());

        rank_of = input;

        vector<int> ct(SZ);
        for (int i = 0; i < SZ; i++) ct[input[i]]++;
        for (int i = 0; i < SZ - 1; i++) ct[i + 1] += ct[i];

        vector<int> by_rank(SZ);
        for (int i = SZ - 1; i >= 0; i--) by_rank[--ct[input[i]]] = i;

        vector<int> new_ranks(SZ);
        vector<int> by_rank_updated(SZ);
        for (int len = 1; len < SZ; len *= 2) {
            int tail = 0;
            if (FILL == NEG_INF)
                for (int i = SZ - len; i < SZ; i++)
                    by_rank_updated[tail++] = i;
            for (int rank = 0; rank < SZ; rank++)
                if (by_rank[rank] >= len)
                    by_rank_updated[tail++] = by_rank[rank] - len;
                else if (FILL == CYCLIC)
                    by_rank_updated[tail++] = by_rank[rank] - len + SZ;
            if (FILL == POS_INF)
                for (int i = SZ - len; i < SZ; i++)
                    by_rank_updated[tail++] = i;
            swap(by_rank, by_rank_updated);

            fill(ct.begin(), ct.end(), 0);
            for (int i = 0; i < SZ; i++) ct[rank_of[i]]++;
            for (int i = 0; i < SZ - 1; i++) ct[i + 1] += ct[i];

            for (int i = SZ - 1; i >= 0; i--)
                by_rank_updated[--ct[rank_of[by_rank[i]]]] = by_rank[i];
            swap(by_rank, by_rank_updated);

            pair<int, int> prev = { rank_of_suffix(by_rank[0]), rank_of_suffix(by_rank[0] + len) };
            for (int i = 1; i < SZ; i++) {
                pair<int, int> cur = { rank_of_suffix(by_rank[i]), rank_of_suffix(by_rank[i] + len) };
                new_ranks[by_rank[i]] = new_ranks[by_rank[i - 1]] + (prev != cur);
                prev = cur;
            }
            swap(rank_of, new_ranks);
        }

        int R = *max_element(rank_of.begin(), rank_of.end()) + 1;

        first_suffix_with_rank.resize(R);
        for (int i = SZ - 1; i >= 0; i--)
            first_suffix_with_rank[rank_of_suffix(i)] = i;

        lcp_between_ranks.resize(SZ - 1);
        for (int i = 0, len = 0; i < SZ; i++) {
            if (rank_of_suffix(i) == R - 1)
                continue;
            int j = suffix_at_rank(rank_of_suffix(i) + 1);
            while (len < SZ && rank_of_char(i + len) == rank_of_char(j + len))
                len++;
            lcp_between_ranks[rank_of_suffix(i)] = len;
            if (len) --len;
        }
    }

    struct smaller {
        int operator()(int x, int y) const { return min(x, y); }
    } cmp;

    int longest_common_prefix(int i, int j) const {
        static sparse_table<int, smaller>lcp_between_ranks_rmq(SZ - 1, cmp,
                [&](int r) { return lcp_between_ranks[r]; });
        assert(FILL != CYCLIC && 0 <= i && i < SZ && 0 <= j && j < SZ);
        int ri = rank_of_suffix(i);
        int rj = rank_of_suffix(j);
        if (ri == rj) return FILL == CYCLIC ? SZ : SZ - i;
        if (ri  > rj) swap(ri, rj);
        return lcp_between_ranks_rmq(ri, rj);
    }

    pair<int, int> ranks_with_prefix(int pos, int len) const {
        assert(0 <= pos && pos + len <= SZ);
        const vector<int> &fswr = first_suffix_with_rank;
        auto less_than = [&](int other_pos, int arg) { return longest_common_prefix(pos, other_pos) < arg; };
        auto geq       = [&](int other_pos, int arg) { return longest_common_prefix(pos, other_pos) >= arg; };
        return make_pair(
            lower_bound(fswr.begin(), fswr.begin() + rank_of_suffix(pos), len, less_than) - fswr.begin(),
            lower_bound(fswr.begin() + rank_of_suffix(pos), fswr.end(), len, geq) - fswr.begin()
        );
    }

    int first_occurence_of(int pos, int len) const {
        static sparse_table<int, smaller> by_rank_rmq(SZ, cmp, [&](int r) { return first_suffix_with_rank[r]; });
        pair<int, int> ranks_of_occurences = ranks_with_prefix(pos, len);
        return by_rank_rmq(ranks_of_occurences.first, ranks_of_occurences.second);
    }
};

struct node {

};

int main() {
    setIO();

    int N; re(N);
    string s; re(s);
    suffix_array<NEG_INF> sa(all(s));

    vector<int> pref(N + 1);
    F0R (i, N) pref[i + 1] = pref[i] + (s[i] == '(' ? 1 : -1);

    vector<int> uniq = pref;
    dedup(uniq);

    const int U = sz(uniq);
    vector<vector<int>> occur(U);
    F0R (i, N + 1) occur[index(uniq, pref[i])].pb(i);

    auto get_ct = [&](int pos, int min_len, int max_len) {
        int inx = index(uniq, pref[pos]);
        if (inx) {
            auto it = lower_bound(all(occur[inx - 1]), pos);
            if (it != occur[inx - 1].end())
                ckmin(max_len, *it - pos);
        }
        if (min_len >= max_len) return 0;
        return int(lower_bound(all(occur[inx]), pos + max_len)
            - lower_bound(all(occur[inx]), pos + min_len));
    };

    ll ans = 0;
    F0R (r, N) {
        int i = sa.suffix_at_rank(r);
        int min_len = r ? sa.lcp_between_ranks[r - 1] + 1 : 1;
        int max_len = N - i + 1;
        int ct = get_ct(i, min_len, max_len);
        //pd(r, i, s.substr(i), min_len, max_len, ct);
        ans += ct;
    }
    ps(ans);

    // did you check N=1? did you mix up N,M?
    // check your "infinity" and "null" values against the bounds
    return 0;
}