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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<pair<int, int>>> adj(N);

    for (int i = 0; i < M; i++) {
        int x, y, c;
        cin >> x >> y >> c;

        adj[x-1].emplace_back(y-1, c);
        adj[y-1].emplace_back(x-1, c);
    }

    vector<bool> store(N);

    for (int i = 0; i < K; i++) {
        int loc;
        cin >> loc;
        store[loc-1] = true;
    }

    int ans = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (store[i]) {
            for (auto e : adj[i]) {
                if (!store[e.first])
                    ans = min(ans, e.second);
            }
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << "\n";
    return 0;
}