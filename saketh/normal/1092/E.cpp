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

    int N, M;
    cin >> N >> M;

    vvi adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    auto bfs = [&N, &adj](int root) {
        vi dist(N, -1);
        dist[root] = 0;
        for (queue<int> q({ root }); !q.empty(); q.pop()) {
            for (int nbr : adj[q.front()]) if (dist[nbr] == -1) {
                dist[nbr] = dist[q.front()] + 1;
                q.push(nbr);
            }
        }
        return dist;
    };

    int ans = 0;
    vb visit(N, false);
    vector<pair<int, int>> cp;

    for (int i = 0; i < N; i++) {
        if (visit[i]) continue;
        vi distI = bfs(i);

        int cent = -1, dist = INT_MAX;
        for (int v = 0; v < N; v++) if (distI[v] != -1) {
            visit[v] = true;
            int maxd = 0;
            for (int d : bfs(v)) maxd = max(maxd, d);
            ans = max(ans, maxd);
            if (maxd < dist) {
                dist = maxd;
                cent = v;
            }
        }

        cp.emplace_back(dist, cent);
    }

    sort(all(cp));
    reverse(all(cp));

    if (cp.size() >= 2) {
        ans = max(ans, cp[0].first + 1 + cp[1].first);
    }
    if (cp.size() >= 3) {
        ans = max(ans, cp[1].first + 1 + cp[2].first + 1);
    }

    cout << ans << "\n";
    for (int i = 1; i < cp.size(); i++) {
        cout << cp[0].second + 1 << " " << cp[i].second + 1 << "\n";
    }

    return 0;
}