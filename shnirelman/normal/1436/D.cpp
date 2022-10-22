#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

vector<int> g[N];
li a[N], sum[N], dp[N], cnt[N];

void dfs(int v, int par) {
    sum[v] = a[v];

    bool fl = true;

    for(auto u : g[v]) {
        if(u == par)
            continue;


        dfs(u, v);
        sum[v] += sum[u];
        dp[v] = max(dp[v], dp[u]);
        cnt[v] += cnt[u];
        fl = false;
    }

    cnt[v] += fl;

    dp[v] = max(dp[v], (sum[v] + cnt[v] - 1) / cnt[v]);
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;

        p--;

        g[p].push_back(i);
        g[i].push_back(p);
    }

    for(int i = 0; i < n; i++)
        cin >> a[i];

    dfs(0, 0);

    cout << dp[0] << endl;
}