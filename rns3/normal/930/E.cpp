#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return rlt;
}

#define N 101010

int k, n, m;

int dp[N*4][3];
int sdp[N*4][3];

int z[N*4];

typedef pair <int, int> pii;

pii p[N], q[N];

bool cmp(pii a, pii b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}

int e;

int convert(int x) {
	int rlt = lower_bound(z + 1, z + e + 1, x) - z;
	return rlt;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d %d", &k, &n, &m);
	for (int i = 1, x, y; i <= n + m; i ++) {
		scanf("%d %d", &x, &y);
		x --;
		y = min(y, k);
		z[++e] = x, z[++e] = y;
		if (i <= n) p[i] = make_pair(x, y);
		else q[i-n] = make_pair(x, y);
	}
	z[++e] = 0;
	z[++e] = k;
	sort(z + 1, z + e + 1);
	int ee = 0;
	for (int i = 1; i <= e; i ++) if (i == 1 || z[i] != z[i-1]) z[++ee] = z[i];
	e = ee;
	for (int i = 1; i <= n; i ++) p[i] = make_pair(convert(p[i].first), convert(p[i].second));
	for (int i = 1; i <= m; i ++) q[i] = make_pair(convert(q[i].first), convert(q[i].second));

	sort(p + 1, p + n + 1, cmp);
	sort(q + 1, q + m + 1, cmp);

	dp[1][0] = sdp[1][0] = 0;
	dp[1][1] = sdp[1][1] = 0;
	dp[1][2] = sdp[1][2] = 1;
	int nn = 1, mm = 1;

	int val0 = 0, val1 = 0;
	for (int i = 2; i <= e; i ++) {
		dp[i][0] = 1;
		dp[i][1] = 1;
		dp[i][2] = expmod(2, z[i] - z[i-1]) - 2;

		while (mm <= m && q[mm].second == i) {
			val1 = max(val1, q[mm].first);
			mm ++;
		}
		dp[i][0] = (1ll * sdp[i-1][1] + sdp[i-1][2] - sdp[val1][1] - sdp[val1][2]) * dp[i][0] % mod;

		while (nn <= n && p[nn].second == i) {
			val0 = max(val0, p[nn].first);
			nn ++;
		}
		dp[i][1] = (1ll * sdp[i-1][0] + sdp[i-1][2] - sdp[val0][0] - sdp[val0][2]) * dp[i][1] % mod;
		dp[i][2] = (1ll * dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) * dp[i][2] % mod;

		for (int k = 0; k < 3; k ++) sdp[i][k] = (sdp[i-1][k] + dp[i][k]) % mod;
	}
	int ans = (1ll * dp[e][0] + dp[e][1] + dp[e][2]) % mod;
	ans = (ans + mod) % mod;
	printf("%d\n", ans);

	return 0;
}