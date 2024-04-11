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
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;

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

bool LOCAL = 0;
vi secret;

int q_ct = 0;
bool query(vi locs) {
    if (sz(locs) == 1)
        return true;

    ++q_ct;

    if (LOCAL) {
        int sum = 0;
        trav (e, locs) sum += secret[e];
        return (sum % sz(locs)) == 0;
    }

    pr("? ", sz(locs));
    trav (e, locs) pr(" ", e + 1);
    cout << endl;

    bool resp;
    re(resp);
    return resp;
}

void finish(vi perm) {
    assert(q_ct <= 18 * sz(perm));

    trav (e, perm)
        assert(e != -1);

    if (perm.front() > sz(perm) / 2)
        trav (e, perm) e = sz(perm) + 1 - e;

    if (LOCAL)
        assert(perm == secret);

    pr("!");
    trav (e, perm) pr(" ", e);
    cout << endl;
    exit(0);
}

vi without(vi locs, int loc) {
    vi ret;
    trav (e, locs) if (e != loc) ret.pb(e);
    return ret;
}

vi with(vi locs, int loc) {
    locs.pb(loc);
    return locs;
}

int main() {
    setIO();

    int N; re(N);
    if (LOCAL) {
        secret.resz(N);
        F0R (i, N) secret[i] = i + 1;
        shuffle(all(secret), rng);
        if (secret.front() > N/2) {
            trav (e, secret) e = N + 1 - e;
        }
    }

    vi perm(N, -1);

    auto index_of = [&](int v) {
        F0R (i, N)
            if (perm[i] == v)
                return i;
        assert(0);
    };

    vvi remainder(9, vi(N, -1));

    const int K = 4;
    // locates [1, K] and (N-K, N]
    // and learns all parities
    // uses under (K + 1) * N queries
    {
        vi locs;
        F0R (i, N) locs.pb(i);

        F0R (stage, min(N/2, K)) {
            if (stage == 1) { // after the first time around, learn parities
                int index_of_1 = index_of(1);
                F0R (i, N)
                    if (perm[i] == -1)
                        remainder[2][i] = query({ index_of_1, i });
                    else
                        remainder[2][i] = perm[i]&1;
            }

            array<int, 2> values = { 1 + stage, N - stage };
            if (values[0]&1) swap(values[0], values[1]);

            bool f = 0;
            array<int, 2> indices;
            F0R (i, N) if (perm[i] == -1 && query(without(locs, i))) {
                if (stage == 0) {
                    perm[i] = values[f];
                } else {
                    perm[i] = values[remainder[2][i]];
                }
                indices[f] = i;
                f = 1;
            }
            F0R (i, 2) {
                locs = without(locs, indices[i]);
            }
        }
    }

    if (N <= 2 * K) {
        finish(perm);
    }

    { // learn remainders mod 3, 5, 7, and 8
        vi known = { 1, 2, 3, 4, N-3, N-2, N-1, N};

        vi indices;
        F0R (i, 8) indices.pb(index_of(known[i]));

        for (int mod : {3, 5, 7, 4, 8}) {
            F0R (i, N)
                if (perm[i] != -1)
                    remainder[mod][i] = perm[i] % mod;

            vvi for_residue(mod);

            vb subset(8, 0);
            F0R (i, mod - 1) subset[7 - i] = 1;
            do {
                int total = 0;
                F0R (i, sz(subset))
                    if (subset[i])
                        total += known[i];

                int would_discover = -(total % mod);
                if (would_discover < 0) would_discover += mod;

                if (for_residue[would_discover].empty()) {
                    F0R (i, sz(subset))
                        if (subset[i])
                            for_residue[would_discover].pb(indices[i]);
                }

            } while (next_permutation(all(subset)));

            if (mod % 2) {
                int by_elimination = -1;
                int did = 0;
                vb discovered(mod);

                F0R (r, mod) {
                    if (for_residue[r].empty() || did == mod - 1) {
                        assert(by_elimination == -1);
                        by_elimination = r;
                    } else {
                        F0R (i, N)
                            if (remainder[mod][i] == -1 && query(with(for_residue[r], i)))
                                remainder[mod][i] = r;
                        did++;
                    }
                }

                F0R (i, N)
                    if (remainder[mod][i] == -1)
                        remainder[mod][i] = by_elimination;
            } else {
                F0R (i, N)
                    if (remainder[mod][i] == -1) {
                        int r1 = remainder[mod/2][i],
                            r2 = r1 + mod/2;
                        if (!for_residue[r1].empty())
                            remainder[mod][i] = query(with(for_residue[r1], i)) ? r1 : r2;
                        else {
                            assert(!for_residue[r2].empty());
                            remainder[mod][i] = query(with(for_residue[r2], i)) ? r2 : r1;
                        }
                    }
            }
        }
    }

    F0R (i, N) if (perm[i] == -1) {
        FOR (v, 1, N + 1) {
            bool match = 1;
            for (int mod : { 3, 5, 7, 8 })
                match &= (v % mod) == remainder[mod][i];
            if (match) {
                perm[i] = v;
                break;
            }
        }
    }

    finish(perm);

    // did you check N=1? did you mix up N,M?
    // check your "infinity" and "null" values against the bounds
    return 0;
}