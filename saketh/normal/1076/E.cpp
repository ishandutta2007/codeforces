#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T> struct BIT {
    int S;
    vector<T> v;

    BIT<T>(int _S) {
        S = _S;
        v.resize(S+1);
    }

    void update(int i, T k) {
        for(i++; i <= S; i += i&-i)
            v[i] = v[i] + k;
    }

    T read(int i) {
        T sum = 0;
        for(i++; i; i -= i&-i)
            sum = sum + v[i];
        return sum;
    }

    T read(int l, int r) {
        return read(r) - read(l-1);
    }

    int lower_bound(T sum) {
        T res = 0;
        int inx = 0;
        for (int i = 31 - __builtin_clz(S); i >= 0; i--) {
            if ((inx + (1 << i) <= S) && res + v[inx + (1 << i)] < sum) {
                inx += 1 << i;
                res += v[inx];
            }
        }
        return inx;
    }
};

void go(vvi &adj, BIT<ll> &app, vll &res, auto &ops, int loc, int par, int dep) {
    for (auto [d, x] : ops[loc]) {
        app.update(min(dep + d, int(adj.size()) - 1), x);
    }
    res[loc] = app.read(dep, app.S - 1);
    for (int ch : adj[loc]) {
        if (ch == par) continue;
        go(adj, app, res, ops, ch, loc, dep+1);
    }
    for (auto [d, x] : ops[loc]) {
        app.update(min(dep + d, int(adj.size()) - 1), -x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vvi adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<vector<array<int, 2>>> ops(N);
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int v, d, x;
        cin >> v >> d >> x;
        ops[v-1].push_back({ d, x });
    }

    BIT<ll> bit(N);
    vll res(N);
    go(adj, bit, res, ops, 0, 0, 0);

    for (int i = 0; i < N; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}