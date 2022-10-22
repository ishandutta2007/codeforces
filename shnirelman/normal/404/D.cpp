#include <bits/stdc++.h>

#define f irst
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int M = 1e9 + 7;
const int N = 1e6 + 13;
const int K = 4;

int sum(int a, int b) {
    int res = a + b;

    while(res >= M)
        res -= M;

    return res;
}

/*
0..2 - 0..2
3 - *

*??
*?*
*1?
??
*/

int dp[N][K][2];
int c[256];

int main() {
    string s;
    cin >> s;

    int n = s.length();

    if(s[0] == '2' || s[n - 1] == '2') {
        cout << 0;
        return 0;
    }

    c['0'] = 0;
    c['1'] = 1;
    c['2'] = 2;
    c['*'] = 3;
    c['?'] = -1;

    if(c[s[0]] == -1) {
        dp[0][0][0] = dp[0][1][0] = dp[0][3][0] = 1;
    } else {
        dp[0][c[s[0]]][0] = 1;
    }

    for(int i = 1; i < n; i++) {
        if(s[i] == '*' || s[i] == '?') {
            dp[i][3][1] = sum(dp[i][3][1], dp[i - 1][3][0]);
            dp[i][3][1] = sum(dp[i][3][1], dp[i - 1][3][1]);
            dp[i][3][0] = sum(dp[i][3][0], dp[i - 1][1][0]);
            dp[i][3][0] = sum(dp[i][3][0], dp[i - 1][2][1]);
        }

        if(s[i] == '0' || s[i] == '?') {
            dp[i][0][0] = sum(dp[i][0][0], dp[i - 1][0][0]);
            dp[i][0][0] = sum(dp[i][0][0], dp[i - 1][1][1]);
        }

        if(s[i] == '1' || s[i] == '?') {
            dp[i][1][0] = sum(dp[i][1][0], dp[i - 1][0][0]);
            dp[i][1][0] = sum(dp[i][1][0], dp[i - 1][1][1]);
            dp[i][1][1] = sum(dp[i][1][1], dp[i - 1][3][0]);
            dp[i][1][1] = sum(dp[i][1][1], dp[i - 1][3][1]);
        }

        if(s[i] == '2' || s[i] == '?') {
            dp[i][2][1] = sum(dp[i][2][1], dp[i - 1][3][0]);
            dp[i][2][1] = sum(dp[i][2][1], dp[i - 1][3][1]);
        }
    }

    int ans = 0;

    ans = sum(ans, dp[n - 1][0][0]);
    ans = sum(ans, dp[n - 1][1][1]);
    ans = sum(ans, dp[n - 1][3][0]);
    ans = sum(ans, dp[n - 1][3][1]);

//    cout << 0 << ' ' << 0 << ' ' << dp[n - 1][0][0] << endl;
//    cout << 1 << ' ' << 1 << ' ' << dp[n - 1][1][1] << endl;
//    cout << 3 << ' ' << 0 << ' ' << dp[n - 1][3][0] << endl;
//    cout << 3 << ' ' << 1 << ' ' << dp[n - 1][3][1] << endl;

    cout << ans;
}