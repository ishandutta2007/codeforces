#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int inv(int n) {
    return pow2(n, M - 2);
}

mt19937 rnd(0);

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
        cin >> b[i];

    vector<vector<li>> dp(n, vector<li>(2, INF64));
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0] + abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]),
                       dp[i - 1][1] + abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]));
        dp[i][1] = min(dp[i - 1][0] + abs(b[i] - a[i - 1]) + abs(a[i] - b[i - 1]),
                       dp[i - 1][1] + abs(b[i] - b[i - 1]) + abs(a[i] - a[i - 1]));
    }

    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}