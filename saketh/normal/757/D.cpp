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

const int MOD = 1e9 + 7;
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int MAXV = 20;

    int N;
    cin >> N;
    string block;
    cin >> block;

    // list of numbers we can make ending at position j
    vector<vector<pair<int, int>>> make(N);

    for (int i = 0; i < N; i++) {
        int val = 0;
        for (int j = i; j < N; j++) {
            val = 2 * val + int(block[j] == '1');
            if (val > 0)
                make[j].emplace_back(val - 1, i);
        }
    }

    vector<bool> good(1 << MAXV);
    int gs = 0;
    for (int m = 0; m < MAXV; m++) {
        gs ^= 1 << m;
        good[gs] = true;
    }

    // dp[i][m] = # of ways to consume characters [0, i) making mask m
    vvi dp(N + 1, vi(1 << MAXV));

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        int fi = i;
        while (fi < N && block[fi] == '0')
            fi++;

        for (int m = 0; m < (1 << MAXV); m++) {
            int &res = dp[i][m];
            if (m == 0) res++; // case where we make nothing before
            if (!res) continue;

            if (good[m])
                ans = sum(ans, res);

            // pick the next block we put down, this will run for at most 5 iterations
            int val = 0;
            for (int j = fi; j < N; j++) {
                val = 2 * val + int(block[j] == '1');
                if (val > MAXV) break;

                int sm = m | (1 << (val-1));
                dp[j+1][sm] = sum(dp[j+1][sm], res);
            }
        }
    }

    cout << ans << endl;
    return 0;
}