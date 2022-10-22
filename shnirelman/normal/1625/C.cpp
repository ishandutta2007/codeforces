#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 513;
const int LOGN = 10;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

int a[N], d[N];
int dp[N][N];

void solve() {
    int n, l, k;
    cin >> n >> l >> k;

    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    d[n] = l;
    a[n] = 0;
    n++;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int p = 0; p < i; p++) {
                if(i - p - 1 <= j && dp[p][j - i + p + 1] < INF) {
                    dp[i][j] = min(dp[i][j], dp[p][j - i + p + 1] + a[p] * (d[i] - d[p]));
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i <= k; i++)
        ans = min(ans, dp[n - 1][i]);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}