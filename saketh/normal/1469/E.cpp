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

// sparse_table {{{
#include <vector>
#include <cassert>

template<typename T, typename IdempotentBinaryOperation = const T&(*)(const T&, const T&)>
struct sparse_table {
    int SZ;
    IdempotentBinaryOperation TT;
    std::vector<std::vector<T>> data;

    sparse_table() {}

    sparse_table(IdempotentBinaryOperation _TT) : TT(_TT) {}

    template<typename Function>
    sparse_table(int _SZ, IdempotentBinaryOperation _TT, Function fn) : TT(_TT) {
        construct(_SZ, fn);
    }

    template<typename Function>
    void construct(int _SZ, Function fn) {
        SZ = _SZ;

        const int L = 32 - __builtin_clz(std::max(SZ - 1, 1));
        data.assign(L, std::vector<T>(SZ));

        for (int i = 0; i < SZ; i++)
            data[0][i] = fn(i);

        for (int l = 0; l + 1 < L; l++)
            for (int i = 0; i + (2 << l) <= SZ; i++)
                data[l + 1][i] = TT(data[l][i], data[l][i + (1 << l)]);
    }

    // Accumulates the elements at indices in [i, j) in O(1)
    T accumulate(int first, int last) const {
        assert(0 <= first && first < last && last <= SZ);
        int l = last - first > 1 ? 31 - __builtin_clz(last - first - 1) : 0;
        return TT(data[l][first], data[l][last - (1 << l)]);
    }
};
// }}}

// suffix_array {{{
// {{{ data_structures/sparse_table.cpp }}}

#include <vector>
#include <algorithm>

enum BACKFILL { CYCLIC, NEG_INF, POS_INF };
template<BACKFILL FILL>
struct suffix_array {
    int SZ;
    std::vector<int> input;
    std::vector<int> rank_of;
    std::vector<int> lcp_between_ranks;
    std::vector<int> first_suffix_with_rank;

    int read_rank(const std::vector<int>& v, int i) const {
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

    template<typename InputIterator>
    suffix_array(InputIterator begin, InputIterator end) {
        std::vector<int> uniq(begin, end);
        std::sort(uniq.begin(), uniq.end());
        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());

        for (InputIterator iter = begin; iter != end; iter = next(iter))
            input.push_back(int((lower_bound(uniq.begin(), uniq.end(), *iter) - uniq.begin())));

        SZ = int(input.size());

        rank_of = input;

        std::vector<int> ct(SZ);
        for (int i = 0; i < SZ; i++) ct[input[i]]++;
        for (int i = 0; i < SZ - 1; i++) ct[i + 1] += ct[i];

        std::vector<int> by_rank(SZ);
        for (int i = SZ - 1; i >= 0; i--) by_rank[--ct[input[i]]] = i;

        std::vector<int> new_ranks(SZ);
        std::vector<int> by_rank_updated(SZ);
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

            std::pair<int, int> prev = { rank_of_suffix(by_rank[0]), rank_of_suffix(by_rank[0] + len) };
            for (int i = 1; i < SZ; i++) {
                std::pair<int, int> cur = { rank_of_suffix(by_rank[i]), rank_of_suffix(by_rank[i] + len) };
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

    int longest_common_prefix(int i, int j) const {
        static sparse_table<int>
            lcp_between_ranks_rmq(SZ - 1, std::min<int>, [&](int r) { return lcp_between_ranks[r]; });

        assert(FILL != CYCLIC && 0 <= i && i < SZ && 0 <= j && j < SZ);
        int ri = rank_of_suffix(i);
        int rj = rank_of_suffix(j);
        if (ri == rj) return FILL == CYCLIC ? SZ : SZ - i;
        if (ri  > rj) std::swap(ri, rj);
        return lcp_between_ranks_rmq.accumulate(ri, rj);
    }

    std::pair<int, int> ranks_with_prefix(int pos, int len) const {
        assert(0 <= pos && pos + len <= SZ);
        const std::vector<int> &F = first_suffix_with_rank;
        auto less_than = [&](int other_pos, int arg) { return longest_common_prefix(pos, other_pos) < arg; };
        auto geq       = [&](int other_pos, int arg) { return longest_common_prefix(pos, other_pos) >= arg; };
        return std::make_pair(
            lower_bound(F.begin(), F.begin() + rank_of_suffix(pos), len, less_than) - F.begin(),
            lower_bound(F.begin() + rank_of_suffix(pos), F.end(), len, geq) - F.begin()
        );
    }

    int first_occurrence_of(int pos, int len) const {
        static sparse_table<int>
            by_rank_rmq(SZ, std::min<int>, [&](int r) { return first_suffix_with_rank[r]; });

        std::pair<int, int> ranks_of_occurrences = ranks_with_prefix(pos, len);
        return by_rank_rmq.accumulate(ranks_of_occurrences.first, ranks_of_occurrences.second);
    }
};
// }}}

int pow2(int K) {
    if (K > 25)
        return INT_MAX;
    else
        return 1 << K;
}

void solve() {
    int N, K; re(N, K);
    string s; re(s);

    trav (c, s) c ^= 1;

    suffix_array<NEG_INF> sa(all(s));

    // all unique substrings of length K
    vector<int> locs;
    F0R (r, sz(s)) {
        int i = sa.suffix_at_rank(r);
        if (i + K > N)
            continue;

        if (r == 0 || sa.lcp_between_ranks[r - 1] < K)
            locs.pb(i);
    }

    if (sz(locs) == pow2(K)) {
        ps("NO");
        return;
    }

    string ans(K, '?');

    int L = 0, R = sz(locs);

    F0R (i, K) {
        // find first one starting with '1'
        int lo = L - 1, hi = R;
        while (hi - lo > 1) {
            int mi = lo + (hi - lo) / 2;
            if (s[locs[mi] + i] == '1')
                hi = mi;
            else
                lo = mi;
        }

        if (hi - L == pow2(K - i - 1)) {
            ans[i] = '1';
            L = hi;
        } else {
            ans[i] = '0';
            R = hi;
        }
    }

    ps("YES");
    ps(ans);
}

int main() {
    setIO();

    int T; re(T); F0R (t, T) {
        //pr("Case #", t+1, ": ");
        solve();
    }

    return 0;
}