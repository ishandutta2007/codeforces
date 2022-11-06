#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 17;
const ll INF = 1e18 + 239;

int n;
ll r1, r2, r3, d;
ll a[N];
ll dp[N];

ll two(int i) {
    return min(r1 * (a[i] + 2), r1 + r2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = INF;
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + r1 * a[i] + r3);
        dp[i] = min(dp[i], dp[i - 1] + two(i) + 2 * d);
        if (i >= 2) {
            dp[i] = min(dp[i], dp[i - 2] + two(i) + two(i - 1) + 2 * d);
            if (i == n)
                dp[i] = min(dp[i], dp[i - 2] + two(i - 1) + r1 * a[i] + r3 + d);
        }
    }
    cout << dp[n] + d * (n - 1);
    return 0;
}