#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
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

    const int LIM = 600;

    int N, M, K;
    cin >> N >> M >> K;

    vi x(M), y(M);
    vvi g(N);

    for (int i = 0; i < M; i++) {
        cin >> x[i] >> y[i];
        g[--x[i]].push_back(i);
        g[--y[i]].push_back(i);
    }

    vi deg(N);
    for (int i = 0; i < N; i++)
        deg[i] = g[i].size();

    vb del(N, false);
    vb live(M, true);

    int alive = N;
    vi ans(M);

    auto bfs = [&](int v) {
        if (deg[v] >= K || del[v]) return;
        queue<int> rem;
        rem.push(v);
        del[v] = true;
        alive--;
        while (!rem.empty()) {
            int nxt = rem.front();
            rem.pop();
            for (int e : g[nxt]) {
                if (!live[e]) continue;
                live[e] = false;
                int nbr = x[e] + y[e] - nxt;
                deg[nbr]--;
                if (!del[nbr] && deg[nbr] < K) {
                    del[nbr] = true;
                    alive--;
                    rem.push(nbr);
                }
            }
        }
    };

    for (int i = 0; i < N; i++) {
        bfs(i);
    }

    for (int i = M - 1; i >= 0; i--) {
        ans[i] = alive;
        if (live[i]) {
            live[i] = false;
            deg[x[i]]--;
            deg[y[i]]--;
            bfs(x[i]);
            bfs(y[i]);
        }
    }

    for (int i = 0; i < M; i++)
        cout << ans[i] << "\n";

    return 0;
}