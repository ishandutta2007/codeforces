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

    const int MAXV = 2e5 + 1;
    vi sieve(MAXV);

    for (int p = 2; p < MAXV; p++) {
        if (sieve[p]) continue;
        for (int q = p; q < MAXV; q += p)
            sieve[q] = p;
    }

    int N;
    cin >> N;

    vi a(N);
    vvi app(MAXV);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        for (int tmp = a[i]; tmp > 1; ) {
            int p = sieve[tmp];
            app[p].push_back(i);
            while (tmp % p == 0)
                tmp /= p;
        }
    }

    vvi adj(N);
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    auto find = [&](vi& vis, int r, int p) {
        pair<int, int> res = { 0, r };
        vis[r] = p;
        for (queue<pair<int, int>> bfs({ res });
                !bfs.empty(); bfs.pop()) {
            auto [dist, loc] = bfs.front();
            if (dist > res.first) res = bfs.front();
            for (int nbr : adj[loc]) {
                if (vis[nbr] == p) continue;
                if (a[nbr] % p) continue;
                vis[nbr] = p;
                bfs.push({ dist + 1, nbr });
            }
        }
        return res;
    };

    int ans = 0;
    vi vis1(N), vis2(N);
    for (int p = 2; p < MAXV; p++) {
        for (int v : app[p]) {
            if (vis1[v]) continue;
            int q = find(vis1, v, p).second;
            int d = find(vis2, q, p).first;
            ans = max(ans, d + 1);
        }
    }
    cout << ans << endl;

    return 0;
}