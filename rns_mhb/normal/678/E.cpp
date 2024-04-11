#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
#define f0(i, a, b) for (int i = a; i < b; i ++)

#define N 20
#define M 1 << 18

int n;
double p[N][N];
double dp[M][N];

double solve(int st, int k) {
    if (dp[st][k] > -0.5) return dp[st][k];
    double &ans = dp[st][k];
    f0(i, 0, n) if (!(st & (1 << i))) {
		ans = max(ans, solve(st | (1 << i), k) * p[k][i] + solve(st | (1 << i), i) * p[i][k]);
	}
    return ans;
}

int main() {
    scanf("%d", &n);
    if (n == 1) {
        puts("1");
        return 0;
    }
    f0(i, 0, n) f0(j, 0, n) scanf("%lf", &p[i][j]);
    int up = 1 << n;
    f0(i, 0, up) f0(j, 0, n) dp[i][j] = -1;
    dp[up-1][0] = 1; f0(i, 1, n) dp[up-1][i] = 0;
    double ans = 0;
    f0(i, 0, n) {
		f0(j, i + 1, n) {
			double now = 0;
            int st = (1 << i) | (1 << j);
            now += solve(st, i) * p[i][j];
            now += solve(st, j) * p[j][i];
            ans = max(ans, now);
		}
    }
    printf("%.10lf\n", ans);
	return 0;
}