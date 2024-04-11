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
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

const int MV = 6;
const int BASE = 4;

int prefix[MV][MV][MV];
int cyc[MV][MV][MV];
vector<array<char, 3>> mex[MV][MV][MV];

char get2(char a, char b) {
    if (a > b) swap(a, b);
    return (a != 0) ? 0 : ((b != 1) ? 1 : 2);
}

char get3(char a, char b, char c) {
    vector<char> v = {a,b,c};
    dedup(v);
    char i = 0;
    while (i < sz(v) && v[i] == i) i++;
    return i;
}

char get(int x, int y, int z, ll v, int lm) {
    int pref = prefix[x][y][z];
    if (v >= pref) v = pref + ((v - pref) % cyc[x][y][z]);
    return mex[x][y][z][v][lm];
}

void solve() {
    int N, X, Y, Z;
    re(N, X, Y, Z);

    vll nums(N); re(nums);

    char univ = 0;
    trav (s, nums) {
        univ ^= get(X, Y, Z, s, 0);
    }

    int ans = 0;

    trav (s, nums) {
        univ ^= get(X, Y, Z, s, 0);

        if (!(univ ^ get(X, Y, Z, max(0ll, s - X), 0))) {
            ans++;
        }
        if (!(univ ^ get(X, Y, Z, max(0ll, s - Y), 1))) {
            ans++;
        }
        if (!(univ ^ get(X, Y, Z, max(0ll, s - Z), 2))) {
            ans++;
        }

        univ ^= get(X, Y, Z, s, 0);
    }

    ps(ans);
}

int main() {
    setIO();

    FOR (x, 1, MV)
        FOR (y, 1, MV)
            FOR (z, 1, MV) {
                auto &table = mex[x][y][z];
                unordered_map<int, int> seen;

                table.pb({0,0,0});
                for (int s = 1; ; s++) {
                    if (s >= MV) {
                        int state = 0;
                        FOR (l, 1, MV)
                            F0R (i, 3)
                                state = BASE * state + table[s - l][i];
                        if (seen.count(state)) {
                            prefix[x][y][z] = seen[state];
                            cyc[x][y][z] = s - seen[state];
                            break;
                        } else seen[state] = s;
                    }

                    array<char, 3> vals = {
                        get3(table[max(0, s - x)][0], table[max(0, s - y)][1], table[max(0, s - z)][2]),
                        get2(table[max(0, s - x)][0],                          table[max(0, s - z)][2]),
                        get2(table[max(0, s - x)][0], table[max(0, s - y)][1]),
                    };
                    table.pb(vals);
                }
            }

    int T; re(T); F0R (t, T) {
        //pr("Case #", t+1, ": ");
        solve();
    }

    return 0;
}