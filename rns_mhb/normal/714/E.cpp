#include <bits/stdc++.h>
using namespace std;

#define N 3005
#define INF 1000000000000000000

typedef long long ll;

int n;
int a[N], id[N];
ll dp[2][2][N];

bool cmp(int x, int y) {return a[x] < a[y];}

void calc_dp() {
    for (int i = 1, t = 0; i <= n; i ++, t ^= 1) {
        dp[1][t][0] = INF;
        for (int j = 1; j <= n; j ++) {
            dp[0][t][j] = dp[1][t^1][j] + abs(a[id[j]] - a[i]);
            dp[1][t][j] = min(dp[1][t][j-1], dp[0][t][j]);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", a + i);
        a[i] -= i - 1;
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    calc_dp();
    printf("%I64d\n", dp[1][n&1^1][n]);
    return 0;
}