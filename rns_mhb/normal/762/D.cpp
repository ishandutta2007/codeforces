#include <bits/stdc++.h>
using namespace std;

#define N 100005

template<class T> void chkmax(T &a, T b) { if (a < b) a = b; }
typedef long long ll;
const ll INF = 1e18;

int n;
int a[3][N];

ll dp[3][N], ans[3][N];

void calc_dp() {
    for (int i = 0; i < n; i ++) {
        if (!i) {
            dp[0][i] = a[0][i];
            dp[1][i] = -INF;
            dp[2][i] = -INF;
        }
        else {
            dp[0][i] = a[0][i] + ans[0][i-1];
            dp[1][i] = a[1][i] + ans[1][i-1];
            dp[2][i] = a[2][i] + ans[2][i-1];
        }
        ans[0][i] = max(dp[0][i], dp[1][i] + a[0][i]);
        chkmax(ans[0][i], dp[2][i] + a[0][i] + a[1][i]);
        if (i) chkmax(ans[0][i], dp[2][i-1] + a[0][i] + a[1][i] + a[2][i] + a[0][i-1] + a[1][i-1]);
        ans[1][i] = max(dp[1][i], dp[0][i] + a[1][i]);
        chkmax(ans[1][i], dp[2][i] + a[1][i]);
        ans[2][i] = max(dp[2][i], dp[1][i] + a[2][i]);
        chkmax(ans[2][i], dp[0][i] + a[1][i] + a[2][i]);
        if (i) chkmax(ans[2][i], dp[0][i-1] + a[0][i] + a[1][i] + a[2][i] + a[1][i-1] + a[2][i-1]);
    }
}

int main() {
    
    scanf("%d", &n);
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < n; j ++) {
            scanf("%d", &a[i][j]);
        }
    }
    calc_dp();
    printf("%I64d\n", ans[2][n-1]);
    return 0;
}