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

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

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

namespace output {
    template<typename T, size_t... I> void print_tuple(ostream& o,
            const T& t, index_sequence<I...>) {
        o << "("; ((o << (I ? ", " : "") << get<I>(t)), ...); o << ")";
    }
    template<typename... T> ostream& operator<<(ostream& o,
            const tp<T...>& t) {
        print_tuple(o, t.elts, index_sequence_for<T...>{}); return o;
    }
    template<typename T1, typename T2> ostream& operator<<(ostream& o,
            const pair<T1, T2>& t) {
        return o << "(" << t.first << ", " << t.second << ")";
    }
    template<typename T, size_t N> ostream& operator<<(ostream& o,
            const array<T, N>& a) {
        o << "(";
        for (int i = 0; i < N; i++) { if (i) o << ", "; o << a[i]; }
        return o << ")";
    }
}
using namespace output;

struct union_find {
    vi P, R, S;

    union_find(int N) {
        P.resize(N), R.resize(N, 0), S.resize(N, 1);
        for (int i = 0; i < N; i++)
            P[i] = i;
    }

    int rep(int i) {
        if(P[i] != i) P[i] = rep(P[i]);
        return P[i];
    }

    bool unio(int a, int b) {
        a = rep(a), b = rep(b);
        if(a == b) return false;
        if(R[a] < R[b]) swap(a, b);
        P[b] = a;
        S[a] += S[b];
        if(R[a] == R[b]) R[a]++;
        return true;
    }
};

vb bridges(int N, int M, const auto& edges, const vvi& adj, int S, int T, int avoid = -1) {
    vb res(M);
    vi inx(N, -1);
    auto dfs = [&](auto& self, int loc, int ine) -> tp<bool, int> {
        static int V = 0;
        int low = inx[loc] = V++; bool reachT = loc == T;
        for (int e : adj[loc]) if (e != avoid && e != ine) {
            int nbr = edges[e][_0] + edges[e][_1] - loc;
            if (inx[nbr] == -1) {
                auto nrs = self(self, nbr, e);
                reachT |= nrs[_0];
                ckmin(low, nrs[_1]);
            }
            else ckmin(low, inx[nbr]);
        }
        if (ine != -1) res[ine] = (low == inx[loc]) && reachT;
        return mt(reachT, low);
    };
    dfs(dfs, S, -1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, T;
    cin >> N >> M >> S >> T;
    --S, --T;

    vvi adj(N);
    vector<tp<int, int, int>> edges(M);
    for (int i = 0, u, v, w; i < M; i++) {
        cin >> u >> v >> w;
        edges[i] = { --u, --v, w };
        adj[u].pb(i);
        adj[v].pb(i);
    }

    vi reach(N, -2); reach[S] = -1;
    for (queue<int> bfs({S}); !bfs.empty(); bfs.pop()) {
        int loc = bfs.front();
        for (int e : adj[loc]) {
            int nbr = edges[e][_0] + edges[e][_1] - loc;
            if (reach[nbr] == -2) {
                reach[nbr] = e;
                bfs.push(nbr);
            }
        }
    }
    if (reach[T] == -2) { cout << "0\n0\n"; return 0; }

    vb onpath(M);
    for (int loc = T; loc != S;
            loc = edges[reach[loc]][_0] + edges[reach[loc]][_1] - loc) {
        onpath[reach[loc]] = true;
    }

    tp<int, int, int> ans{ INT_MAX, -1, -1 };

    vb br = bridges(N, M, edges, adj, S, T);
    for (int i = 0; i < M; i++) if (br[i]) ckmin(ans, { edges[i][_2], i, -1 });

    for (int av = 0; av < M; av++) {
        if (!br[av] && onpath[av]) {
            vb br2 = bridges(N, M, edges, adj, S, T, av);
            for (int i = 0; i < M; i++)
                if (i != av && br2[i]) ckmin(ans, { edges[av][_2] + edges[i][_2], av, i });
        }
    }

    if (ans[_0] == INT_MAX) cout << -1 << "\n";
    else if (ans[_2] == -1) cout << ans[_0] << "\n1\n" << ans[_1] + 1 << "\n";
    else {
        if (ans[_1] > ans[_2]) swap(ans[_1], ans[_2]);
        cout << ans[_0] << "\n2\n" << ans[_1] + 1 << " " << ans[_2] + 1 << "\n";
    }

    return 0;
}