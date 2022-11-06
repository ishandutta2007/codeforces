#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
        a[i]--;
    }
    vector<int> first(n, n), last(n, -1);
    vector<int> cnt(n, 0);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[i] = cnt[a[i]]++;
        first[a[i]] = min(first[a[i]], i);
        last[a[i]] = max(last[a[i]], i);
    }
    int res = *max_element(cnt.begin(), cnt.end());
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        if (i == last[a[i]])
            dp[i + 1] = max(dp[i + 1], dp[first[a[i]]] + cnt[a[i]]);
        res = max(res, dp[i] + cnt[a[i]] - pos[i]);
    }
    cout << n - res << "\n";
    return 0;
}