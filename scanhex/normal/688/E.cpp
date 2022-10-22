//
// Created by Alexander Morozov on 29/06/16.
//
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    vector<int> c(n);
    for (auto& x : c)
        cin >> x;
    sort(c.begin(), c.end());
    vector<vector<vector<bool>>> dp(2, vector<vector<bool>>(k + 1, vector<bool>(k + 1)));
    dp[0][0][0] = true;
    for (int i = 0; i < n; ++i)
    {
        for (int s = 0; s <= k; ++s)
        {
            for (int l = 0; l <= k; ++l)
            {
                if (!dp[i & 1][s][l])
                    continue;
                dp[i & 1 ^ 1][s][l] = true;
                if (s + c[i] <= k)
                    dp[i & 1 ^ 1][s + c[i]][l] = true;
                if (s + c[i] <= k && l + c[i] <= k)
                    dp[i & 1 ^ 1][s + c[i]][l + c[i]] = true;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <= k; ++i)
        if (dp[n & 1][k][i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for (auto& x : ans)
        cout << x << ' ';
}