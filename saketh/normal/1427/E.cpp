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

// garner's {{{
/*
 * Garner's algorithm: finds the unique v modulo prod(MODS)
 * such that v is congruent to n[i] modulo MODS[i] for all i.
 * Elements of MODS should be pairwise co-prime.
 */

template<typename V> V crt(const vector<V> MODS, const vector<V> n) {
    auto inverse = [](V M, V n) {
        V g = M, x = 0, y = 1;
        for (V r = n; r != 0; ) {
            V q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        assert(g == 1);
        assert(y == M || y == -M);
        return x < 0 ? x + M : x;
    };

    const int M = sz(MODS);

    vector<V> x(M);
    for (int i = 0; i < M; i++) {
        x[i] = n[i];
        for (int j = 0; j < i; j++) {
            x[i] = V(x[i] - x[j]) * inverse(MODS[i], MODS[j] % MODS[i]) % MODS[i];
            if (x[i] < 0) x[i] += MODS[i];
        }
    }

    V v = 0;
    for (int i = M - 1; i >= 0; i--)
        v = MODS[i] * v + x[i];
    return v;
}
// }}}

const ll INF = 5e18;

int main() {
    setIO();

    int x; re(x);
    if (x % 2 == 0) return 0;

    set<ll> made;
    made.insert(x);
    vector<pair<char, pll>> ops;

    auto get_sum = [&](ll a, ll b) {
        assert(made.count(a));
        assert(made.count(b));
        if (made.count(a + b)) return false;
        ops.eb('+', mp(a, b));
        made.insert(a + b);
        return true;
    };
    auto get_xor = [&](ll a, ll b) {
        assert(made.count(a));
        assert(made.count(b));
        if (made.count(a ^ b)) return false;
        ops.eb('^', mp(a, b));
        made.insert(a ^ b);
        return true;
    };

    auto create_mult = [&](ll v, ll c) {
        ll target = v * c;
        ll helper = v;
        ll partial_sum = v;

        c--;
        while (c) {
            if (c & 1) {
                get_sum(partial_sum, helper);
                partial_sum += helper;
            }
            c /= 2;
            get_sum(helper, helper);
            helper += helper;
        }

        assert(made.count(target));
    };

    create_mult(x, (2 << 20) - 1);

    pll use;
    auto find_coprime = [&]() {
        trav (a, made) {
            trav (b, made) {
                if (b >= a) break;
                if (__gcd(a, b) == 1)
                    return use = pll{a, b};
            }
        }
        return use = pll{-1,-1};
    };

    queue<ll> proc;
    trav (v, made) proc.push(v);
    while (!proc.empty()) {
        ll a = proc.front();
        proc.pop();
        assert(made.count(a));

        set<ll> had_made = made;
        trav (b, had_made) {
            if (a != b && !made.count(a ^ b) && (a ^ b) < INF) {
                get_xor(a, b);
                proc.push(a ^ b);
                if (find_coprime().f != -1) goto DONE;
            }
            if (!made.count(a + b) && (a + b) < INF) {
                get_sum(a, b);
                proc.push(a + b);
                if (find_coprime().f != -1) goto DONE;
            }
        }
    }
DONE:;

    auto [a, b] = use;
    if (a % 2 != 0) {
        if (b % 2 == 0) {
            swap(a, b);
        } else {
            get_sum(a, a);
            a += a;
        }
    }

    assert(a % 2 == 0);
    assert(made.count(a));
    assert(made.count(b));
    assert(__gcd(a, b) == 1);

    ll target = crt<ll>({ a, b}, { 0, b - 1 });

    create_mult(a, target / a);
    assert(made.count(target));
    create_mult(b, (target + 1) / b);
    assert(made.count(target + 1));

    get_xor(target, target + 1);
    assert(made.count(1));

    ps(sz(ops));
    trav (op, ops) {
        ps(op.s.f, op.f, op.s.s);
    }

    return 0;
}