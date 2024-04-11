#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = 510;
const int INF = 1e9;
int dp[MAX][MAX], a[MAX], sf[MAX];

void solve() {
    int n;
    cin >> n >> a[0];

    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= i; j++)
            dp[i][j] = INF;

    priority_queue<int> q;
    q.push({a[0]});
    for(int i = 1; i <= n; i++) {
        sf[i] = q.top();
        q.push(a[i]);
    }

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        // no switch
        for(int j = 0; j <= i - 1; j++) {
            if(j == i - 1) {
                if(i == 1)
                    dp[1][0] = 0;
                else if(dp[i - 1][j] < INF && sf[i - 1] <= a[i])
                    dp[i][j] = dp[i - 1][j];
            }
            else if(dp[i - 1][j] < INF && a[i - 1] <= a[i])
                dp[i][j] = dp[i - 1][j];
        }
        // switch
        for(int j = 0; j <= i - 1; j++) {
            if(dp[i - 1][j] < INF && (j == i - 1 || a[j] >= a[i - 1]) && a[j] < a[i])
                dp[i][i] = min(dp[i][i], dp[i - 1][j] + 1);
        }
    }

    int ans = INF;
    for(int i = 0; i <= n; i++)
        ans = min(ans, dp[n][i]);
    if(ans == INF)
        cout << "-1\n";
    else
        cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}