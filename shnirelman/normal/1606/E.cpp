//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 500 + 13;
const int M = 998244353;
const ld eps = 1e-6;
const int B = 300;
const int K = 400;
const int LOGN = 20;

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

/*
*/

//void solve() {
//}

int C[N][N];
int pw[N][N];
int dp[N][N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    C[0][0] = 1;
    for(int i = 1; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] = sum(C[i - 1][j - 1], C[i - 1][j]);
        }
    }

    for(int i = 1; i < N; i++) {
        pw[i][0] = 1;
        for(int j = 1; j < N; j++) {
            pw[i][j] = mul(pw[i][j - 1], i);
        }
    }

    int n, x;
    cin >> n >> x;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= x; j++) {
            if(i - 1 >= j) {
                dp[i][j] = sum(dp[i][j], mul(C[n][i], dif(pw[j][i], pw[j - 1][i])));
            }

//            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            for(int k = 0; k + i + j - 1 <= x; k++) {
                dp[i + k][j + i + k - 1] = sum(dp[i + k][j + i + k - 1], mul(dp[i][j], mul(C[n - i][k], pw[i + k - 1][k])));
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= x; i++) {
        ans = sum(ans, dp[n][i]);
    }

    cout << ans << endl;

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}