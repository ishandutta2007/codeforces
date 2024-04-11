#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50, mod = 998244353;

int n;
vector<int> G[N];
ll dp[N][3];

void dfs(int v) {
    if(G[v].empty()) {
        dp[v][2] = 1;
        return ;
    }

    dp[v][0] = 1;
    for(int nxt : G[v]) {
        dfs(nxt);
        dp[v][2] = (dp[v][2] * (dp[nxt][0] + dp[nxt][2]) + (dp[v][1] + dp[v][2]) * (dp[nxt][1] + dp[nxt][2])) % mod;
        dp[v][1] = (dp[v][1] * (dp[nxt][0] + dp[nxt][2]) + dp[v][0] * (dp[nxt][1] + dp[nxt][2])) % mod;
        dp[v][0] = dp[v][0] * (dp[nxt][0] + dp[nxt][2]) % mod;
    }
}

int main() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int a; cin >> a; a--;
        G[a].push_back(i);
    }
    dfs(0);
    cout << (dp[0][0] + dp[0][2]) % mod << endl;
}