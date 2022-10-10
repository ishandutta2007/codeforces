#include <bits/stdc++.h>
using namespace std;

int dp[200000] = {}, charDp[26] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    int ret = 0;
    for (int i=0; i<n; i++) {
        for (int j=s[i]-'a'+1; j<26; j++)
            dp[i] = max(dp[i], charDp[j]);
        dp[i]++;
        ret = max(ret, dp[i]);
        charDp[s[i]-'a'] = dp[i];
    }

    cout << ret << "\n";
    vector<vector<char>> seq(ret);
    for (int i=0; i<n; i++) {
        int color;
        for (int j=0; j<ret; j++)
            if (seq[j].empty() || seq[j].back() <= s[i]) {
                seq[j].push_back(s[i]);
                color = j + 1;
                break;
            }
        cout << color << " ";
    }
    cout << "\n";

    return 0;
}