#include <bits/stdc++.h>
using namespace std;

int mod, a[500], dp[501][501] = {};

void add(int &a, int b) {
    a = (a + b) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, b;
    cin >> n >> m >> b >> mod;
    for (int i=0; i<n; i++)
        cin >> a[i];

    for (int k=0; k<=b; k++)
        dp[0][k] = 1;
    for (int i=1; i<=n; i++)
        for (int j=0; j<=m; j++)
            for (int k=0; k<=b; k++)
                if (j > 0 && a[i-1] <= k)
                    add(dp[j][k], dp[j-1][k-a[i-1]]);

    cout << dp[m][b] << "\n";

    return 0;
}