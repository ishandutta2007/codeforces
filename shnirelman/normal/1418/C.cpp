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
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

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

    if(k % 2)
        return mul(pw, n);
    else
        return pw;
}
/*
*/

int a[N];
int dp[N][2];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    dp[0][0] = 0;
    dp[0][1] = INF;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], (i > 1 ? dp[i - 2][1] : INF));
        dp[i][1] = min(dp[i - 1][0] + a[i - 1], (i > 1 ? dp[i - 2][0] + a[i - 1] + a[i - 2] : INF));

//        for(int j = 0; j < 2; j++) {
//            dp[i][j] =
//        }
    }

    cout << min(dp[n][0], dp[n][1]) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}