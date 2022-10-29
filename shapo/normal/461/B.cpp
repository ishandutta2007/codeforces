#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MD = 1000000007;
const int MAXN = 100500;

int parV[MAXN];
int dp[MAXN][2];
int color[MAXN];
int n;

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
        dp[i][1] = 0;
    }
    for (int i = 1; i < n; ++i) {
        cin >> parV[i];
        //dp[parV[i]][0] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> color[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        if (color[i] == 1) {
            dp[i][1] = dp[i][0];
            dp[i][0] = 0;
        }
        if (i == 0) {
            continue;
        }
        int par = parV[i];
        dp[par][1] = (1ll * dp[par][1] * (dp[i][1] + dp[i][0]) + 1ll * dp[par][0] * dp[i][1]) % MD;
        dp[par][0] = 1ll * dp[par][0] * (dp[i][1] + dp[i][0]) % MD;
    }
    cout << dp[0][1] << '\n';
    return 0;
}