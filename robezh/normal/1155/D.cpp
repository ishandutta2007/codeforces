#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50;

int n, x;
ll a[N];
ll dp[3][N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        dp[0][i] = max(0LL, dp[0][i-1] + a[i]);
        dp[1][i] = max(dp[0][i-1] + x * a[i], dp[1][i-1] + x * a[i]);
        dp[2][i] = max(dp[1][i-1] + a[i], dp[2][i-1] + a[i]);
        for(int j = 0; j < 3; j++) res = max(res, dp[j][i]);
    }
    cout << max(res, 0LL) << endl;
}