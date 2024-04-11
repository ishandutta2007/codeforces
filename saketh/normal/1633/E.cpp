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

// union_find {{{
#include <vector>
#include <numeric>
#include <iostream>

struct union_find {
    struct node {
        int parent, rank, size;
        node (int id = 0) : parent(id), rank(0), size(1) {}
    };

    mutable std::vector<node> data;

    union_find(int SZ = 0) : data(SZ) {
        iota(data.begin(), data.end(), 0);
    }

    void reset() {
        iota(data.begin(), data.end(), 0);
    }

    // Returns the root of the component containing i
    int find(int i) const {
        if (i != data[i].parent)
            data[i].parent = find(data[i].parent);
        return data[i].parent;
    }

    bool is_root(int i) const {
        return i == find(i);
    }

    node& root_node(int i) const {
        return data[find(i)];
    }

    /* Unites the components containing a and b if they are different.
     * Returns a boolean indicating whether a and b were in different components.
     */
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;

        if (data[a].rank < data[b].rank)
            std::swap(a, b);

        data[b].parent = a;
        data[a].size += data[b].size;
        if (data[a].rank == data[b].rank)
            data[a].rank++;

        return true;
    }

    friend void pr(const union_find& u) {
        std::cout << "{";
        bool first = 1;
        for (int i = 0; i < int(u.data.size()); i++) {
            if (u.is_root(i)) {
                if (!first) std::cout << ", ";
                else first = 0;
                std::cout << "[ " << i << " | rank=" << u.data[i].rank
                    << " size=" << u.data[i].size << " ]";
            }
        }
        std::cout << "}";
    }
};
// }}}

int main() {
    setIO();

    int N, M; re(N, M);

    vi u(M), v(M), ew(M);

    F0R (i, M) {
        re(u[i], v[i], ew[i]);
        --u[i];
        --v[i];
    }

    vi ws;
    vector<int64_t> A;
    vector<int64_t> B;
    {
        {
            F0R (i, M) {
                ws.pb(ew[i] - 1);
                ws.pb(ew[i]);
                ws.pb(ew[i] + 1);

                FOR (j, i + 1, M) {
                    int x = ew[i];
                    int y = ew[j];

                    if (x > y) {
                        swap(x, y);
                    }

                    assert(x <= y);
                    ws.pb(x + (y - x) / 2);
                    ws.pb(ws.back() + 1);
                    ws.pb(ws.back() - 2);
                }
            }

            dedup(ws);
        }

        {
            union_find uf(N);

            vector<int> order(M);
            iota(all(order), 0);

            for (int W : ws) {
                sort(all(order), [&ew, &W](int i, int j) {
                    int wi = abs(ew[i] - W);
                    int wj = abs(ew[j] - W);
                    return wi != wj ? wi < wj : ew[i] < ew[j];
                });

                int64_t m = 0;
                int64_t b = 0;

                for (int ei : order) {
                    if (uf.unite(u[ei], v[ei])) {
                        if (W <= ew[ei]) { // ew[ei] - W
                            m -= 1;
                            b += ew[ei];
                        } else { // W - ew[ei]
                            m += 1;
                            b -= ew[ei];
                        }
                    }
                }

                A.pb(m);
                B.pb(b);

                uf.reset();
            }
        }
    }

    ws.back() = 1e9;

    int64_t ans = 0;

    {
        int P, K, a, b, c;
        re(P, K, a, b, c);

        vi x(P);
        re(x);

        x.resz(K);
        FOR (i, P, K) {
            x[i] = int((int64_t(x[i - 1]) * a + b) % c);
        }

        for (int w : x) {
            int i = lb(all(ws), w) - ws.begin();
            int64_t res = A[i] * w + B[i];
            ans ^= res;
        }
    }

    ps(ans);

    return 0;
}