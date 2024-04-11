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

const ll INF = LLONG_MAX / 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vector<array<ll, 2>> cost(N, { 0, 0 });
    for (int i = 0; i < N; i++)
        cin >> cost[i][1];

    vector<array<string, 2>> vals(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i][0];
        vals[i][1] = vals[i][0];
        reverse(vals[i][1].begin(), vals[i][1].end());
    }

    vector<array<ll, 2>> dp(N, { INF, INF });
    dp[0] = cost[0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (vals[i][j] >= vals[i-1][k])
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + cost[i][j]);
            }
        }
    }

    ll ans = min(dp.back()[0], dp.back()[1]);
    if (ans == INF)
        cout << -1 << endl;
    else 
        cout << ans << endl;

    return 0;
}