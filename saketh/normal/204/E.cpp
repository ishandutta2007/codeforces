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
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

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

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::const_iterator find(const vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(const vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

namespace __io {
    FILE* setIn(string s) { return freopen(s.c_str(),"r",stdin); }
    FILE* setOut(string s) { return freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

// segment_tree_persistent {{{
template<typename T, typename F, typename I = int>
struct segment_tree_persistent {
    struct node {
        T val;
        int left, right;
    };

    int SZ; T tid; F tt;
    vector<node> data;
    vector<pair<I, int>> root;

    segment_tree_persistent() {}
    segment_tree_persistent(int SZ_, T tid_, F tt_) : tid(tid_), tt(tt_) {
        SZ = 1 << (32 - __builtin_clz(SZ_ - 1));

        data.push_back({ tid, -1, -1 });
        for (int sz = 2; sz <= SZ; sz *= 2)
            data.push_back({ tt(data.back().val, data.back().val), int(data.size()), int(data.size()) });
    }

    // Assigns value v to the element at index i during moment w
    void assign(int i, T v, I w, bool replace = true) {
        assert(0 <= i && i < SZ && (root.empty() || root.back().first <= w));
        root.emplace_back(w, __assign(i, v, w, root.empty() ? __builtin_ctz(SZ) : root.back().second, 0, SZ, replace));
    }
    int __assign(int i, T v, I w, int loc, int L, int R, bool replace) {
        if (R - L == 1) {
            data.push_back({ replace ? v : tt(data[loc].val, v), -1, -1 });
        } else {
            int M = L + (R - L) / 2;
            int left  = i <  M ? __assign(i, v, w, data[loc].left,  L, M, replace) : data[loc].left;
            int right = M <= i ? __assign(i, v, w, data[loc].right, M, R, replace) : data[loc].right;
            data.push_back({ tt(data[left].val, data[right].val), left, right });
        }
        return int(data.size()) - 1;
    }

    // Accumulates the elements at indices in [i, j) as they were before moment w
    T accumulate(int i, int j, I w) const {
        if (i >= j) return tid;
        assert(0 <= i && j <= SZ);
        return __accumulate(i, j, w, tid, root_before(w), 0, SZ);
    }
    int root_before(I w) const {
        static auto cmp = [](pair<I, int> a, pair<I, int> b) { return a.first < b.first; };
        auto it = lower_bound(root.begin(), root.end(), make_pair(w, tid), cmp);
        return it != root.begin() ? prev(it)->second : __builtin_ctz(SZ);
    }
    T __accumulate(int i, int j, I w, T init, int loc, int L, int R) const {
        if (L == i && j == R) {
            init = tt(init, data[loc].val);
        } else {
            int M = L + (R - L) / 2;
            if (i < M) init = __accumulate(i, min(j, M), w, init, data[loc].left,  L, M);
            if (M < j) init = __accumulate(max(i, M), j, w, init, data[loc].right, M, R);
        }
        return init;
    }
};
// }}}

// count_distinct_in_range {{{
template<typename T>
struct count_distinct_in_range {
    segment_tree_persistent<int, decltype(plus<int>())> st;

    count_distinct_in_range(const vector<T> &vals, int copies_allowed = 1) {
        assert(copies_allowed >= 1);

        vector<T> uniq = vals;
        sort(uniq.begin(), uniq.end());
        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());

        vector<vector<int>> occur(uniq.size());
        for (int i = 0; i < int(vals.size()); i++) {
            int v = int(lower_bound(uniq.begin(), uniq.end(), vals[i]) - uniq.begin());
            occur[v].push_back(i);
        }

        st = segment_tree_persistent(int(vals.size()), 0, plus<int>());

        vector<int> successor(vals.size(), -1);
        for (int i = 0; i < int(occur.size()); i++) {
            for (int j = 0; j < min(copies_allowed, int(occur[i].size())); j++)
                st.assign(occur[i][j], 1, -1);

            for (int j = 0; j + copies_allowed < int(occur[i].size()); j++)
                successor[occur[i][j]] = occur[i][j + copies_allowed];
        }

        for (int i = 0; i < int(vals.size()); i++)
            if (successor[i] != -1)
                st.assign(successor[i], 1, i);
    }

    /* Returns the number of distinct elements appearing at indices in [L, R) of 'vals'.
     * The first 'copies_allowed' copies of each distinct value are counted.
     */
    int get_count(int L, int R) {
        return st.accumulate(L, R, L);
    }
};
// }}}

// sparse_table {{{
template<typename T, typename F> struct sparse_table {
    int SZ;
    F tt; // idempotent
    vector<vector<T>> table;

    sparse_table() {}
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
// }}}

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
        for (int i = 0; i < SZ; i++) ct[rank_of[i]]++;
        for (int i = 0; i < SZ - 1; i++) ct[i + 1] += ct[i];

        vector<int> by_rank(SZ);
        for (int i = SZ - 1; i >= 0; i--) by_rank[--ct[rank_of[i]]] = i;

        vector<int> new_ranks(SZ);
        vector<int> by_rank_updated(SZ);
        for (int len = 1; len < SZ; len *= 2) {
            //auto started = std::chrono::system_clock::now();

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

            //cerr << "ROTATED " << chrono::duration<double>(chrono::system_clock::now() - started).count() << endl;

            fill(ct.begin(), ct.end(), 0);
            for (int i = 0; i < SZ; i++) ct[rank_of[i]]++;
            for (int i = 0; i < SZ - 1; i++) ct[i + 1] += ct[i];

            //cerr << "COUNTED " << chrono::duration<double>(chrono::system_clock::now() - started).count() << endl;

            for (int i = SZ - 1; i >= 0; i--)
                by_rank_updated[--ct[rank_of[by_rank[i]]]] = by_rank[i];
            swap(by_rank, by_rank_updated);

            //cerr << "SORTED " << chrono::duration<double>(chrono::system_clock::now() - started).count() << endl;

            pair<int, int> prev = { rank_of_suffix(by_rank[0]), rank_of_suffix(by_rank[0] + len) };
            for (int i = 1; i < SZ; i++) {
                pair<int, int> cur = { rank_of_suffix(by_rank[i]), rank_of_suffix(by_rank[i] + len) };
                new_ranks[by_rank[i]] = new_ranks[by_rank[i - 1]] + (prev != cur);
                prev = cur;
            }
            swap(rank_of, new_ranks);

            //cerr << "RANKED " << chrono::duration<double>(chrono::system_clock::now() - started).count() << endl;
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
        assert(0 <= i && i < SZ && 0 <= j && j < SZ);
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

int main() {
    setIO();

    int N, K; re(N, K);
    vs a(N); re(a);

    vector<int> concat;
    vector<int> which;
    vector<int> begin;

    F0R (i, N) {
        concat.pb(26 + i);
        which.pb(-1);

        begin.pb(sz(concat));

        trav (c, a[i]) {
            concat.pb(c - 'a');
            which.pb(i);
        }
    }

    suffix_array<CYCLIC> sa(all(concat));

    vector<int> from_a(sz(concat));
    iota(all(from_a), INT_MAX / 2);
    for (int i = 0; i < sz(concat); i++) {
        int ai = which[sa.suffix_at_rank(i)];
        if (ai != -1) from_a[i] = ai;
    }

    count_distinct_in_range cd(from_a, 1);

    for (int i = 0; i < N; i++) {
        ll ans = 0;
        for (int pos = 0; pos < sz(a[i]); pos++) {
            int lo = 0, hi = sz(a[i]) - pos + 1;
            while (hi - lo > 1) {
                int mi = lo + (hi - lo) / 2;
                pii ranks = sa.ranks_with_prefix(begin[i] + pos, mi);
                if (cd.get_count(ranks.f, ranks.s) >= K)
                    lo = mi;
                else
                    hi = mi;
            }
            ans += lo;
        }

        if (i) pr(" ");
        pr(ans);
    }

    ps();

    return 0;
}