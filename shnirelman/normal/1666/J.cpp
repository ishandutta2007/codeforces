#include <bits/stdc++.h>

using namespace std;
using li = long long;

const li INF64 = 1e18 + 13;
const int N = 200 + 13;

int a[N][N];
li dp[N][N];
int res[N][N];
li p[N][N];
int ans[N];

li get(int i1, int j1, int i2, int j2) {
    return p[i2][j2] - p[i1][j2] - p[i2][j1] + p[i1][j1];
}

void calc(int l, int r, int par) {
    ans[res[l][r]] = par;
    if(res[l][r] > l)
        calc(l, res[l][r], res[l][r]);
    if(res[l][r] < r - 1)
        calc(res[l][r] + 1, r, res[l][r]);
}

mt19937 rnd(0);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 186;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }
//
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < i; j++) {
//            a[i][j] = a[j][i] = rnd() % 100;
//        }
//    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            p[i + 1][j + 1] = a[i][j] + p[i + 1][j] + p[i][j + 1] - p[i][j];
        }
    }
//cout << "sagasfg" << endl;
    for(int i = 0; i < n; i++) {
        dp[i][i + 1] = 0;
        res[i][i + 1] = i;
    }

    for(int len = 2; len <= n; len++) {
//        cout << "len " << len << endl;
        for(int l = 0; l + len <= n; l++) {
//            if(len == 76)cout << "l " << l << endl;
            int r = l + len;
            dp[l][r] = INF64;
            for(int v = l; v < r; v++) {
//                if(len == 76 && l == 85)
//                    cout << v << endl;
//                li rs = dp[l][v] + dp[v + 1][r] +
//                (p[n][n] - get(l, l, v, v)) / 2 +
//                (p[n][n] - get(v + 1, v + 1, r, r)) / 2;

                li rs = dp[l][v] + dp[v + 1][r] +
                (get(l, 0, v, n) - get(l, l, v, v)) +
                (get(v + 1, 0, r, n) - get(v + 1, v + 1, r, r));

//                li rs = dp[l][v] + dp[v + 1][r] +
//                (get(0, l, l, v) + get(l, l, v, v)) +
//                (get(v + 1, 0, r, n) + get(v + 1, v + 1, r, r));

//                cout << l << ' ' << v << ' ' << r << ' ' <<
//                dp[l][v] << ' ' << dp[v + 1][r] << ' ' <<
//                (get(l, 0, v, n) - get(l, l, v, v) / 2) << ' ' <<
//                (get(v + 1, 0, r, n) - get(v + 1, v + 1, r, r) / 2) <<
//                ' ' << get(l, 0, v, n) << endl;
//                cout << get(l, 0, v, n) << ' ' << get(l, l, v, v) << endl;

                if(dp[l][r] > rs) {
                    dp[l][r] = rs;
                    res[l][r] = v;
                }
            }

//            cout << l << ' ' << r << ' ' << dp[l][r] << endl;
        }
    }

    calc(0, n, -1);

//    cout << dp[0][n] << endl;

    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
    cout << endl;
}