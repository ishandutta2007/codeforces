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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<array<int, 3>>> adj(N);
    for (int e = 0; e < M; e++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].push_back({ v-1, w, e });
        adj[v-1].push_back({ u-1, w, e });
    }

    vll dist(N, LLONG_MAX);
    vi used(N, -1);
    vector<array<ll, 2>> eids;

    priority_queue<tuple<ll, int, int>> pq;
    pq.push({ 0, 0, -1 });
    while (!pq.empty()) {
        ll tot = -get<0>(pq.top());
        int loc = get<1>(pq.top());
        int eid = get<2>(pq.top());
        pq.pop();

        if (dist[loc] == LLONG_MAX) {
            dist[loc] = tot;
            used[loc] = eid;
            if (eid != -1)
                eids.push_back({ tot, eid });
        } else continue;

        for (auto [nbr, wt, eid] : adj[loc]) {
            pq.push({ -tot -wt, nbr, eid });
        }
    }

    sort(all(eids));
    K = min(K, int(eids.size()));

    cout << K << "\n";
    for (int i = 0; i < K; i++) {
        cout << eids[i][1] + 1 << " ";
    }
    cout << endl;

    return 0;
}