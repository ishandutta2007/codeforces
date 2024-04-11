#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1005;
int a[MAXN];
ll binom[MAXN][MAXN], dp[MAXN], pdp[MAXN];
const ll MOD = 998244353;

ll bin(int n, int m) {
    if(m > n)
        return 0;
    return binom[n][m];
}

void add(ll &x, ll y) {
    x += y;
    x %= MOD;
}

int main() {
    binom[0][0] = 1;
    for(int i = 1; i < MAXN; i++) {
        binom[i][0] = 1;
        for(int j = 1; j <= i; j++)
            binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % MOD;
    }
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    dp[0] = pdp[0] = pdp[1] = 1;
    ll ans = 0;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(a[j] <= 0)
                continue;
            add(dp[i], pdp[j - 1] * bin(i - j - 1, a[j] - 1));
        }
        pdp[i] = (pdp[i - 1] + dp[i]) % MOD;
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << '\n';
}