#include <bits/stdc++.h>
using namespace std;

#define N 205
#define K 30*N

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
typedef long long ll;
const int inf = 1e9;
int n, k, ans;
ll a[N];
int ord2[N], ord5[N];
int dp[2][N][K+5];

void calc_dp() {
    for (int i = 0, t = 0; i <= n; i ++, t ^= 1)
    for (int j = 0; j <= n; j ++)
    for (int l = 0; l < K; l ++) {
        if (i < j) {
            dp[t][j][l] = -inf;
            continue;
        }
        if (!i) {
            if (!l) dp[t][j][l] = 0;
            else dp[t][j][l] = -inf;
            continue;
        }
        dp[t][j][l] = dp[t^1][j][l];
        if (l >= ord5[i] && j >= 1) chkmax(dp[t][j][l], dp[t^1][j-1][l-ord5[i]] + ord2[i]);
        if (i == n && j == k) {
            chkmax(ans, min(dp[t][j][l], l));
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%I64d", &a[i]);
        while (a[i] % 2 == 0) ord2[i] ++, a[i] /= 2;
        while (a[i] % 5 == 0) ord5[i] ++, a[i] /= 5;
    }
    calc_dp();
    printf("%d\n", ans);
    return 0;
}