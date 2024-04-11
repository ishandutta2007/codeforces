#include <bits/stdc++.h>
using namespace std;

int n, m, dp[1000000], dist[1000000] = {0};
vector<string> graph;

int dfs(int r, int c, int d) {
    if (dp[m * r + c] != -1)
        return dp[m * r + c];
    else if (r == n - 1 && c == m - 1)
        return dist[d] = dp[m * r + c] = 1;

    dp[m * r + c] = 0;
    if (r < n - 1 && graph[r+1][c] != '#')
        dp[m * r + c] |= dfs(r+1, c, d+1);
    if (c < m - 1 && graph[r][c+1] != '#')
        dp[m * r + c] |= dfs(r, c+1, d+1);

    if (dp[m * r + c])
        dist[d]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string row;
        cin >> row;
        graph.push_back(row);
    }

    memset(dp, -1, sizeof(dp));
    dfs(0, 0, 0);

    if (dist[n+m-2] == 0) {
        cout << "0\n";
        return 0;
    }
    for (int i=1; i<n+m-2; i++)
        if (dist[i] == 1) {
            cout << "1\n";
            return 0;
        }
    cout << "2\n";

    return 0;
}