#include <cstdio>

const int N = 1100005;
int tot, lst, n, l[15], r[15], ch[N][26], nxt[N], ma[N], dp[N][12], enxt[N], fst[N];
char in[N];

void extend(int c) {
	int np = ++tot, p = lst;
	ma[np] = ma[lst] + 1;
	for (; p && !ch[p][c]; p = nxt[p]) ch[p][c] = np;
	if (!p) nxt[np] = 1;
	else {
		int q = ch[p][c];
		if (ma[q] == ma[p] + 1) nxt[np] = q;
		else {
			int nq = ++tot;
			ma[nq] = ma[p] + 1;
			for (int i = 0; i <= n; i++) dp[nq][i] = 0;
			for (int i = 0; i < 26; i++) ch[nq][i] = ch[q][i];
			nxt[nq] = nxt[q];
			nxt[q] = nxt[np] = nq;
			for (; p && ch[p][c] == q; p = nxt[p]) ch[p][c] = nq;
		}
	}
	lst = np;
}

void dfs(int u) {
	for (int i = fst[u]; i; i = enxt[i]) {
		dfs(i);
		for (int j = 0; j <= n; j++)
			dp[u][j] += dp[i][j];
	}
}

int main() {
	scanf("%s", in);
	l[0] = 1, r[0] = 0x3f3f3f3f;
	tot = 1;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		if (i) scanf("%s%d%d", in, l + i, r + i);
		lst = 1;
		for (int j = 0; in[j]; j++) {
			extend(in[j] - 'a');
			dp[lst][i]++;
		}
	}
	for (int i = 2; i <= tot; i++)
		enxt[i] = fst[nxt[i]], fst[nxt[i]] = i;
	dfs(1);
	long long ans = 0;
	for (int i = 2; i <= tot; i++) {
		bool flag = true;
		for (int j = 0; j <= n; j++)
			if (!(l[j] <= dp[i][j] && dp[i][j] <= r[j])) { flag = false; break; }
		if (flag) ans += ma[i] - ma[nxt[i]];
	}
	printf("%lld\n", ans);
	return 0;
}