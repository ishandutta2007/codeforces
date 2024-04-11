#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vvi adj(N);
    for (int e = 0; e < M; e++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vvi dist(N, vi(N, INT_MAX));
    for (int src = 0; src < N; src++) {
        dist[src][src] = 0;

        queue<int> bfs({src});
        while (!bfs.empty()) {
            int loc = bfs.front();
            bfs.pop();

            for (int nbr : adj[loc]) {
                if (dist[src][nbr] == INT_MAX) {
                    dist[src][nbr] = dist[src][loc] + 1;
                    bfs.push(nbr);
                }
            }
        }
        WATCHC(dist[src]);
    }

    int W;
    cin >> W;
    vector<array<int, 3>> stores(W);

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < 3; j++)
            cin >> stores[i][j];
        stores[i][0]--;
    }

    sort(all(stores), [&](array<int, 3> &a1, array<int, 3> &a2) {
        return make_pair(a1[2], a1[1]) < make_pair(a2[2], a2[1]);
    });

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        WATCH(q);
        int shov, loc, cost;
        cin >> loc >> shov >> cost;
        loc--;

        int ans = -1;
        int lo = 0, hi = N - 1;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;

            vector<pair<int, int>> avail;
            for (int st = 0; st < W; st++)
                if (dist[loc][stores[st][0]] <= mi)
                    avail.emplace_back(stores[st][2], stores[st][1]);

            WATCH(mi);

            int bought = 0, money = cost;
            for (auto p : avail) {
                int buy = min(p.second, money / p.first);
                money -= buy * p.first;
                bought += buy;
            }

            if (bought >= shov) {
                ans = mi;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }

        cout << ans << "\n";
    }

    return 0;
}