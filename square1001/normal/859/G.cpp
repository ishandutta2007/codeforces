#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool solve(vector<int> ps, vector<int> v) {
	if (ps.empty()) return v[0] == 0;
	int n = v.size();
	vector<int> nps(ps.begin() + 1, ps.end());
	vector<vector<int> > g(ps[0], vector<int>(n / ps[0]));
	bool ans = true;
	for (int i = 0; i < n; ++i) {
		g[i % ps[0]][i % (n / ps[0])] = v[i];
	}
	for (int i = 1; i < ps[0]; ++i) {
		for (int j = 0; j < n / ps[0]; ++j) {
			g[i][j] -= g[0][j];
		}
		if (!solve(nps, g[i])) ans = false;
	}
	return ans;
}
int main() {
	int N; string S;
	cin >> N >> S;
	vector<int> ps;
	int rad = 1, x = N;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			rad *= i;
			ps.push_back(i);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) rad *= x, ps.push_back(x);
	bool ans = true;
	for (int i = 0; i < N / rad; ++i) {
		vector<int> v;
		for (int j = i; j < N; j += N / rad) {
			v.push_back(S[j] - '0');
		}
		bool res = solve(ps, v);
		if (!res) ans = false;
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}