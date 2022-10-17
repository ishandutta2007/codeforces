#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll INF = 1e17;

ll sp(int N, vvi &adj, vi &u, vi &v, vll &w, int S, int T) {
    vll dist(N, INF);
    dist[S] = 0;

    priority_queue<pair<ll, int>> pq;
    pq.push({ 0, S });

    while (!pq.empty()) {
        ll cost = -pq.top().first;
        int loc = pq.top().second;
        pq.pop();

        for (int e : adj[loc]) {
            int nbr = u[e] + v[e] - loc;
            ll path = cost + w[e];

            if (path < dist[nbr]) {
                dist[nbr] = path;
                pq.push({-path, nbr});
            }
        }
    }

    return dist[T];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M, L, S, T;
    cin >> N >> M >> L >> S >> T;

    vi unw;
    vvi adj(N);
    vi u(M), v(M);
    vll w(M);

    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i] >> w[i];
        if (!w[i]) unw.push_back(i);

        adj[u[i]].push_back(i);
        adj[v[i]].push_back(i);
    }

    int lo = 0, hi = unw.size();
    int ans = hi + 1;
    ll diff = 0;

    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        for (int i = 0; i < unw.size(); i++) {
            if (i < mi) w[unw[i]] = 1;
            else w[unw[i]] = INF;
        }

        ll res = sp(N, adj, u, v, w, S, T);

        if (res <= L) {
            ans = mi;
            hi = mi - 1;
            diff = L - res;
        } else {
            lo = mi + 1;
        }
    }

    if (ans > unw.size() || (ans == 0 && diff != 0)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int k = 0; k < unw.size(); k++) {
            if (k < ans - 1) w[unw[k]] = 1;
            else if (k == (ans - 1)) w[unw[k]] = 1 + diff;
            else w[unw[k]] = INF;
        }

        for (int e = 0; e < M; e++)
            cout << u[e] << " " << v[e] << " " << w[e] << "\n";
    }

    return 0;
}