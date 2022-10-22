#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e6 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

/*
*/

int pw_m[N];
int pw_m1[N];

int dp[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if(m == 1) {
        cout << n + 1 << endl;
        return 0;
    }

    pw_m[0] = pw_m1[0] = 1;
    for(int i = 1; i < N; i++) {
        pw_m[i] = mul(pw_m[i - 1], m);
        pw_m1[i] = mul(pw_m1[i - 1], m - 1);
    }

    int inv = pow2(m - 1, M - 2);

    int ans = pw_m[n];
    dp[0] = 1;

    int s = pw_m1[n];
    for(int i = 1; i <= n; i++) {
        dp[i] = mul(m, mul(s, pow2(inv, n - i + 1)));

        s = sum(s, mul(dp[i], pw_m1[n - i]));

        ans = sum(ans, mul(dp[i], pw_m[n - i]));

//        cout << i << ' ' << dp[i] << endl;
    }

    cout << ans << endl;
}