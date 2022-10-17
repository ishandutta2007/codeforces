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

    int N, M, S, K;
    cin >> N >> M >> S >> K;

    vi type(N);
    for (int i = 0; i < N; i++) {
        cin >> type[i];
        --type[i];
    }

    vvi adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vvi opt(N);
    for (int tp = 0; tp < S; tp++) {
        vi dist(N, -1);

        queue<pair<int, int>> q;
        for (int i = 0; i < N; i++) {
            if (type[i] == tp) {
                q.push({ i, 0 });
                dist[i] = 0;
            }
        }

        while (!q.empty()) {
            int loc = q.front().first;
            int tot = q.front().second;
            q.pop();
            for (int nbr : adj[loc]) {
                if (dist[nbr] != -1)
                    continue;
                dist[nbr] = tot + 1;
                q.push({ nbr, tot + 1 });
            }
        }

        WATCH(tp);
        WATCHC(dist);
        for (int i = 0; i < N; i++) {
            opt[i].push_back(dist[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        sort(all(opt[i]));
        int ans = 0;
        for (int j = 0; j < K; j++) {
            ans += opt[i][j];
        }
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}