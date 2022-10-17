#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int N, M;
    cin >> N >> M;

    vvi adj(N);
    for (int e = 0, u, v; e < M; e++) {
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vi color(N, -1);
    color[0] = 0; array<int, 2> ct = { 1, 0 };
    for (queue<int> bfs({0}); !bfs.empty(); bfs.pop()) {
        for (int nbr : adj[bfs.front()]) if (color[nbr] == -1) {
            color[nbr] = !color[bfs.front()];
            ++ct[color[nbr]];
            bfs.push(nbr);
        }
    }

    int use = ct[0] > ct[1];
    cout << ct[use] << "\n";
    for (int i = 0; i < N; i++)
        if (color[i] == use)
            cout << i + 1 << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}