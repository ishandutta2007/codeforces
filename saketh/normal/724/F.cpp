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

int MOD;
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, D;
    cin >> N >> D >> MOD;

    if (N <= 2) {
        // there is only one tree, and it has no internal vertices
        cout << 1 << "\n";
        return 0;
    }

    vi inv(N + 1);
    inv[1] = 1;
    for (int i = 2; i <= N; i++)
        inv[i] = prod(inv[MOD % i], sum(MOD, -(MOD/i)));

    vector<vvi> dp(N + 1, vvi(D + 1, vi(N + 1)));
    vvi picks(N + 1, vi(N + 1));

    for (int s = 1; s <= N; s++) {
        if (s == 1) {
            for (int m = 0; m <= N; m++)
                dp[1][0][m] = 1;
        }
        else for (int d = 1; d <= D; d++) {
            for (int m = 1; m <= N; m++) {
                dp[s][d][m] = dp[s][d][m-1];
                for (int t = 1; t * m + 1 <= s && t <= d; t++) {
                    dp[s][d][m] = sum(dp[s][d][m],
                            prod(dp[s-t*m][d-t][m-1], picks[m][t]));
                }
            }
        }

        for (int t = 0; t * s <= N; t++) {
            picks[s][t] = 1;
            int numer = sum(dp[s][(s == 1) ? 0 : (D-1)][s-1], t - 1);
            for (int v = 0; v < t; v++)
                picks[s][t] = prod(picks[s][t], numer - v);
            for (int v = 1; v <= t; v++)
                picks[s][t] = prod(picks[s][t], inv[v]);
        }
    }

    int ans = dp[N][D][(N-1)/2];
    if (N % 2 == 0) {
        int numer = dp[N/2][D-1][N/2-1] + 2 - 1;
        int nc2 = prod(prod(numer, sum(numer, MOD - 1)), inv[2]);
        ans = sum(ans, nc2);
    }

    cout << ans << endl;
    return 0;
}