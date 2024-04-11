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
    friend bool operator >(const tp& a, const tp& b) { return a.elts > b.elts; }
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
        o << "[";
        for (int i = 0; i < N; i++) { if (i) o << ", "; o << a[i]; }
        return o << "]";
    }
    template<typename T> ostream& operator<<(ostream& o,
            const vector<T>& v) {
        o << "[";
        for (int i = 0; i < sz(v); i++) { if (i) o << ", "; o << v[i]; }
        return o << "]";
    }
}
using namespace output;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vvi adj(N);
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    tp<int, int> ld = { 0, -1 }, sd = { 0, -1 };
    for (int i = 0; i < N; i++) {
        ckmax(sd, { sz(adj[i]), i });
        if (sd > ld) swap(sd, ld);
    }

    if (sd[_0] > 2) { cout << "No\n"; return 0; }

    cout << "Yes\n" << ld[_0] << "\n";

    for (int nbr : adj[ld[_1]]) {
        int loc = nbr, bef = ld[_1];
        while (sz(adj[loc]) > 1) {
            int nxt = adj[loc][0] + adj[loc][1] - bef;
            bef = loc;
            loc = nxt;
        }
        cout << ld[_1] + 1 << " " << loc + 1 << "\n";
    }

    return 0;
}