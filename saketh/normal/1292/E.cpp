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

// frac {{{
template<typename v_t = long long> struct frac {
    v_t n, d;
    frac(v_t _n = 0, v_t _d = 1) : n(_n), d(_d) {
        assert(n != 0 || d != 0);
        if (d < 0) { n *= -1; d *= -1; }
        v_t g = __gcd(abs(n), d);
        n /= g;
        d /= g;
    }
    friend ostream& operator << (ostream& o, const frac& f) {
        return o << f.n << "/" << f.d;
    }

#define define_relational_operator(OP) \
    friend bool operator OP (const frac& a, const frac& b) { \
        return a.n * b.d OP b.n * a.d; \
    }
    define_relational_operator(<)
    define_relational_operator(<=)
    define_relational_operator(==)
    define_relational_operator(!=)
    define_relational_operator(>)
    define_relational_operator(>=)

    friend frac min(const frac a, const frac b) { return a <= b ? a : b; }
    friend frac max(const frac a, const frac b) { return a >= b ? a : b; }

    frac& operator += (const frac& b) { return *this = frac(n*b.d+b.n*d, d*b.d); }
    frac& operator -= (const frac& b) { return *this = frac(n*b.d-b.n*d, d*b.d); }
    frac& operator *= (const frac& b) { return *this = frac(n*b.n, d*b.d); }
    frac& operator /= (const frac& b) { return *this = frac(n*b.d, d*b.n); }
    friend frac operator + (const frac& a, const frac& b) { return frac(a) += b; }
    friend frac operator - (const frac& a, const frac& b) { return frac(a) -= b; }
    friend frac operator * (const frac& a, const frac& b) { return frac(a) *= b; }
    friend frac operator / (const frac& a, const frac& b) { return frac(a) /= b; }

    explicit operator double() const { return double(n)/d; }
    v_t floor() { assert(d > 0); return n / d - ((n < 0) && (n % d)); }
    v_t ceil() { assert(d > 0); return n / d + ((n > 0) && (n % d)); }

    // canonical continued fraction
    vector<v_t> to_cont() const {
        if (d == 0) return { LLONG_MAX };
        vector<v_t> cont;
        for (v_t n = this->n, d = this->d; ; swap(n, d)) {
            v_t f = (n >= 0 ? n : n - d + 1) / d;
            cont.push_back(f);
            n -= f * d;
            if (n == 0) break;
        }
        return cont;
    }

    static frac from_cont(const vector<v_t>& cont) {
        v_t n = 1, d = 0;
        for (int i = int(cont.size()) - 1; i >= 0; i--) {
            swap(n, d);
            n += d * cont[i];
        }
        return { n, d };
    }

    // "best" fraction in (x, y): minimizes both n and d
    friend frac best_in(const frac x, const frac y) {
        assert(x < y);

        vector<v_t> x1 = x.to_cont(), y1 = y.to_cont();
        vector<v_t> x2 = x1; x2.back()--; x2.push_back(1);
        vector<v_t> y2 = y1; y2.back()--; y2.push_back(1);

        auto z = [](const vector<v_t>& a, const vector<v_t>& b) {
            vector<v_t> c;
            for (int i = 0; ; i++) {
                v_t ai = i < a.size() ? a[i] : LLONG_MAX;
                v_t bi = i < b.size() ? b[i] : LLONG_MAX;
                if (ai != bi) {
                    c.push_back(min(ai, bi) + 1);
                    return from_cont(c);
                }
                c.push_back(ai);
            }
        };

        frac ans = { 1, 0 };
        for (const frac f : {z(x1, y1), z(x1, y2), z(x2, y1), z(x2, y2)}) {
            if (x < f && f < y && (ans.d == 0 || f.d < ans.d))
                ans = f;
        }
        return ans;
    }
};
// }}}
using fr = frac<int>;

const int LIM = 5;
vvi qs[LIM];

void gen(vi q) {
    qs[sz(q)].pb(q);
    if (sz(q) + 1 < LIM) {
        q.pb(0);
        F0R (lv, 3) q.back() = lv, gen(q);
    }
}

map<ll, vvi> groups(vvi pos, vi q) {
    map<ll, vvi> res;
    trav (e, pos) {
        ll m = 0;
        F0R (i, sz(e) - sz(q) + 1) {
            bool f = 1;
            F0R (j, sz(q)) f &= e[i + j] == q[j];
            if (f) m |= 1ll << i;
        }
        res[m].pb(e);
    }
    return res;
}

map<vvi, pair<fr, vi>> decision;
bool solve(vvi pos, fr energy) {
    if (sz(pos) == 1) {
        assert(energy >= fr{0});
        decision[pos] = mp(fr{0}, vi{});
        return true;
    }
    if (energy <= fr{1, sz(pos[0]) * sz(pos[0])}) return false;

    auto it = decision.find(pos);
    if (it != decision.end() && it->s.f <= energy) return true;

    vector<tuple<fr, vi, map<ll, vvi>>> candidates;
    FOR (qlen, 1, min(LIM, sz(pos[0]) + 1)) {
        if (fr{1, qlen * qlen} > energy) continue;
        trav (q, qs[qlen]) {
            map<ll, vvi> res = groups(pos, q);
            if (sz(res) == 1) continue;

            int biggest = 0;
            trav (e, res) ckmax(biggest, sz(e.s));
            candidates.eb(fr{biggest, qlen * qlen}, q, res);
        }
    }
    sort_by(candidates, get<0>(a) < get<0>(b));

    trav (e, candidates) {
        bool ok = 1;
        auto [_, q, res] = e;
        trav (g, res) {
            ok &= solve(g.s, energy - fr{1, sz(q) * sz(q)});
        }
        if (ok) {
            decision[pos] = mp(energy, q);
            return true;
        }
    }

    return false;
}

string format(vi str) {
    string res;
    F0R (i, sz(str)) res.pb("CHO"[str[i]]);
    return res;
}
void print(vi str) {
    cout << format(str) << endl;
}

const bool LOCAL = 0;
string secret;

fr energy = {7,5};
ll query(vi str) {
    fr use{1, sz(str) * sz(str)};
    assert(energy >= use);
    energy -= use;

    if (LOCAL) {
        string check = format(str);
        ll m = 0;
        F0R (i, sz(secret) - sz(check) + 1)
            if (secret.substr(i, sz(check)) == check)
                m |= 1ll << i;
        return m;
    }

    pr("? "), print(str);
    int K, v; ll m = 0; re(K);
    F0R (i, K) re(v), m |= 1ll << --v;
    return m;
}

vvi finish(vvi pos) {
    set<vi> f1;
    trav (e, pos) f1.insert({ e.begin(), e.end() - 1 });
    if (sz(f1) == 2) {
        ll res = query(*f1.begin());
        pos = groups(pos, *f1.begin())[res];
    } else assert(sz(f1) == 1);
    if (sz(pos) == 1) return pos;
    assert(sz(pos) == 2);
    return groups(pos, pos[0])[query(pos[0])];;
}

void solve() {
    energy = {7,5};

    int N; re(N);
    if (LOCAL) {
        secret.clear(); F0R (i, N) secret.pb("CHO"[rng() % 3]);
        cerr << secret << endl;
    }

    vvi pos;
    if (N == 4) {
        pos = qs[4];
        {
            const vvi ask = {{0,0}, {0,2}, {0,1}, {2,1}};
            trav (out, ask) {
                int res = query(out);
                pos = groups(pos, out)[res];
                if (res) break;
            }
        }
        {
            solve(pos, energy);
            while (sz(pos) > 1) {
                vi out = decision[pos].s;
                int res = query(out);
                pos = groups(pos, out)[res];
            }
        }
    } else {
        vi known(N, -1);
        {
            const vvi ask = {{0,0}, {0,1}, {0,2}, {1,2}, {2,2}};
            trav (out, ask) {
                ll res = query(out);
                F0R (i, N) if (res & (1ll << i)) {
                    F0R (j, sz(out)) known[i + j] = out[j];
                }
            }
            FOR (i, 1, N - 1) if (known[i] == -1) known[i] = 1;
        }
        {
            vi tmp = known;
            F0R (fv, 3) if (fv != 0) {
                if (known.front() == -1) tmp.front() = fv;
                F0R (lv, 3) if (lv != 2) {
                    if (known.back() == -1) tmp.back() = lv;
                    pos.pb(tmp);
                }
            }
            dedup(pos);
        }

        pos = finish(pos);
    }

    if (LOCAL) assert(format(pos[0]) == secret);
    pr("! "), print(pos[0]);
    int resp; re(resp); assert(resp);
}

int main() {
    setIO();

    gen({});
    int T; re(T); F0R (t, T) {
        //pr("Case #", t+1, ": ");
        solve();
    }

    // did you check N=1? did you mix up N,M?
    // check your "infinity" and "null" values against the bounds
    return 0;
}