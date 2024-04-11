#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, p[150009], c[150009]; double dp[150009]; vector<int> g[150009];
void rec(int pos) {
	c[pos] = 1;
	for (int i : g[pos]) {
		rec(i);
		c[pos] += c[i];
	}
}
void solve(int pos) {
	for (int i : g[pos]) {
		dp[i] = dp[pos] + (c[pos] - c[i] + 1) * 0.5;
		solve(i);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) scanf("%d", &p[i]), g[--p[i]].push_back(i);
	dp[0] = 1.0;
	rec(0);
	solve(0);
	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%.9lf", dp[i]);
	}
	printf("\n");
	return 0;
}