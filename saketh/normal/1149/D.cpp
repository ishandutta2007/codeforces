#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B;
    cin >> N >> M >> A >> B;

    const int INF = 1e9;

    vvi floyd(N, vi(N, INF));
    vector<pair<int, int>> slow;

    for (int m = 0; m < M; m++) {
        int u, v, c;
        cin >> u >> v >> c;
        if (c == A) {
            floyd[u-1][v-1] = c;
            floyd[v-1][u-1] = c;
        } else {
            slow.emplace_back(u-1, v-1);
        }
    }

    for (int i = 0; i < N; i++)
        floyd[i][i] = 0;

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }

    int cc = 0;
    vi clump(N, -1);
    vvi celt;

    for (int i = 0; i < N; i++) {
        if (clump[i] != -1) continue;
        celt.push_back({});
        for (int j = 0; j < N; j++) {
            if (floyd[i][j] != INF) {
                clump[j] = cc;
                celt.back().push_back(j);
            }
        }
        cc++;
    }

    vvi adj(N);
    for (auto [u, v] : slow) {
        if (clump[u] != clump[v]) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int bc = 0;
    vi index(cc, -1);
    for (int i = 0; i < cc; i++) {
        if (celt[i].size() >= 4) {
            index[i] = bc++;
        }
    }
    bc = max(bc, 1);

    const int MLIM = 1 << bc;
    vi spc(N * MLIM, INF);

    priority_queue<array<int, 3>> dij;
    dij.push({ 0, 0, 0 });
    while (!dij.empty()) {
        auto pos = dij.top();
        dij.pop();

        int dist = -pos[0];
        int loc = pos[1];
        int visit = pos[2];
        if (index[clump[loc]] != -1) {
            visit |= 1 << index[clump[loc]];
        }

        for (int node : celt[clump[loc]]) {
            spc[node * MLIM + visit] = min(spc[node * MLIM + visit], dist + floyd[loc][node]);

            for (int nbr : adj[node]) {
                int would = visit;
                if (index[clump[nbr]] != -1) {
                    if (would & (1 << index[clump[nbr]])) continue;
                    would |= 1 << index[clump[nbr]];
                }

                if (dist + floyd[loc][node] + B < spc[nbr * MLIM + would]) {
                    spc[nbr * MLIM + would] = dist + floyd[loc][node]+ B;
                    dij.push({ -dist - B - floyd[loc][node], nbr, visit });
                }
            }
        }
    }

    vi ans(N, INF);
    for (int l = 0; l < N; l++) {
        for (int m = 0; m < MLIM; m++) {
            ans[l] = min(ans[l], spc[l * MLIM + m]);
        }
        cout << ans[l] << " ";
    }
    cout << endl;

    return 0;
}