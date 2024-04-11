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

void flood(int loc, vvi &adj, vb &seen, vi &comp) {
    if (seen[loc]) return;
    seen[loc] = true;
    comp.push_back(loc);

    for (int nbr : adj[loc])
        flood(nbr, adj, seen, comp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M, W;
    cin >> N >> M >> W;

    vi weight(N);
    for (int i = 0; i < N; i++)
        cin >> weight[i];

    vi beauty(N);
    for (int i = 0; i < N; i++)
        cin >> beauty[i];

    vvi adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vvi comps;
    vb seen(N);

    for (int i = 0; i < N; i++) {
        if (seen[i]) continue;
        comps.push_back(vi(0));
        flood(i, adj, seen, comps.back());
    }

    vi dp(W + 1);

    for (auto &v : comps) {
        vi upd = dp;

        int sum_weight = 0;
        int sum_beauty = 0;

        for (int h : v) {
            for (int i = weight[h]; i <= W; i++) {
                upd[i] = max(upd[i], dp[i - weight[h]] + beauty[h]);
            }

            sum_weight += weight[h];
            sum_beauty += beauty[h];
        }

        for (int i = sum_weight; i <= W; i++)
            upd[i] = max(upd[i], dp[i - sum_weight] + sum_beauty);

        swap(dp, upd);
    }

    int ans = 0;
    for (int v : dp)
        ans = max(ans, v);
    cout << ans << endl;

    return 0;
}