#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 250 + 13;
const int LOGN = 30;

/*

*/

int sum(int a, int b) {
    a += b;
    return (a < M ? a : a - M);
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

int dp[N][N];
int C[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    cout << pow2(2, 10) << ' ' << pow2(3, 4) << endl;

    for(int i = 0; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++)
            C[i][j] = sum(C[i - 1][j - 1], C[i - 1][j]);
    }

//    for(int i = 0; i < 5; i++) {
//        for(int j = 0; j <= i; j++)
//            cout << C[i][j] << ' ';
//        cout << endl;
//    }

    int n, k;
    cin >> n >> k;

    dp[1][0] = 1;
    for(int i = 0; i <= k; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            for(int x = 1; x <= i; x++) {
                dp[i][j] = sum(dp[i][j], mul(mul(mul(dp[x][j - 1],
                                                pow2(k - j + 1, (i - x) * (i - x - 1) / 2)),
                                                pow2(k - j + 1, (x - 1) * (i - x))),
                                                C[n - x][i - x]));

//                cout << "add to i = " << i << " j = " << j << "   from x = " << x << " j-1 = " << j - 1 << " dp = " << dp[x][j - 1] << " " <<
//                                                pow2(k - j + 1, (i - x) * (i - x - 1) / 2) << " " <<
//                                                pow2(k - j + 1, (x - 1) * (i - x)) << ' ' << C[n - x][i - x] << endl;
            }

//            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }


    cout << dp[n][k] << endl;

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}