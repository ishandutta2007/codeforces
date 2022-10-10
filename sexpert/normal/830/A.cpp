#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

ll pp[2005], ke[2005], we[2005], dp[2005][2005];
ll INF = 1e18;

ll calc(int n, int k) {
    if(n == 0)
        return 0;
    if(k == 0)
        return INF;
    if(dp[n][k] != -1)
        return dp[n][k];
    dp[n][k] = calc(n, k - 1);
    dp[n][k] = min(dp[n][k], max(abs(pp[n] - ke[k]) + we[k], calc(n - 1, k - 1)));
    return dp[n][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, p;
    cin >> n >> k >> p;
    for(int i = 1; i <= n; i++)
        cin >> pp[i];
    for(int i = 1; i <= k; i++)
        cin >> ke[i];
    sort(pp + 1, pp + n + 1);
    sort(ke + 1, ke + k + 1);
    for(int i = 1; i <= k; i++)
        we[i] = abs(p - ke[i]);
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
            dp[i][j] = -1;
    cout << calc(n, k) << '\n';
}