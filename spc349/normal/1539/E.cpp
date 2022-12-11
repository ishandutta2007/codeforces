#include <bits/stdc++.h>
using namespace std;

struct RMQ {
	int f[100010][17], lg[100010];
#define MAXTYPE 0
#define MINTYPE 1
	int TYPE;
	int fun(int x, int y) {return TYPE == MAXTYPE ? max(x, y) : min(x, y);}
	void init(int *a, int n, int TTT) {
		TYPE = TTT; for (int i = 1; i <= n; i++) f[i][0] = a[i];
		lg[0] = -1; for (int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
		for (int j = 1; j < 17; j++) {
			for (int i = 1; i <= n; i++) {
				if (i + (1 << j) - 1 > n) break;
				f[i][j] = fun(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
			}
		}
	}
	int query(int l, int r) {
		if (l == 0) l++;
		if (r == 0) r++;
		int k = lg[r - l + 1];
		return fun(f[l][k], f[r - (1 << k) + 1][k]);
	}
};

RMQ L[2], R[2];
int X[100010], A[2][100010], B[2][100010];
int f[100010], g[100010];
int dp[100010][2], lst[100010][2];
int ans[100010];
int n, m;

int GetNxt(int p, int D, int x) {
	int l = p, r = n + 1;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (L[D].query(p, mid - 1) <= x && R[D].query(p, mid - 1) >= x) l = mid;
		else r = mid - 1;
	}
	return l;
}

void solve(int l, int r) {
	if (l == r) return ;
	int mid = l + r >> 1;
	solve(l, mid);
	int maxj = -1, p = -1;
	for (int i = mid; i >= l; i--) {
		if (dp[i][0] && maxj < f[i]) maxj = f[i], p = i;
		if (g[i] == i) break;
	}
	if (p != -1 && maxj > mid) {
		for (int i = mid + 1; i <= r; i++) {
			if (g[i] == i || maxj == i) break;
			dp[i][1] = 1, lst[i][1] = p;
		}
	}
	maxj = -1, p = -1;
	for (int i = mid; i >= l; i--) {
		if (dp[i][1] && maxj < g[i]) maxj = g[i], p = i;
		if (f[i] == i) break;
	}
	if (p != -1 && maxj > mid) {
		for (int i = mid + 1; i <= r; i++) {
			if (f[i] == i || maxj == i) break;
			dp[i][0] = 1, lst[i][0] = p;
		}
	}
	solve(mid + 1, r);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d%d%d%d", &X[i], &A[0][i], &B[0][i], &A[1][i], &B[1][i]);
	for (int it = 0; it < 2; it++) L[it].init(A[it], n, MAXTYPE), R[it].init(B[it], n, MINTYPE);
	for (int i = 0; i <= n; i++) f[i] = GetNxt(i, 0, X[i]), g[i] = GetNxt(i, 1, X[i]);
	dp[0][0] = 1, dp[0][1] = 1;
	solve(0, n);
	if (!dp[n][0] && !dp[n][1]) printf("No\n");
	else {
		printf("Yes\n");
		int cur = n, p = dp[n][0] ? 0 : 1;
		while (cur) {
			int nxt = lst[cur][p];
			for (int i = nxt + 1; i <= cur; i++) ans[i] = p;
			p ^= 1, cur = nxt;
		}
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
	}
	return 0;
}