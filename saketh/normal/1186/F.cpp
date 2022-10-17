#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define F0R(i, a)       for (int i = 0; i < (a); i++)
#define FORd(i, a, b)   for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a)      for (int i = (a)-1; i >= 0; i--)
#define trav(a, x)      for (auto& a : x)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <size_t I> struct index_t {};
#define _i(i, v) const index_t<i> v{}
_i(0, _0); _i(1, _1); _i(2, _2); _i(3, _3); _i(4, _4);
template<typename... T> struct tp {
    std::tuple<T...> elts;
    tp() {}
    tp(std::tuple<T...> _t) : elts(_t) {}
    template<typename T1, typename... Ts> tp(T1 t1, Ts... ts) : elts(t1, ts...) {}
    template <size_t I> decltype(auto) operator[](index_t<I>) {
        return get<I>(this->elts);
    }
    template <size_t I> decltype(auto) operator[](index_t<I>) const {
        return get<I>(this->elts);
    }
    friend bool operator <(const tp& a, const tp& b) { return a.elts < b.elts; }
};

namespace __input {
    template<typename T, size_t... I> void read_tuple(istream& i, T& t, index_sequence<I...>) {
        ((i >> get<I>(t)), ...);
    }
    template<typename... T> istream& operator>>(istream& i, tp<T...>& t) {
        read_tuple(i, t.elts, index_sequence_for<T...>{}); return i;
    }
    template<typename T1, typename T2> istream& operator >>(istream& i, pair<T1, T2>& p) {
        i >> p.first >> p.second; return i;
    }
    template<typename T, size_t N> istream& operator >>(istream& i, array<T, N>& v) {
        for (auto& e : v) { i >> e; } return i;
    }
    template<typename T> istream& operator >>(istream& i, vector<T>& v) {
        for (auto& e : v) { i >> e; } return i;
    }
}
using namespace __input;

namespace __output {
    template<typename T, size_t... I> void write_tuple(ostream& o, const T& t, index_sequence<I...>) {
        o << "("; ((o << (I ? ", " : "") << get<I>(t)), ...); o << ")";
    }
    template<typename... T> ostream& operator<<(ostream& o, const tp<T...>& t) {
        write_tuple(o, t.elts, index_sequence_for<T...>{}); return o;
    }
    template<typename T1, typename T2> ostream& operator<<(ostream& o, const pair<T1, T2>& t) {
        return o << "(" << t.first << ", " << t.second << ")";
    }
    template<typename T, size_t N> ostream& operator<<(ostream& o, const array<T, N>& a) {
        o << "["; for (int i = 0; i < N; i++) { if (i) o << ", "; o << a[i]; } return o << "]";
    }
    template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
        o << "["; for (int i = 0; i < sz(v); i++) { if (i) o << ", "; o << v[i]; } return o << "]";
    }
}
using namespace __output;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vi u(M), v(M);
    vvi adj(N);

    F0R (e, M) {
        cin >> u[e] >> v[e];
        --u[e], --v[e];
        adj[u[e]].pb(e);
        adj[v[e]].pb(e);
    }

    vb alive(M, true);

    vi remain(N), used(N);
    F0R (i, N) remain[i] = sz(adj[i]);

    vector<pair<int, int>> ans;

    F0R (i, N) {
        while (remain[i]) {
            vi path;
            for (int rep = 0; rep < 2; rep++) {
                int loc = i;
                while (true) {
                    bool adv = false;
                    while (used[loc] < sz(adj[loc])) {
                        int e = adj[loc][used[loc]++];
                        if (alive[e]) {
                            path.pb(e);

                            alive[e] = false;
                            remain[u[e]]--;
                            remain[v[e]]--;

                            loc = u[e] + v[e] - loc;
                            adv = true;
                            break;
                        }
                    }
                    if (!adv) break;
                }
                reverse(all(path));
            }

            for (int j = 0; j < sz(path); j += 2)
                ans.emplace_back(u[path[j]], v[path[j]]);
            if (!path.empty() && sz(path) % 2 == 0) {
                ans.emplace_back(u[path[sz(path) - 1]], v[path[sz(path) - 1]]);
            }
        }
    };

    vi deg(N);

    cout << sz(ans) << "\n";
    for (auto p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
        deg[p.first]++;
        deg[p.second]++;
    }
    cout << flush;

    assert(sz(ans) <= (N + M + 1) / 2);
    F0R (i, N) {
        assert(deg[i] >= (sz(adj[i]) + 1) / 2);
    }

    return 0;
}