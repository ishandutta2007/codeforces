#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) 
        dp[i] = -INF;
    int mod = 0;
    set<pair<int, int>> s;
    for (int i = 0; i <= n; i++) 
        s.insert({dp[i], i});
    for (int i = 1; i < n; i++) {
        int cur = s.rbegin()->first + mod;
        s.erase(s.find({dp[a[i]], a[i]}));
        if (!s.empty())
            cur = max(cur, s.rbegin()->first + mod + 1);
        s.insert({dp[a[i]], a[i]});
        if (a[i] != a[i - 1]) 
            mod++; 
        if (cur >= 0) {
            int mx = max(dp[a[i - 1]] + mod, cur);
            s.erase({dp[a[i - 1]], a[i - 1]});
            dp[a[i - 1]] = mx - mod;
            s.insert({dp[a[i - 1]], a[i - 1]});
        }
    }
    cout << s.rbegin()->first + mod << endl;
    return 0;
}