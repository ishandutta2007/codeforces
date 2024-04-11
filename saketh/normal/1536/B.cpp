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

#include <vector>
#include <numeric>
#include <algorithm>

namespace stable_counting_sort {
    template<typename T = int>
    T identity(const T& t) { return t; }

    template<typename T_extract_key = int(*)(const int&)>
    const std::vector<int>& permutation(int SZ, int MAX_KEY,
            const T_extract_key &extract_key = identity) {

        static std::vector<int> p;
        p.resize(SZ);

        if (SZ < 256) {
            std::iota(p.begin(), p.end(), 0);
            std::sort(p.begin(), p.end(), [&](int a, int b) {
                return extract_key(a) < extract_key(b);
            });
        } else {
            static std::vector<int> count;
            count.assign(MAX_KEY, 0);
            for (int i = 0; i < SZ; i++)
                count[extract_key(i)]++;
            for (int i = 0; i < MAX_KEY - 1; i++)
                count[i + 1] += count[i];
            for (int i = SZ - 1; i >= 0; i--)
                p[--count[extract_key(i)]] = i;
        }

        return p;
    }
}

#include <array>
#include <vector>
#include <cassert>

template<int MIN_CHAR, int SIGMA>
struct suffix_automaton {
    struct state {
        int len = 0;
        int suffix_link = -1;
        int first_end_pos = -1;
        std::array<int, SIGMA> transitions;
        state() { transitions.fill(-1); }
    };

    int SZ, last;
    std::vector<state> data;
    std::vector<bool> is_clone;

    const state& operator [] (int loc) const { return data[loc]; }

    int create_state(state s = {}) {
        data.push_back(s);
        is_clone.push_back(s.len != 0);
        return int(data.size()) - 1;
    }

    suffix_automaton() : SZ(0) { last = create_state(); }

    template<typename InputIterator>
    suffix_automaton(InputIterator begin, InputIterator end) {
        initialize(begin, end);
    }

    template<typename InputIterator>
    void initialize(InputIterator begin, InputIterator end) {
        SZ = 0;
        data.clear();
        is_clone.clear();
        last = create_state();

        for (InputIterator iter = begin; iter != end; iter++)
            append(*iter);
        initialize_auxiliary_data();
    }

    void append(int c) {
        assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);
        c -= MIN_CHAR;

        int p = last;

        last = create_state();
        data[last].first_end_pos = SZ;
        data[last].len = ++SZ;

        while (p != -1 && data[p].transitions[c] == -1) {
            data[p].transitions[c] = last;
            p = data[p].suffix_link;
        }

        if (p == -1) {
            data[last].suffix_link = 0;
            return;
        }

        int q = data[p].transitions[c];
        if (data[q].len - data[p].len == 1) {
            data[last].suffix_link = q;
            return;
        }

        int pc = create_state(data[q]);
        data[pc].len = data[p].len + 1;

        while (p != -1 && data[p].transitions[c] == q) {
            data[p].transitions[c] = pc;
            p = data[p].suffix_link;
        }

        data[q].suffix_link = pc;
        data[last].suffix_link = pc;
    }

    std::vector<int> reverse_length_order;
    std::vector<int> ct_end_pos;
    void initialize_auxiliary_data() {
        reverse_length_order = stable_counting_sort::permutation(
                int(data.size()), SZ + 1, [&](int loc) { return SZ - data[loc].len; });

        ct_end_pos.assign(data.size(), 0);
        for (int loc : reverse_length_order) {
            if (loc) {
                ct_end_pos[loc] += !is_clone[loc];
                ct_end_pos[data[loc].suffix_link] += ct_end_pos[loc];
            } else ct_end_pos[loc] = 0;
        }
    }

    int transition(int loc, int c) const {
        assert(loc != -1 && MIN_CHAR <= c && c < MIN_CHAR + SIGMA);
        return data[loc].transitions[c - MIN_CHAR];
    }

    template<typename InputIterator>
    int state_associated_with(InputIterator begin, InputIterator end) const {
        int loc = 0;
        for (auto iter = begin; iter != end && loc != -1; iter++)
            loc = transition(loc, *iter);
        return loc;
    }

    template<typename InputIterator>
    int first_occurrence(InputIterator begin, InputIterator end) const {
        int loc = state_associated_with(begin, end);
        return loc == -1 ? -1 : data[loc].first_end_pos - distance(begin, end) + 1;
    }

    template<typename InputIterator>
    int count_occurrences(InputIterator begin, InputIterator end) const {
        int loc = state_associated_with(begin, end);
        return loc == -1 ? 0 : ct_end_pos[loc];
    }
};

void dfs(const suffix_automaton<'a', 26>& sa, int loc, string& ans, string& cur) {
    F0R (c, 26) {
        int nxt = sa[loc].transitions[c];
        cur.push_back('a' + c);

        if (nxt == -1) {
            if (ans.empty() || sz(ans) > sz(cur) || cur < ans) {
                ans = cur;
            }
            cur.pop_back();
            return;
        } else {
            dfs(sa, nxt, ans, cur);
            cur.pop_back();
        }
    }
}

void solve() {
    int N; string s; re(N, s);
    suffix_automaton<'a', 26> sa(all(s));

    string ans = "", cur = "";
    dfs(sa, 0, ans, cur);
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