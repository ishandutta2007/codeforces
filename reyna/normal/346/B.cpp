//In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 49;

int f[N], nxt[N][26], dp[N][N][N];
pair<int, pair<int, int>> par[N][N][N];

string s;

void update(int i1, int j1, int k1, int i2, int j2, int k2, int add) {
	if (dp[i1][j1][k1] < dp[i2][j2][k2] + add) {
		dp[i1][j1][k1] = dp[i2][j2][k2] + add;	
		par[i1][j1][k1] = {k2, {i2, j2}};
	}
}

void show(int i, int j, int k, int cnt = 0) {
	if (i == -1) {
		if (cnt == 0) {
			cout << 0;
		}
		return;
	}
	int ni = par[i][j][k].second.first, nj = par[i][j][k].second.second, nk = par[i][j][k].first;
	if (ni != -1 && i - ni == 1 && j - nj == 1) {
		show(ni, nj, nk, cnt + 1);
		cout << s[ni];	
	} else show(ni, nj, nk, cnt);
}

int main() {
	string t, virus; cin >> s >> t >> virus;
	int n = (int) s.size(), m = (int) t.size(), k = (int) virus.size();
	for (int i = 1; i < k; i++) {
		int state = f[i];
		while (state && virus[i] != virus[state])
			state = f[state];
		if (virus[state] == virus[i])
			state++;
		f[i + 1] = state;
	}
	for (int i = 0; i <= k; i++)
		for (int c = 'A'; c <= 'Z'; c++)
			if (i != k && virus[i] == c)
				nxt[i][c - 'A'] = i + 1;
			else
				nxt[i][c - 'A'] = nxt[f[i]][c - 'A'];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int r = 0; r < N; r++) {
				if (r) dp[i][j][r] = -1e9;
				par[i][j][r] = {-1, {-1, -1}};
			}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int state = 0; state < k; state++) {
				if (i < n && j < m && s[i] == t[j])
					update(i + 1, j + 1, nxt[state][s[i] - 'A'], i, j, state, 1);
				if (i < n) update(i + 1, j, state, i, j, state, 0);
				if (j < m) update(i, j + 1, state, i, j, state, 0);	
			}
		}
	}
	int mx = -1;
	for (int i = 0; i < k; i++)
		if (dp[n][m][i])
			mx = max(mx, dp[n][m][i]);
	if (mx <= 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < k; i++)
		if (dp[n][m][i] == mx) {
			show(n, m, i);
			return 0;
		}
}