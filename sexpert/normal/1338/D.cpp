#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
vector<int> adj[MAXN];
int dp[MAXN][2];
int ans;

void merge(array<int, 2> &a, int x) {
    if(x > a[0]) {
        swap(a[0], a[1]);
        a[0] = x;
        return;
    }
    if(x > a[1])
        a[1] = x;
}

void dfs(int s, int p = 0) {
    array<int, 2> owo = {0, 0}, uwu = {0, 0};
    dp[s][1] = 1;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
        dp[s][0] = max(dp[s][0], max(dp[v][0], dp[v][1]) + (int)adj[s].size() - 2 + (s == 0));
        dp[s][1] = max(dp[s][1], 1 + dp[v][0]);
        merge(owo, dp[v][0]);
        merge(uwu, max(dp[v][0], dp[v][1]));
    }
    ans = max(ans, dp[s][0]);
    ans = max(ans, dp[s][1]);
    ans = max(ans, uwu[0] + uwu[1] + (int)adj[s].size() - 2);
    ans = max(ans, owo[0] + owo[1] + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = 0;
    dfs(1);
    cout << ans << '\n';
}