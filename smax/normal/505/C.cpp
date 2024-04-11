#include <bits/stdc++.h>
using namespace std;

int gems[30001] = {}, dp[30001][500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, d;
    cin >> n >> d;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        gems[p]++;
    }

    memset(dp, 128, sizeof(dp));
    dp[d][245] = gems[d];
    int ret = 0;
    for (int i=d; i<=30000; i++)
        for (int j=max(0, 246-d); j<=490; j++) {
            ret = max(ret, dp[i][j]);
            int l = d + j - 245;
            assert(l > 0);
            for (int k : {l - 1, l, l + 1})
                if (k > 0 && i + k <= 30000 && dp[i][j] + gems[i+k] > dp[i+k][k-d+245])
                    dp[i+k][k-d+245] = dp[i][j] + gems[i+k];
        }

    cout << ret << "\n";

    return 0;
}