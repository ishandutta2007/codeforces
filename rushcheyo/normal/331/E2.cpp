#include <bits/stdc++.h>
using namespace std;

const int N = 55, M = N * N, P = 1000000007;
int n, m, u[M], v[M], g[N][N], good[N][N][2 * N], half[N][N][2 * N], trans[2][2][N][N][2 * N], dp[2][N][2 * N];
tuple<int, int, int> pre[2][N][2 * N];
vector<int> seq[M], goodv[N][N][2 * N], halfv[N][N][2 * N], transv[2][2][N][N][2 * N];

bool find(int &now, vector<int> &ind, bool c) {
	int cnt = 0;
	for (; cnt != ind.size(); ++cnt) {
		int nxt = ind[cnt];
		if (ind.size() > 2 * n || !g[now][nxt] || g[now][nxt] % 2 != c) return false;
		for (int x : seq[g[now][nxt]]) ind.push_back(x);
		now = nxt;
	}
	return true;
}
void get(bool c) {
	for (int i = 1; i <= m; ++i)
		for (int j = 0; j < seq[i << 1 | c].size(); ++j)
			if (seq[i << 1 | c][j] == u[i << 1 | c]) {
				vector<int> tmp1(j);
				reverse_copy(seq[i << 1 | c].begin(), seq[i << 1 | c].begin() + j, tmp1.begin());
				int now = u[i << 1 | c];
				if (find(now, tmp1, c ^ 1)) {
					if (j + 1 == seq[i << 1 | c].size()) {
						++half[now][v[i << 1 | c]][tmp1.size() + 1];
						halfv[now][v[i << 1 | c]][tmp1.size() + 1] = tmp1;
						reverse(halfv[now][v[i << 1 | c]][tmp1.size() + 1].begin(), halfv[now][v[i << 1 | c]][tmp1.size() + 1].end());
						halfv[now][v[i << 1 | c]][tmp1.size() + 1].push_back(u[i << 1 | c]);
					}
					else if (seq[i << 1 | c][j + 1] == v[i << 1 | c]) {
						vector<int> tmp2(seq[i << 1 | c].begin() + j + 2, seq[i << 1 | c].end());
						int nxt = v[i << 1 | c];
						if (find(nxt, tmp2, c)) {
							++good[now][nxt][tmp1.size() + tmp2.size() + 1];
							goodv[now][nxt][tmp1.size() + tmp2.size() + 1] = tmp1;
							reverse(goodv[now][nxt][tmp1.size() + tmp2.size() + 1].begin(), goodv[now][nxt][tmp1.size() + tmp2.size() + 1].end());
							goodv[now][nxt][tmp1.size() + tmp2.size() + 1].push_back(u[i << 1 | c]);
							goodv[now][nxt][tmp1.size() + tmp2.size() + 1].push_back(v[i << 1 | c]);
							for (int x : tmp2) goodv[now][nxt][tmp1.size() + tmp2.size() + 1].push_back(x);
						}
					}
				}
			}
}

int main() {
	cin >> n >> m;
	for (int i = 1, k; i <= m; ++i) {
		cin >> u[i << 1] >> v[i << 1] >> k;
		u[i << 1 | 1] = v[i << 1], v[i << 1 | 1] = u[i << 1];
		seq[i << 1].resize(k);
		for (int j = 0; j < k; ++j) cin >> seq[i << 1][j];
		seq[i << 1 | 1].resize(k);
		reverse_copy(seq[i << 1].begin(), seq[i << 1].end(), seq[i << 1 | 1].begin());
		g[u[i << 1]][v[i << 1]] = i << 1;
		g[v[i << 1]][u[i << 1]] = i << 1 | 1;
		if (!k) trans[0][0][u[i << 1]][v[i << 1]][1] = 1;
	}
	get(0);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= 2 * n; ++k) {
				trans[1][1][i][j][k] = good[i][j][k];
				transv[1][1][i][j][k] = goodv[i][j][k];
				trans[1][0][i][j][k] = half[i][j][k], half[i][j][k] = 0;
				transv[1][0][i][j][k] = halfv[i][j][k], halfv[i][j][k].clear();
			}
	get(1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= 2 * n; ++k) {
				trans[0][1][i][j][k] = half[j][i][k], transv[0][1][i][j][k] = halfv[j][i][k];
				reverse(transv[0][1][i][j][k].begin(), transv[0][1][i][j][k].end());
			}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= 2 * n; ++k)
				for (int t = 0; t < 2; ++t)
					if (trans[1][t][i][j][k])
						pre[t][j][k] = make_tuple(0, i, 0), dp[t][j][k] = (dp[t][j][k] + trans[1][t][i][j][k]) % P;
	for (int k = 1; k < 2 * n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int p = 0; p < 2; ++p)
				if (dp[p][i][k])
					for (int q = 0; q < 2; ++q)
						for (int j = 1; j <= n; ++j)
							for (int l = 1; k + l <= 2 * n; ++l)
								if (trans[p ^ 1][q][i][j][l])
									pre[q][j][k + l] = make_tuple(p, i, k), dp[q][j][k + l] = (dp[q][j][k + l] + 1ll * dp[p][i][k] * trans[p ^ 1][q][i][j][l]) % P;
	for (int l = 1; l <= 2 * n; ++l) {
		int sum = 0;
		for (int j = 1; j <= n; ++j)
			sum = (sum + dp[1][j][l]) % P;
		cout << sum << '\n';
	}
}