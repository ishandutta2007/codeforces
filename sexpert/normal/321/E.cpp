#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e3 + 5, INF = 1e9;
int mat[MAXN][MAXN], dp[MAXN][MAXN], cost[MAXN][MAXN], scost[MAXN][MAXN];

void compute(int p, int L, int R, int oL, int oR) {
    if(L > R) return;
    int n = (L + R)/2;
    dp[p][n] = INF;
    int opt = -1;
    for(int k = oL; k <= oR; k++) {
        int dk = dp[p - 1][k] + cost[k + 1][n];
        if(dk < dp[p][n]) {
            opt = k;
            dp[p][n] = dk;
        }
    }
    //cout << p << " " << n << " " << dp[p][n] << " " << oL << " " << oR << '\n';
    compute(p, L, n - 1, oL, opt);
    compute(p, n + 1, R, opt, oR);
}

int main() {
    int n, k;
    cin >> n >> k;
    getchar();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            mat[i][j] = (getchar() - '0');
            getchar();
        }
    }
    

    //if(n == 4000)
    //    cout << "no\n";

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scost[i][j] = scost[i][j - 1] + mat[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        cost[i][i] = 0;
        for(int j = i + 1; j <= n; j++) {
            cost[i][j] = cost[i][j - 1] + (scost[j][j] - scost[j][i - 1]);
            //cout << "(" << i << ", " << j << ") " << cost[i][j] << '\n';
        }
    }

    dp[0][0] = 0;
    for(int i = 1; i < MAXN; i++)
        dp[0][i] = INF;

    for(int i = 1; i <= k; i++)
        compute(i, 0, n, 0, n - 1);

    cout << dp[k][n] << endl;
}