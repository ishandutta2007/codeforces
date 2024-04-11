#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<int> &u, int cnt, int clen, vector<bool> &afro, vector<bool> &ok, vector<vector<int>> &es) {
	// cout << v / 3 << " " << v % 3 << " " << cnt << "\n";
	if (ok[v]) {
		// cout << "ok " << v << endl;
		afro[cnt % clen] = true;
	}
	for (int w : es[v]) {
		if (u[w]) continue;
		u[w] = -1;
		dfs(w, u, cnt + 1, clen, afro, ok, es);
	}
}

pair<int, int> go(int st, vector<int> &nxt, vector<int> &u, vector<vector<int>> &es, vector<bool> &ok) {
	// cout << "go " << st << endl;
	int v = st;
	u[v] = 1;
	vector<int> path = {st};
	while (!u[nxt[v]]) { u[nxt[v]] = u[v] + 1; v = nxt[v]; path.push_back(v); }
	int clen = u[v] - u[nxt[v]] + 1;

	vector<bool> afro(clen, false);
	for (int i = 0; i < (int)path.size(); i++) {
		dfs(path[i], u, (int)path.size() - i, clen, afro, ok, es);
	}
	int afro_sum = 0;
	for (bool a : afro) if (a) afro_sum++;
	// cout << "res: " << clen << " " << afro_sum << endl;
	return {clen, afro_sum};
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<bool> ok(n * m, false);
	vector<int> nxt(n * m);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '0') ok[i * m + j] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			int code = i * m + j;
			if (s[j] == 'L') nxt[code] = code - 1;
			if (s[j] == 'R') nxt[code] = code + 1;
			if (s[j] == 'D') nxt[code] = code + m;
			if (s[j] == 'U') nxt[code] = code - m;
		}
	}
	vector<vector<int>> es(n * m);
	for (int i = 0; i < n * m; i++) es[nxt[i]].push_back(i);
	vector<int> u(n * m, 0);
	int aa = 0, bb = 0;
	for (int i = 0; i < n * m; i++) {
		if (u[i]) continue;
		auto q = go(i, nxt, u, es, ok);
		aa += q.first;
		bb += q.second;
	}
	cout << aa << " " << bb << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}