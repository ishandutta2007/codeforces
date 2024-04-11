#include <bits/stdc++.h>
using namespace std;

const int K = 3;
const int L = 1 << K;

const int INF = 2e8;

int mn[L];

char s[1010];

int type() {
	int rlt = 0;
	int sz = strlen(s);
	for (int i = 0; i < sz; i ++) {
		rlt |= (1 << (s[i] - 'A'));
	}
	return rlt;
}

int ans;

void check(int x) {
	ans = min(ans, mn[x]);
}

void check(int x, int y) {
	ans = min(ans, mn[x] + mn[y]);
}

void check(int x, int y, int z) {
	ans = min(ans, mn[x] + mn[y] + mn[z]);
}

int main() {
	//freopen("r.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < L; i ++) mn[i] = INF;
	for (int i = 1, c; i <= n; i ++) {
		scanf("%d %s", &c, s);
		int t = type();
		mn[t] = min(mn[t], c);
	}
	ans = INF;
	check(7);
	for (int i = 0; i < L; i ++) for (int j = i + 1; j < L; j ++) if ((i | j) == 7) check(i, j);
	for (int i = 0; i < L; i ++) for (int j = i + 1; j < L; j ++) for (int k = j + 1; k < L; k ++) if (((i | j) | k) == 7) check(i, j, k);
	if (ans == INF) puts("-1");
	else printf("%d\n", ans);


	return 0;
}