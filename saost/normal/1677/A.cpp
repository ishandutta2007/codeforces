#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 5005;
int t, n, m, k, res;
int a[N], dp[N][N], dp2[N][N];

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

void Process() {
    FOR(i, 1, n) {
        FOR(j, 1, n) dp[i][j] = dp[i - 1][j];
        FOR(j, a[i], n) ++dp[i][j];
    }
    FOR(i, 1, n) dp2[n + 1][i] = 0;
    FORD(i, n, 1) {
        FOR(j, 1, n) dp2[i][j] = dp2[i + 1][j];
        FOR(j, a[i], n) ++dp2[i][j];
    }
    long long res = 0;
    FOR(i, 1, n) FOR(j, i + 1, n) {
        res += 1LL * dp[i - 1][a[j]] * dp2[j + 1][a[i]];
    }
    cout << res << '\n';
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