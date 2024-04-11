#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, dp[110][10010], b[110], c[110];
int sb[110], ssb[110];
const int MOD = 1e9 + 7;
void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
int X[100010];

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&c[i]);
    }
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d",&b[i]);
        sb[i] = sb[i - 1] + b[i];
        ssb[i] = ssb[i - 1] + sb[i];
    }
    int Q, x;
    scanf("%d",&Q);
    for (int i = 1; i <= Q; i++) {
        scanf("%d",&X[i]);
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (dp[i][j]) {
                for (int k = 0; k <= c[i + 1]; k++) {
                    if (j + k >= (i + 1) * X[1] + ssb[i]) {
                        add(dp[i + 1][j + k], dp[i][j]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 10000; i++) add(ans, dp[n][i]);
    printf("%d\n",ans);
}