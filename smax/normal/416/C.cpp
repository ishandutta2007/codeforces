#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001] = {};
pair<int, int> r[1000], parent[1001][1001];
pair<int, pair<int, int>> group[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> group[i].first >> group[i].second.first;
        group[i].second.second = i + 1;
    }

    int k;
    cin >> k;
    for (int i=0; i<k; i++) {
        cin >> r[i].first;
        r[i].second = i + 1;
    }

    sort(group, group + n);
    sort(r, r + k);

    for (int i=0; i<=n; i++)
        parent[i][0] = {-1, -1};
    for (int j=0; j<=k; j++)
        parent[0][j] = {-1, -1};
    for (int i=1; i<=n; i++)
        for (int j=1; j<=k; j++) {
            if (dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                parent[i][j] = {i-1, j};
            } else {
                dp[i][j] = dp[i][j-1];
                parent[i][j] = {i, j-1};
            }
            if (group[i-1].first <= r[j-1].first && dp[i-1][j-1] + group[i-1].second.first > dp[i][j]) {
                dp[i][j] = dp[i-1][j-1] + group[i-1].second.first;
                parent[i][j] = {i-1, j-1};
            }
        }

    int i = n, j = k;
    vector<pair<int, int>> ret;
    while (i && j) {
        int newI = parent[i][j].first, newJ = parent[i][j].second;
        if (newI == i - 1 && newJ == j - 1)
            ret.emplace_back(group[i-1].second.second, r[j-1].second);
        i = newI, j = newJ;
    }

    cout << ret.size() << " " << dp[n][k] << "\n";
    for (auto p : ret)
        cout << p.first << " " << p.second << "\n";

    return 0;
}