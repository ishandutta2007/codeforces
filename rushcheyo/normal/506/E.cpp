#include <bits/stdc++.h>
using namespace std;

const int N = 200, S = 1500, P = 10007;

int n, m, goal, dp[S + 1][N + 5][N + 5], tmp[N + 5][N + 5], f[S / 2], g[S];
vector<int> x, y;
char s[N + 5];

void add(int &x, int y) { x = (x + y) % P; }

int power(int a, int x) {
	int ans = 1;
	for (; x; x >>= 1, a = a * a % P)
		if (x & 1) ans = ans * a % P;
	return ans;
}

vector<int> BM(const vector<int> &x) {
	vector<int> cur, ls;
	int lf, ld;
	for (int i = 0; i < x.size(); ++i) {
		int t = -x[i];
		for (int j = 0; j < cur.size(); ++j)
			t = (t + cur[j] * x[i - 1 - j]) % P;
		if (!t) continue;
		if (cur.empty()) {
			cur.resize(i + 1); lf = i; ld = t;
			continue;
		}
		int k = -t * power(ld, P - 2) % P;
		vector<int> c(i - 1 - lf);
		c.push_back(-k);
		for (int j = 0; j < ls.size(); ++j) c.push_back(k * ls[j] % P);
		if (c.size() < cur.size()) c.resize(cur.size());
		for (int j = 0; j < cur.size(); ++j) c[j] = (c[j] + cur[j]) % P;
		if (c.size() > cur.size()) ls = cur, lf = i, ld = t;
		cur = c;
	}
	for (int &x : cur) x = (x + P) % P;
	return cur;
}

void solve(int n) {
	if (n < m) {
		f[n] = 1;
		return;
	}
	solve(n >> 1);
	fill(g, g + 2 * m - 1, 0);
	for (int i = 0; i < m; ++i)
		if (f[i]) for (int j = 0; j < m; ++j)
			g[i + j] = (g[i + j] + f[i] * f[j]) % P;
	for (int i = 2 * m - 2; i >= m; --i)
		if (g[i]) for (int j = 0; j < m; ++j)
			g[i - 1 - j] = (g[i - 1 - j] + g[i] * y[j]) % P;
	copy(g, g + m, f);
	if (n & 1)
		for (int i = m - 1, tmp = f[m - 1]; i >= 0; --i)
			f[i] = ((i ? f[i - 1] : 0) + tmp * y[m - 1 - i]) % P;
}

int main() {
	scanf("%s%d", s + 1, &goal);
	n = strlen(s + 1);
	dp[0][0][n + 1] = 1;
	for (int i = 1; i <= S + 1; ++i) {
		memset(tmp, 0, sizeof tmp);
		int res0 = 0, res1 = 0;
		for (int j = 0; j <= n; ++j)
			for (int k = n + 1; k; --k)
				if (dp[i - 1][j][k]) {
					if (j >= k - 1) add(res0, dp[i - 1][j][k]);
					add(tmp[j][k], dp[i - 1][j][k] * 25);
					add(tmp[j + (j < n)][k], dp[i - 1][j][k]);
					if (i > S) continue;
					if (j == n) {
						if (k == 1) add(dp[i][j][k], dp[i - 1][j][k] * 26);
						else {
							add(dp[i][j][k], dp[i - 1][j][k] * 25);
							add(dp[i][j][k - 1], dp[i - 1][j][k]);
						}
					} else {
						if (k == 1) {
							add(dp[i][j][k], dp[i - 1][j][k] * 25);
							add(dp[i][j + 1][k], dp[i - 1][j][k]);
						} else if (s[j + 1] == s[k - 1]) {
							add(dp[i][j][k], dp[i - 1][j][k] * 25);
							add(dp[i][j + 1][k - 1], dp[i - 1][j][k]);
						} else {
							add(dp[i][j][k], dp[i - 1][j][k] * 24);
							add(dp[i][j + 1][k], dp[i - 1][j][k]);
							add(dp[i][j][k - 1], dp[i - 1][j][k]);
						}
					}
				}
		for (int j = 0; j <= n; ++j)
			for (int k = j + 1; k; --k)
				add(res1, tmp[j][k]);
		x.push_back(res0), x.push_back(res1);
	}
	y = BM(x);
	m = y.size();
	solve(goal + n);
	int res = 0;
	for (int i = 0; i < m; ++i) res = (res + f[i] * x[i]) % P;
	printf("%d\n", (res + P) % P);
}