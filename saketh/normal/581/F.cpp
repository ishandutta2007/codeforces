#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5050;
const int INF = 0x7f7f7f7f;

int N;
vector<int> adj[MAXN];

int lf[MAXN];
int dp[MAXN][2][MAXN];
int dp2[MAXN][2][MAXN];

void solve(int loc, int par) {
    if (adj[loc].size() == 1) {
        lf[loc] = 1;
        dp[loc][0][0] = 0;
        dp[loc][1][1] = 0;
        return;
    }

    for (int nbr : adj[loc]) 
        if (nbr != par) solve(nbr, loc);

    memset(dp2[0], 0x7f, sizeof(dp2[0]));

    dp2[0][0][0] = 0;
    dp2[0][1][0] = 0;
    int x = 0;

    for (int nbr : adj[loc]) 
        if (nbr != par) {
            memset(dp2[x+1], 0x7f, sizeof(dp2[x+1]));

            for (int rc = 0; rc < 2; rc++) {
                for (int pv = 0; pv <= lf[loc]; pv++) {
                    if (dp2[x][rc][pv] == INF) continue;

                    for (int cc = 0; cc < 2; cc++) {
                        for (int gh = 0; gh <= lf[nbr]; gh++) {
                            if (dp[nbr][cc][gh] == INF) continue;

                            dp2[x+1][rc][pv+gh] = min(dp2[x+1][rc][pv+gh],
                                dp2[x][rc][pv] + dp[nbr][cc][gh] + int(rc != cc));
                        }
                    }
                }
            }

            x++;
            lf[loc] += lf[nbr];
        }

    for (int wl = 0; wl <= lf[loc]; wl++) {
        dp[loc][0][wl] = dp2[x][0][wl];
        dp[loc][1][wl] = dp2[x][1][wl];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, 0x7f, sizeof(dp));

    if (N == 2) { cout << 1 << "\n"; return 0; }

    int root = 0;
    while(adj[root].size() == 1) root++;
    solve(root, root);

    int L = lf[root];
    cout << min(dp[root][0][L/2], dp[root][1][L/2]) << "\n";
}