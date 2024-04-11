#include <vector>
#include <iostream>
using namespace std;
vector<vector<int> > solve(int n, int m, int delta) {
	vector<vector<int> > ans(n, vector<int>(m));
	int cur = delta, ofs = delta;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans[i][j] = cur;
			cur += delta;
			if (cur > n * m) --ofs, cur = ofs;
		}
	}
	return ans;
}
bool adj(int n, int m, int x, int y) {
	if (x > y) swap(x, y);
	if (y - x == m) return true;
	if (y - x == 1 && x % m != 0) return true;
	return false;
}
bool check(int n, int m, vector<vector<int> > ans) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			if (adj(n, m, ans[i][j], ans[i][j + 1])) return false;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			if (adj(n, m, ans[i][j], ans[i + 1][j])) return false;
		}
	}
	return true;
}
vector<vector<int> > calc(int n, int m) {
	if (n == 2 && m == 4) return{ {5, 4, 7, 2}, {3, 6, 1, 8} };
	if (n == 2 && m == 5) return{ {1, 3, 5, 7, 9}, {8, 10, 2, 4, 6} };
	if (n == 4 && m == 2) return{ {1, 5}, {6, 2}, {3, 7}, {8, 4} };
	if (n == 3 && m == 3) return{ {2, 9, 4}, {7, 5, 3}, {6, 1, 8} };
	for (int i = 1; i <= 50 && i <= n * m; ++i) {
		vector<vector<int> > ans = solve(n, m, i);
		if (check(n, m, ans)) {
			return ans;
		}
	}
	return vector<vector<int> >();
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > ans = calc(n, m);
	cout << (ans.empty() ? "NO\n" : "YES\n");
	if (!ans.empty()) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (j) cout << ' ';
				cout << ans[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}