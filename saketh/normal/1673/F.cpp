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

using i64 = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;
using vi64 = vector<i64>;
using vvi64 = vector<vi64>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using vpii = vector<pii>;

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
}
using namespace __algorithm;

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

bool LOCAL = false;
bool TRACK = false;

int64_t tot = 0;

int join(int a, int b) {
    int c = 0;

    int i = 0;

    while (a || b) {
        c += (a & 1) << i;
        i++;
        a >>= 1;

        c += (b & 1) << i;
        i++;
        b >>= 1;
    }

    if (TRACK) {
        tot += c;
        assert(tot <= 48'000);
    }

    return c;
}

pair<int, int> split(int c) {
    int a = 0, b = 0;

    int i = 0;
    while (c) {
        a += (c&1) << (i/2);
        i++;
        c >>= 1;

        b += (c&1) << (i/2);
        i++;
        c >>= 1;
    }

    return {a, b};
}

int main() {
    setIO();

    F0R (a, 32) {
        F0R (b, 32) {
            int c = join(a, b);
            auto p = split(c);

            assert(p.f == a);
            assert(p.s == b);
        }
    }

    int N, K; re(N, K);

    vi perm = {
        0b0, 0b1, 0b11, 0b10, 0b110, 0b111, 0b101, 0b100,
        0b1100, 0b1101, 0b1111, 0b1110, 0b1010, 0b1011, 0b1001, 0b1000,
        0b11000, 0b11001, 0b11011, 0b11010, 0b11110, 0b11111,
        0b11101, 0b11100, 0b10100, 0b10101, 0b10111, 0b10110, 0b10010, 0b10011, 0b10001, 0b10000
    };

    vi tmp = perm;
    dedup(tmp);
    assert(sz(tmp) == 32);

    vi invp(32);
    F0R (i, 32) {
        invp[perm[i]] = i;
    }

    TRACK = true;
    F0R (i, N) {
        F0R (j, N - 1) {
            if (j) pr(' ');
            pr(join(0, perm[j] ^ perm[j + 1]));
        }
        ps();
    }

    F0R (i, N - 1) {
        F0R (j, N) {
            if (j) pr(' ');
            pr(join(perm[i] ^ perm[i + 1], 0));
        }
        ps();
    }
    TRACK = false;

    cout << flush;

    int r = 0, c = 0;

    vi xs;
    vpii ans;

    if (LOCAL) {

        int tr = 0, tc = 0;

        int dir[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

        F0R (_, K) {
            int tracker = 0;
            F0R (steps, 100) {
                int d = rng() % 4;
                int ntr = tr + dir[d][0];
                int ntc = tc + dir[d][1];

                if (0 <= ntr && ntr < N && 0 <= ntc && ntc < N) {
                    tracker ^= join(perm[ntr] ^ perm[tr], perm[ntc] ^ perm[tc]);
                    tr = ntr;
                    tc = ntc;
                }
            }

            xs.pb(tracker);
            ans.eb(tr, tc);
        }
    }

    F0R (_, K) {
        int x;

        if (LOCAL) {
            x = xs[_];
        } else {
            re(x);
        }

        int xr, xc;
        tie(xr, xc) = split(x);

        r ^= xr;
        c ^= xc;

        ps(invp[r] + 1, invp[c] + 1);
        cout << flush;

        if (LOCAL) {
            assert(invp[r] == ans[_].f);
            assert(invp[c] == ans[_].s);
        }
    }

    return 0;
}