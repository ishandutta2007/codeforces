#include <bits/stdc++.h>

using namespace std;

double v, ans;

void dfs(int n, double a, double b, double c, double p) {
	ans += n * c * p;
	if (fabs(a) > v && fabs(b) > v) {
		dfs(n + 1, a - v, b + v / 2, c + v / 2, p * a);
		dfs(n + 1, a + v / 2, b - v, c + v / 2, p * b);
	} else if (fabs(a) > 1e-8 && fabs(b) > v) {
		dfs(n + 1, 0, b + a / 2, c + a / 2, p * a);
		dfs(n + 1, a + v / 2, b - v, c + v / 2, p * b);
	} else if (fabs(a) <= 1e-8 && fabs(b) > v) {
		dfs(n + 1, 0, b - v, c + v, p * b);
	} else if (fabs(a) > v && fabs(b) > 1e-8) {
		dfs(n + 1, a - v, b + v / 2, c + v / 2, p * a);
		dfs(n + 1, a + b / 2, 0, c + b / 2, p * b);
	} else if (fabs(a) > 1e-8 && fabs(b) > 1e-8) {
		dfs(n + 1, 0, b + a / 2, c + a / 2, p * a);
		dfs(n + 1, a + b / 2, 0, c + b / 2, p * b);
	} else if (fabs(a) <= 1e-8 && fabs(b) > 1e-8) {
		dfs(n + 1, 0, 0, c + b, p * b);
	} else if (fabs(a) > v && fabs(b) <= 1e-8) {
		dfs(n + 1, a - v, 0, c + v, p * a);
	} else if (fabs(a) > 1e-8 && fabs(b) <= 1e-8) {
		dfs(n + 1, 0, 0, c + a, p * a);
	}
}

void solve() {
	double a, b, c;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &v);
	ans = 0;
	dfs(1, a, b, c, 1);
	printf("%.7lf\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}