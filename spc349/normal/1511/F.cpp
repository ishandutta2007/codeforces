#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int son[50][26], bck[50], TOT = 1;
int A[210][210], N, ans[210][210], tmp[210][210];

void dfs(int x, int y, int d, int id) {
	if (d == 0) {
		if (bck[x]) A[id][y * 5]++;
		if (bck[y]) A[id][x * 5]++;
		if (bck[x] && bck[y]) A[id][0]++;
		return ;
	}
	for (int i = 0; i < 26; i++) {
		if (son[x][i] != -1 && son[y][i] != -1) dfs(son[x][i], son[y][i], d - 1, id);
	}
}

int main() {
	memset(son, -1, sizeof(son));
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int now = 0;
		for (auto x : s) now = ~son[now][x - 'a'] ? son[now][x - 'a'] : son[now][x - 'a'] = TOT++;
		bck[now] = 1;
	}
	N = TOT * 5;
	for (int i = 0; i < TOT; i++) {
		for (int j = 0; j < 5; j++) {
			if (j < 4) A[i * 5 + j][i * 5 + j + 1]++;
			dfs(0, i, j + 1, i * 5 + j);
		}
	}
	for (int i = 0; i < N; i++) ans[i][i] = 1;
	for (int it = 0; it < 30; it++) {
		if (m >> it & 1) {
			for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
				long long qwq = 0;
				for (int k = 0; k < N; k++) {
					qwq += 1ll * A[i][k] * ans[k][j];
					if ((N - k - 1 & 7) == 0) qwq %= mod;
				}
				tmp[i][j] = qwq;
			}
			for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ans[i][j] = tmp[i][j];
		}
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			long long qwq = 0;
			for (int k = 0; k < N; k++) {
				qwq += 1ll * A[i][k] * A[k][j];
				if ((N - k - 1 & 7) == 0) qwq %= mod;
			}
			tmp[i][j] = qwq;
		}
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) A[i][j] = tmp[i][j];
	}
	printf("%d\n", ans[0][0]);
	return 0;
}