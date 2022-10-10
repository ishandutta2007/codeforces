#include <bits/stdc++.h>
using namespace std;

int l[80], r[80], dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int x, s;
        cin >> x >> s;
        l[i] = max(x - s, 0);
        r[i] = min(x + s, m);
    }

    dp[m] = 0;
    for (int x=m-1; x>=0; x--) {
        dp[x] = m - x;
        for (int i=0; i<n; i++) {
            if (l[i] <= x + 1 && x + 1 <= r[i]) {
                dp[x] = dp[x+1];
                break;
            } else if (l[i] > x)
                dp[x] = min(dp[x], dp[min(r[i] + l[i] - x - 1, m)] + l[i] - x - 1);
        }
    }

    cout << dp[0] << "\n";

    return 0;
}