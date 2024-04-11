#include <bits/stdc++.h>
using namespace std;

void go(int v, int pr, vector<vector<int>> &es, vector<int> &dr, vector<int> &db, int &ans) {
	int m1r = 0, m1b = 0, m2r = 0, m2b = 0;
	for (int w : es[v]) {
		if (w == pr) continue;
		go(w, v, es, dr, db, ans);

		if (max(dr[w], db[w]) > m2b) m2b = max(dr[w], db[w]);
		if (m2b > m1b) swap(m2b, m1b);
		if (dr[w] > m2r) m2r = dr[w];
		if (m2r > m1r) swap(m2r, m1r);
	}

	ans = max(ans, m1r + m2r + 1);
	ans = max(ans, m1b + m2b + max(0, (int)es[v].size() - 2));

	db[v] = m1r + 1;
	dr[v] = m1b + max(0, (int)es[v].size() - 1 - (int)(pr != -1));
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> es(n);
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}
	vector<int> dr(n, -1), db(n, -1);
	int ans = 1;

	go(0, -1, es, dr, db, ans);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 1;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}