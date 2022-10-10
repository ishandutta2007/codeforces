#include <bits/stdc++.h>
using namespace std;

int n, m, mx[15], cost[15], prof[15], memo[1005][15];

int dp(int dough, int ind) {
    if(ind == -1)
        return 0;
    if(memo[dough][ind] != -1)
        return memo[dough][ind];
    int ans = 0;
    for(int i = 0; i * cost[ind] <= dough && i <= mx[ind]; i++)
        ans = max(ans, i * prof[ind] + dp(dough - i * cost[ind], ind - 1));
    return memo[dough][ind] = ans;
}

int main() {
    memset(memo, -1, sizeof memo);
    cin >> n >> m >> cost[0] >> prof[0];
    mx[0] = 100000;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b >> cost[i] >> prof[i];
        mx[i] = a / b;
    }
    cout << dp(n, m) << endl;
}