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

// segment_tree_lazy {{{
template<typename T, typename U, typename TT, typename UU, typename UT>
struct segment_tree_lazy {
    int SZ;
    T tid; U uid; TT tt; UU uu; UT ut;
    vector<T> table;
    vb has; vector<U> ops;

    segment_tree_lazy() {}
    segment_tree_lazy(int SZ_, T tid_, U uid_, TT tt_, UU uu_, UT ut_)
            : tid(tid_), uid(uid_), tt(tt_), uu(uu_), ut(ut_) {
        init(SZ_);
    }
    void init(int SZ_) {
        SZ = SZ_;
        table.resize(2 * SZ, tid), has.resize(SZ), ops.resize(SZ, uid);
    }
    template<typename L> void set_leaves(L create) {
        F0R (i, SZ) table[SZ + i] = create(i);
        FORd (i, 1, SZ) table[i] = tt(table[2 * i], table[2 * i + 1]);
        fill(has.begin(), has.end(), false);
        fill(ops.begin(), ops.end(), U{});
    }

    void _apply(int i, const U &op) {
        table[i] = ut(op, table[i]);
        if (i < SZ) has[i] = true, ops[i] = uu(op, ops[i]);
    }
    void _rebuild(int i) {
        for (i /= 2; i; i /= 2)
            table[i] = ut(ops[i], tt(table[2 * i], table[2 * i + 1]));
    }
    void _propagate(int i) {
        for (int j = 31 - __builtin_clz(i); j > 0; j--) {
            int k = i >> j;
            if (has[k]) {
                _apply(2 * k, ops[k]);
                _apply(2 * k + 1, ops[k]);
                has[k] = false, ops[k] = uid;
            }
        }
    }

    // Replaces the element at index i with v
    void replace(int i, T v) {
        i += SZ;
        _propagate(i);
        table[i] = v;
        _rebuild(i);
    }

    // Applies op to the elements at indices in [i, j)
    void operator()(int i, int j, U op) {
        i += SZ, j += SZ;
        _propagate(i), _propagate(j - 1);
        for (int l = i, r = j; l < r; l /= 2, r /= 2) {
            if (l&1) _apply(l++, op);
            if (r&1) _apply(--r, op);
        }
        _rebuild(i), _rebuild(j - 1);
    }

    // Returns the element at index i
    const T& operator[](int i) {
        i += SZ;
        _propagate(i);
        return table[i];
    }

    // Accumulates the elements at indices in [i, j)
    T operator()(int i, int j) {
        i += SZ, j += SZ;
        _propagate(i), _propagate(j - 1);
        T left = tid, right = tid;
        for (; i < j; i /= 2, j /= 2) {
            if (i&1) left = tt(left, table[i++]);
            if (j&1) right = tt(table[--j], right);
        }
        return tt(left, right);
    }
};
// }}}

struct node {
    int len;
    int tot;
};

auto nn = [](node a, node b) {
    return node {
        a.len + b.len,
        a.tot + b.tot
    };
};

using update = int;

auto uu = [](update a, update b) {
    return update{a + b};
};

auto un = [](update u, node n) {
    return node {
        n.len,
        n.tot + u * n.len
    };
};

int main() {
    setIO();

    int N, M, K; re(N, M, K);

    vi L(M), R(M);
    F0R (i, M) {
        re(L[i], R[i]);
        if (L[i] > R[i]) swap(L[i], R[i]);
        --L[i];
    }

    vector<vector<pair<int, int>>> events(N + 1);
    segment_tree_lazy<node, update, decltype(nn), decltype(uu), decltype(un)> st(N, node{0,0}, update{0}, nn, uu, un);

    int ans = 0;

    F0R (a, N - K + 1) {
        trav (bucket, events) bucket.clear();
        st.set_leaves([](int i) { return node{1, 0}; });

        int cur = 0;

        F0R (i, M) {
            int l = max(L[i], a);
            int r = min(R[i], a + K);

            if (l < r) {
                cur += r - l;

                int enter = max(0, L[i] + (r - l) - K);
                int leave = min(R[i] - (r - l) + 1, N);

                //pd(i, L[i], R[i], enter, leave);

                if (enter < leave) {
                    events[enter].eb(i, 1);
                    events[leave].eb(i, -1);
                }
            } else {
                st(L[i], R[i], 1);
            }
        }

        F0R (b, N - K + 1) {
            for (auto [i, v] : events[b]) {
                st(L[i], R[i], v);

                int l = max(L[i], a);
                int r = min(R[i], a + K);
                cur -= v * (r - l);
            }

            //pd(a, b, cur + st(b, b + K).tot);
            ckmax(ans, cur + st(b, b + K).tot);
        }
    }

    ps(ans);

    return 0;
}