#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

inline int get_cost(vector<int> a) {
    int n = a.size();
    vector<int> dp(n, INF);
    int res = n;
    for (int i = 0; i < n; i++) {
        dp[i] = 0;
        if (i != 0) {
            dp[i] += min(i, dp[i - 1] + a[i] - a[i - 1] - 1);
        }
        res = min(res, dp[i] + n - i - 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<vector<int>> a(k);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt++;
                a[i % k].push_back(i / k);
            }
        }
        int ans = INF;
        for (auto v : a) {
            int m = v.size();
            ans = min(ans, cnt - m + get_cost(v));
        }
        cout << ans << '\n';
    }
    return 0;
}