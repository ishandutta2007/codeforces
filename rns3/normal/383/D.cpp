#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;

#define N 1010
#define M 10001

int n, a[N], f[N][2*M], u[2*M], v[2*M], sum[N];

int solve(int st, int en) {
    if (st == en) return 0;
    if (st == en - 1) return a[st] == a[en]? 2 : 0;
    int mid = (st + en) / 2, rlt = 0, m = sum[en] - sum[st-1] + 1;
    for (int i = 0; i < 2 * m; i ++) f[mid][i] = f[mid+1][i] = 0;
    f[mid][m-a[mid]] = f[mid][m+a[mid]] = f[mid+1][m-a[mid+1]] = f[mid+1][m+a[mid+1]] = 1;
    for (int i = mid - 1; i >= st; i --) {
		for (int j = -m; j < m; j ++) {
			f[i][j+m] = 0;
			if (j + m - a[i] >= 0) f[i][j+m] += f[i+1][j+m-a[i]];
			if (j + m + a[i] < 2 * m) f[i][j+m] += f[i+1][j+m+a[i]];
			f[i][j+m] %= P;
		}
    }
    for (int i = mid + 2; i <= en; i ++) {
		for (int j = -m; j < m; j ++) {
			f[i][j+m] = 0;
			if (j + m - a[i] >= 0) f[i][j+m] += f[i-1][j+m-a[i]];
			if (j + m + a[i] < 2 * m) f[i][j+m] += f[i-1][j+m+a[i]];
			f[i][j+m] %= P;
		}
    }
    for (int i = 0; i < 2 * m; i ++) {
		u[i] = v[i] = 0;
		for (int j = mid; j >= st; j --) u[i] = (u[i] + f[j][i]) % P;
		for (int j = mid + 1; j <= en; j ++) v[i] = (v[i] + f[j][i]) % P;
    }
    for (int i = 1; i < 2 * m; i ++) rlt = (rlt + 1ll * u[i] * v[2*m-i]) % P;
    rlt = (rlt + solve(st, mid)) % P;
    rlt = (rlt + solve(mid + 1, en)) % P;
    return rlt;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) sum[i] = sum[i-1] + a[i];
	printf("%d\n", solve(1, n));
	return 0;
}