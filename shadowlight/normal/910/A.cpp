#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    int n, d;
    cin >> n >> d;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    vector <int> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= d; j++) {
            if (i - j < 0) break;
            if (!a[i - j]) continue;
            dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    cout << (dp[n - 1] == INF ? -1 : dp[n - 1]);
}