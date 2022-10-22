#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
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
    string hard = "hard";
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <vector <ll> > dp(n + 1, vector <ll> (5, INF));
    for (int i = 0; i < 4; i++) {
        dp[0][0] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            int v = j + (int) (hard[j] == s[i]);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i]);
            dp[i + 1][v] = min(dp[i + 1][v], dp[i][j]);
        }
    }
    ll res = INF;
    for (int i = 0; i < 4; i++) {
        res = min(res, dp[n][i]);
    }
    cout << res;
}