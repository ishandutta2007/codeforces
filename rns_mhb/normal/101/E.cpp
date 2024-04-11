#include <bits/stdc++.h>
using namespace std;
#define pc putchar
#define x first
#define y second
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

typedef pair <int, int> pii;

#define N 20005

pii rpt[2*N];
int x[N], y[N], ans;
int n, m, p, ox, oy, dp[2][N], ep[2][N];

int val(int a, int b) {
	int res = x[a] + y[b];
	return res >= p ? res - p : res;
}

void go(int sx, int sy, int fx, int fy) {
    int d = fx + fy - sx - sy;
    int mid = d >> 1, up, dw;
    int u = 0, v = 1; dp[0][0] = 0;
    f1(i, 1, mid) {
        if (i == mid) f1(j, 0, i) ep[v][j] = j;
        up = min(i, m - sy - 1);
        dw = max(0, sx + i - n + 1);
        if (dw == 0) dw ++, dp[v][0] = dp[u][0] + val(sx + i, sy);
        if (up == i) up --, dp[v][i] = dp[u][i-1] + val(sx, sy + i);
        f1(j, dw, up) dp[v][j] = max(dp[u][j], dp[u][j-1]) + val(sx + i - j, sy + j);
        swap(u, v);
    }
    f1(i, 0, mid) ep[u][i] = i;
    f1(i, mid + 1, d) {
        up = min(i, m - sy - 1);
        dw = max(0, sx + i - n + 1);
        if (dw == 0) dw ++, dp[v][0] = dp[u][0] + val(sx + i, sy), ep[v][0] = ep[u][0];
        if (up == i) up --, dp[v][i] = dp[u][i-1] + val(sx, sy + i), ep[v][i] = ep[u][i-1];
        f1(j, dw, up) {
            dp[v][j] = max(dp[u][j], dp[u][j-1]) + val(sx + i - j, sy + j);
            ep[v][j] = dp[u][j] > dp[u][j-1] ? ep[u][j] : ep[u][j-1];
        }
        swap(u, v);
    }
    int k = ep[u][fy - sy];
    oy = sy + k;
    ox = sx + sy + mid - oy;
    if (!sx && !sy && fx == n - 1 && fy == m - 1) ans = dp[u][m - 1];
}

void func(int sx, int sy, int fx, int fy) {
    int d = fx + fy - sx - sy;
    if (d <= 1) return;
    int mid = d >> 1;
    go(sx, sy, fx, fy);
    rpt[sx + sy + mid] = pii(ox, oy);
    func(sx, sy, ox, oy);
    func(ox, oy, fx, fy);
    return;
}

int main() {
    scanf("%d %d %d", &n, &m, &p);
    f0(i, 0, n) scanf("%d", &x[i]), x[i] %= p;
    f0(i, 0, m) scanf("%d", &y[i]), y[i] %= p;
    rpt[0] = pii(0, 0);
    rpt[m+n-2] = pii(n-1, m-1);
    func(0, 0, n - 1, m - 1);
    printf("%d\n", ans + val(0, 0));
    f1(i, 1, m + n - 2) {
        if (rpt[i].x == rpt[i-1].x + 1) pc('C');
        else pc('S');
    }
	return 0;
}