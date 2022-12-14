#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 105, INF = 0x3c3c3c3c3c;
int t, n, m;
int a[N], b[N], f[N], ok[N * N * 2];
long long dp[N * N * 2];

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
}

void Process() {
    long long res = 0, sum = 0, r2 = INF;
    FOR(i, 1, n) res += (a[i] * a[i] + b[i] * b[i]) * (n - 1);
    fill(ok + 1, ok + N * N, 0);
    dp[0] = 0;
    ok[0] = 1;
    FOR(i, 1, n) {
        int tmp = sum + a[i] + b[i];
        FORD(j, tmp, 0) {
            dp[j] = INF, ok[j] = 0;
            int k1 = j - a[i], k2 = j - b[i];
            if (k1 >= 0 && ok[k1])
                dp[j] = dp[k1] + a[i] * k1 + b[i] * (sum - k1), ok[j] = 1;
            if (k2 >= 0 && ok[k2])
            dp[j] = min(dp[j], dp[k2] + b[i] * k2 + a[i] * (sum - k2)), ok[j] = 1;
        }
        sum = tmp;
    }
    FORD(i, sum, 0) if (ok[i])
        r2 = min(r2, dp[i]);
    if (r2 == INF) r2 = 0;
    cout << res + r2 * 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}