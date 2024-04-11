#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    vector <int> c;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (c.size() && x == c.back()) continue;
        c.push_back(x);
    }
    n = c.size();
    int dp[n + 1][n + 1];
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
        dp[i][i + 1] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l < n; l++) {
            int r = l + len;
            if (r > n) break;
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
            if (c[l] == c[r - 1]) {
                dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + 1);
            }
        }
    }
    cout << dp[0][n];
}