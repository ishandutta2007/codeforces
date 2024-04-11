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
    template<class T1, class T2> void pr(const map<T1,T2,greater<int>>& x);

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
    template<class T1, class T2> void pr(const map<T1,T2,greater<int>>& x) { prContain(x); }

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

struct monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))monostate& ms) { return os; }
} ms;

template<typename W=monostate> struct wedge {
    int u, v, i; W w;
    wedge<W>(int _u=-1, int _v=-1, int _i=-1) : u(_u), v(_v), i(_i) {}
    int operator[](int loc) const { return u ^ v ^ loc; }
    friend void re(wedge& e) { re(e.u, e.v, e.w); --e.u, --e.v; }
    friend void pr(const wedge& e) { pr(e.u, "<-", e.w, "->", e.v); }
};

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

int main() {
    setIO();

    struct block {
        int bl, br, SZ;

        ll totD = 0;
        int cA = 0, cB = 0, no;
        vi hA, hB;
        vpii B, Bo, A, Ao;

        block (int _bl, int _br) : bl(_bl), br(_br), SZ(br - bl), no(SZ) {
            hA.resz(SZ), hB.resz(SZ);
        }

        void put(int& a, int b) { a = (a && b) ? min(a, b) : (a + b); }

        void rebuild() {
            no = 0;
            totD = 0;
            B.clear(), Bo.clear(), A.clear(), Ao.clear();
            F0R (i, SZ) {
                if (hA[i] && hB[i]) {
                    A.eb(hA[i], 1);
                    B.eb(hB[i], 1);
                    totD += hA[i] + hB[i];
                }
                else if (hA[i]) Ao.eb(hA[i], 1);
                else if (hB[i]) Bo.eb(hB[i], 1);
                else no++;
            }
            sort(all(A)); sort(all(Ao)); sort(all(B)); sort(all(Bo));
        }

        void squeeze(vpii& C, vpii& Co, vpii& O, vpii& Oo, int y) {
            int po = no; no = 0;
            while (sz(Co) && Co.back().f >= y) {
                po += Co.back().s;
                Co.pop_back();
            }
            if (po) Co.eb(y, po);

            int pC = 0;
            while (sz(C) && C.back().f >= y) {
                pC += C.back().s;
                totD -= ll(C.back().f - y) * C.back().s;
                C.pop_back();
            }

            int oS = sz(O);
            trav (p, Oo) {
                pC += p.s;
                totD += ll(p.f + y) * p.s;
                O.pb(p);
            }
            Oo.clear();

            if (pC) C.eb(y, pC);
            sort(O.begin() + oS, O.end());
            inplace_merge(O.begin(), O.begin() + oS, O.end());
        }

        void put_snake(const int sl, const int sr, const int sy) {
            if (sr <= bl || br <= sl) return;
            if (sl <= bl && br <= sr) {
                if (sy < 0) put(cB, -sy), squeeze(B, Bo, A, Ao, -sy);
                else put(cA, sy), squeeze(A, Ao, B, Bo, sy);
                return;
            }

            FOR (i, max(0, sl - bl), min(SZ, sr - bl)) {
                if (sy < 0) put(hB[i], -sy);
                else put(hA[i], sy);
            }
            F0R (i, SZ) put(hA[i], cA), put(hB[i], cB);
            rebuild();
        }

        ll get_danger(int ql, int qr) {
            if (qr <= bl || br <= ql) return 0;
            if (ql <= bl && br <= qr) return totD;
            ll res = 0;
            FOR (i, max(0, ql - bl), min(SZ, qr - bl)) {
                put(hA[i], cA), put(hB[i], cB);
                if (hA[i] && hB[i]) res += hA[i] + hB[i];
            }
            return res;
        }
    };

    const int MAXV = 1e5;
    const int BSZ = sqrt(MAXV);
    vector<block> blocks;
    for (int l = 0; l < MAXV; l += BSZ) {
        blocks.pb(block(l, l + BSZ));
    }

    int t, l, r, k;
    int Q; re(Q); F0R (q, Q) {
        re(t, l, r); --l, --r;
        if (t == 1) {
            re(k);
            trav (b, blocks) b.put_snake(l, r, k);
        } else {
            ll ans = 0;
            trav (b, blocks) ans += b.get_danger(l, r);
            ps(ans);
        }
    }

    return 0;
}