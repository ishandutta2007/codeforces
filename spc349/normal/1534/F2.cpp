#include <bits/stdc++.h>
#define ID(x, y) (x * m + y)
using namespace std;

vector <string> s;
int a[400010];
int dp[400010], vis[400010], has[400010], alive[400010];
vector <int> from[400010], G[400010], GG[400010], trans[400010];
int n, m;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int dfn[400010], low[400010], TOT, ins[400010], ALL, scc[400010], in[400010];
int L[400010], R[400010], b[400010];
vector <int> mst;
vector <int> S;
vector <int> ord;

void chmin(int &x, int y) {
	x = min(x, y);
}

void chmax(int &x, int y) {
	x = max(x, y);
}

bool IN(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void AddEdge(int x, int y, int id) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if (IN(xx, yy) && s[xx][yy] == '#') from[id].push_back(ID(xx, yy));
	}
}

void Tarjan(int x) {
	dfn[x] = low[x] = ++TOT, ins[x] = 1, S.push_back(x);
	for (auto v : from[x]) {
		if (!dfn[v]) Tarjan(v), low[x] = min(low[x], low[v]);
		else if (ins[v]) low[x] = min(low[x], dfn[v]);
	}
	if (dfn[x] != low[x]) return ;
	while (1) {
		int v = S.back(); S.pop_back(), ins[v] = 0;
		scc[v] = ALL;
		if (v == x) break;
	}
	ALL++;
}

void GenInput() {
	srand(10);
	n = 100, m = 500;
	for (int i = 0; i < n; i++) {
		s.push_back("");
		for (int j = 0; j < m; j++) {
			s.back().push_back(char(rand() % 5 ? '.' : '#'));
			a[j] += s.back().back() == '#';
		}
	}
//	for (int i = 0; i < n; i++) cout << s[i] << endl;
//	for (int j = 0; j < m; j++) cout << a[j] << " "; cout << endl;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		s.push_back("");
		cin >> s.back();
	}
	for (int i = 0; i < m; i++) cin >> a[i];
//	GenInput();
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (s[i][j] == '#') {
				int cur = i - 1;
				do {
					cur++;
					AddEdge(cur, j, ID(i, j));
				} while (cur + 1 < n && s[cur + 1][j] != '#');
			}
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (s[i][j] == '#') {
		int x = ID(i, j);
		if (!dfn[x]) Tarjan(x);
	}
	for (int i = 0; i < n * m; i++) for (auto v : from[i]) if (scc[i] != scc[v]) {
		G[scc[i]].push_back(scc[v]), GG[scc[v]].push_back(scc[i]), in[scc[v]]++;
	}
//	int ans = 0;
	for (int i = 0; i < ALL; i++) if (!in[i]) ord.push_back(i);//, ans++, vis[i] = 1;
	for (int it = 0; it < ord.size(); it++) {
		int x = ord[it];
		for (auto v : G[x]) {
			in[v]--;
			if (!in[v]) ord.push_back(v);
		}
	}
	for (int j = 0; j < m; j++) {
		int i = n;
		while (a[j]) i--, a[j] -= s[i][j] == '#';
		b[j] = i;
	}
	for (int i = 0; i < ALL; i++) L[i] = 0x3f3f3f3f, R[i] = -1;
	for (int j = 0; j < m; j++) {
		int cnt = (j && b[j - 1] < b[j]) + (j + 1 < m && b[j + 1] <= b[j]);
		if (cnt == 0 && b[j] != n) {
			has[scc[ID(b[j], j)]] = 1, mst.push_back(j);
		}
	}
	for (auto x : ord) for (auto v : GG[x]) has[x] = min(2, has[x] + has[v]);
	for (auto j : mst) if (has[scc[ID(b[j], j)]] == 1) {
		alive[j] = 1, chmin(L[scc[ID(b[j], j)]], j), chmax(R[scc[ID(b[j], j)]], j);
	}
	for (int it = (int)ord.size() - 1; it >= 0; it--) {
		int x = ord[it];
		for (auto v : G[x]) {
			L[x] = min(L[x], L[v]);
			R[x] = max(R[x], R[v]);
		}
//		cerr << "          L:" << L[x] << " " << R[x] << endl;
		if (R[x] != -1) trans[L[x]].push_back(R[x]);
	}
//	for (auto x : qwq) {
//		cerr << "  x:" << x << endl;
//		for (int i = 0; i < ALL; i++) {
//			if (i == scc[ID(b[x], x)]) continue;
//			cerr << "    i:" << i << endl;
//			assert(L[i] > x || R[i] < x);
//		}
//	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	int maxj = -1;
	for (int i = 0; i < m; i++) {
		if (!alive[i]) chmin(dp[i + 1], dp[i]);
		for (auto x : trans[i]) maxj = max(maxj, x);
		if (maxj >= i) chmin(dp[maxj + 1], dp[i] + 1);
	}
	cout << dp[m] << endl;
//	assert(dp[m] == ans);
	return 0;
}