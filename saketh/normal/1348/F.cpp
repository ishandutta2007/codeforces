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

// tarjan {{{
// Labels strongly connected components in reverse topological order.
// That means for any edge u-->v comp[u] >= comp[v].
tuple<int, vi> strongly_connected_components(const vvi& graph) {
    const int N = graph.size();
    int C = 0, V = 0, top = 0;
    vi comp(N, -1), inx(N, -1), stack(N + 1, -1);

    auto tarjan = [&](auto&& self, int loc) -> int {
        stack[top++] = loc;
        int low = inx[loc] = V++;
        for (int nbr : graph[loc]) {
            if (inx[nbr] == -1) low = min(low, self(self, nbr));
            else if (comp[nbr] == -1) low = min(low, inx[nbr]);
        }
        if (low == inx[loc]) {
            while (stack[top] != loc)
                comp[stack[--top]] = C;
            C++;
        }
        return low;
    };

    for (int i = 0; i < N; i++) {
        if (inx[i] == -1)
            tarjan(tarjan, i);
    }
    return { C, comp };
}
// }}}

int main() {
    setIO();

    int N; re(N);

    vpii ranges(N);
    F0R (i, N) {
        int a, b; re(a, b);
        ranges[i] = { a-1, b };
    }

    vi matching(N);
    {
        // sort ranges by their starting point
        vi order(N);
        F0R (i, N) order[i] = i;
        sort_by(order, ranges[a].f < ranges[b].f);

        // match to soonest-ending
        auto cmp = [&](int a, int b) { return ranges[a].s > ranges[b].s; };
        priority_queue<int, vi, decltype(cmp)> pq(cmp);

        int j = 0;
        F0R (i, N) {
            while (j < N && ranges[order[j]].f <= i) {
                pq.push(order[j]);
                j++;
            }

            matching[pq.top()] = i;
            pq.pop();
        }
    }

    int G = 3 * N;
    vvi graph(G);

    FOR (node, 2, 2 * N)
        graph[node / 2].pb(node);

    auto add_range = [&](int position, int L, int R) {
        for (int i = N + L, j = N + R; i < j; i /= 2, j /= 2) {
            if (i&1) graph[2 * N + position].pb(i++);
            if (j&1) graph[2 * N + position].pb(--j);
        }
    };

    F0R (position, N) { // left-to-right edges
        int person = matching[position];
        graph[N + person].pb(2 * N + position);

        add_range(position, ranges[position].f, person);
        add_range(position, person + 1, ranges[position].s);
    }

    auto [COMP_CT, which_comp] = strongly_connected_components(graph);

    if (COMP_CT == G) {
        ps("YES");
        trav (e, matching) ++e;
        pc(matching);
    } else {
        ps("NO");

        vi comp_sz(COMP_CT);
        F0R (i, G) comp_sz[which_comp[i]]++;

        // find any cycle and use it to make a second matching
        int pos = 2 * N;
        while (pos < G && comp_sz[which_comp[pos]] == 1)
            pos++;
        assert(pos < G);

        vi pred(G, -1);
        queue<int> bfs;

        trav (node, graph[pos]) {
            pred[node] = pos;
            bfs.push(node);
        }

        while (!bfs.empty()) {
            int loc = bfs.front();
            bfs.pop();

            trav (nbr, graph[loc]) {
                if (pred[nbr] == -1) {
                    pred[nbr] = loc;
                    bfs.push(nbr);
                }
            }
        }

        assert(pred[pos] != -1);

        vi new_matching = matching;

        vi cyc = {pos};
        for (int loc = pred[pos]; loc != pos; loc = pred[loc]) {
            if (loc >= N)
                cyc.pb(loc);
        }

        for (int i = 0; i < sz(cyc); i += 2) {
            assert(matching[cyc[i] - 2 * N] == cyc[i + 1] - N);
            int ii = i - 1;
            if (ii < 0) ii += sz(cyc);
            new_matching[cyc[i] - 2 * N] = cyc[ii] - N;
        }

        trav (e, matching) ++e;
        pc(matching);
        trav (e, new_matching) ++e;
        pc(new_matching);
    }

    return 0;
}