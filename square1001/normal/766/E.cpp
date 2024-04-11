#include <vector>
#include <iostream>
using namespace std;
int n, a, b, x[100009], s[100009], dp[100009][22]; vector<int> G[100009], child[100009];
void rec(int pos, int pre) {
	s[pos] = 1;
	for (int j = 0; j < 20; j++) {
		if (x[pos] & (1 << j)) dp[pos][j]++;
	}
	for (int i : G[pos]) {
		if (i == pre) continue;
		rec(i, pos);
		child[pos].push_back(i);
		for (int j = 0; j < 20; j++) {
			if (x[pos] & (1 << j)) dp[pos][j] += s[i] - dp[i][j];
			else dp[pos][j] += dp[i][j];
		}
		s[pos] += s[i];
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b; a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rec(0, -1);
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 20; j++) {
			int sum2 = 0;
			for (int k : child[i]) sum2 += s[k] - dp[k][j];
			long long r = 0, p = 1LL * (s[i] - 1) * (s[i] - 2);
			for (int k : child[i]) {
				r += 1LL * dp[k][j] * (sum2 - s[k] + dp[k][j]);
				p -= 1LL * s[k] * (s[k] - 1);
			}
			if (x[i] & (1 << j)) r = p / 2 - r;
			ret += r << j;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 20; j++) {
			ret += (1LL * dp[i][j]) << j;
		}
	}
	cout << ret << endl;
	return 0;
}