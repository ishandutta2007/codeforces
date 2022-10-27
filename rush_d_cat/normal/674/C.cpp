#include <iostream>
using namespace std;
const int N = 200000+10;
int n, k, rk;
double dp[52][N], S[N], T[N], sum[N], t[N];
void dfs(int l, int r, int qL, int qR) {
    int mid = (l + r) >> 1;
    double mn = 1e18; int best = qL;
    for (int i = qL; i < mid && i <= qR; i ++) {
        double tmp = dp[rk-1][i] + S[mid]-S[i] - (T[mid]-T[i]) * sum[i];
        if (tmp < mn) {
            mn = tmp, best = i;
        }
    }
    dp[rk][mid] = mn;
    if (l < mid) dfs(l,mid-1,qL,best);
    if (r > mid) dfs(mid+1,r,best,qR);
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%lf", &t[i]); 
        sum[i] = sum[i-1] + t[i];
        S[i] = S[i-1] + sum[i] / t[i];
        T[i] = T[i-1] + 1 / t[i];
    }
    for (int i = 1; i < N; i ++) dp[0][i] = 1e20;
    for (int i = 1; i <= k; i ++) {
        rk = i; dfs(1,n,0,n-1);
    }
    printf("%.8f\n", dp[k][n]);
}