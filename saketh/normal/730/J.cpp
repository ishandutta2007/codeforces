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

    int N;
    cin >> N;

    vi a(N), b(N);
    
    int soda = 0;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        soda += a[i];
    }

    for (int i = 0; i < N; i++)
        cin >> b[i];

    vvi dp(N + 1, vi(100 * N + 1, INT_MIN));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int bp = N - 1; bp >= 0; bp--) {
            for (int tc = 0; tc <= 100 * bp; tc++) {
                if (dp[bp][tc] < 0) continue;

                int nc = tc + b[i];
                int ns = dp[bp][tc] + a[i];
                dp[bp+1][nc] = max(dp[bp+1][nc], ns);
            }
        }
    }

    int mb = N, ms = 0;

    for (int bp = 1; bp <= N; bp++) {
        for (int tc = soda; tc <= 100 * bp; tc++) {
            if (dp[bp][tc] < 0) continue;
            mb = bp;
            ms = max(ms, dp[bp][tc]);
        }

        if (mb == bp) break;
    }

    cout << mb << " " << soda - ms << "\n";
    return 0;
}