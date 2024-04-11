#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	map<int, int> d;
	for (int i = 0; i < N; ++i) {
		++d[A[i]];
	}
	int B = 1;
	while ((B + 1) * (B + 1) <= N) ++B;
	vector<vector<int> > tbl(B + 1);
	for (pair<int, int> i : d) {
		tbl[min(i.second, B)].push_back(i.first);
	}
	vector<int> cap(B + 1);
	for (int i = 1; i <= B; ++i) {
		for (int j = 1; j <= B; ++j) {
			cap[i] += tbl[j].size() * min(j, i);
		}
	}
	int sel = -1, opt = -1;
	for (int i = 1; i <= B; ++i) {
		int s = cap[i] / i;
		if (i <= s && opt < i * s) {
			opt = i * s;
			sel = i;
		}
	}
	vector<int> gen;
	for (int i = B; i >= 1; --i) {
		for (int j : tbl[i]) {
			for (int k = 0; k < min(i, sel); ++k) {
				gen.push_back(j);
			}
		}
	}
	vector<vector<int> > ans(sel, vector<int>(opt / sel, -1));
	int x = 0, y = 0;
	for (int i = 0; i < opt; ++i) {
		if (ans[x][y] != -1) {
			x = (x + 1) % sel;
		}
		ans[x][y] = gen[i];
		x = (x + 1) % sel;
		y = (y + 1) % (opt / sel);
	}
	cout << opt << '\n';
	cout << sel << ' ' << opt / sel << '\n';
	for (int i = 0; i < sel; ++i) {
		for (int j = 0; j < opt / sel; ++j) {
			if (j) cout << ' ';
			cout << ans[i][j];
		}
		cout << '\n';
	}
	return 0;
}