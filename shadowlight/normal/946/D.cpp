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
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> dp(k + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        vector <int> dp1(k + 1, INF);
        string s;
        cin >> s;
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') {
                cnt++;
            }
        }
        if (cnt <= k) {
            dp1[cnt] = 0;
        }
        for (int l = 0; l < m; l++) {
            int cnt1 = 0;
            for (int r = l; r < m; r++) {
                if (s[r] == '1') {
                    cnt1++;
                }
                if (cnt - cnt1 > k) continue;
                dp1[cnt - cnt1] = min(dp1[cnt - cnt1], r - l + 1);
            }
        }
        for (int j = 1; j <= k; j++) {
            dp1[j] = min(dp1[j], dp1[j - 1]);
        }
        vector <int> dpn(k + 1, INF);
        for (int j = 0; j <= k; j++) {
            for (int add = 0; add <= k; add++) {
                if (j + add > k) break;
                dpn[j + add] = min(dpn[j + add], dp[j] + dp1[add]);
            }
        }
        for (int j = 1; j <= k; j++) {
            dpn[j] = min(dpn[j], dpn[j - 1]);
        }
        dp = dpn;
    }
    cout << dp[k];
}