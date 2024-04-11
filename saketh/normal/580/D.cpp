#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 19;
const int MASK = 1 << MAXN;

int N, M, K;
ll val[MAXN];
ll rl[MAXN][MAXN];
ll dp[MASK][MAXN];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < K; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        rl[u-1][v-1] = c;
    }

    ll best = 0;

    for (int m = 0; m < (1 << N); m++) {
        if (m == 0) {
            for (int fst = 0; fst < N; fst++) {
                dp[ (1 << fst) ][fst] = val[fst];
            }
            continue;
        }

        int B = __builtin_popcount(m);
        if(B > M) continue;

        for (int lst = 0; lst < N; lst++) {
            if (!((m >> lst) & 1)) continue;

            if (B == M) {
                best = max(best, dp[m][lst]);
                continue;
            }

            for (int use = 0; use < N; use++) {
                if((m >> use) & 1) continue;

                int succ = m ^ (1 << use);
                dp[succ][use] = max(dp[succ][use], dp[m][lst] + val[use] + rl[lst][use]);
            }
        }
    }

    cout << best << endl;
}