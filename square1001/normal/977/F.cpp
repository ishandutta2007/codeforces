#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int hash_function(int z) {
	z ^= z << 13;
	z ^= z >> 17;
	z ^= z << 5;
	return z;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, a;
	cin >> n;
	unordered_map<int, int> d;
	vector<int> p(n), dp(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a;
		p[i] = d[hash_function(a - 1)] - 1;
		d[hash_function(a)] = i + 1;
		dp[i] = (p[i] == -1 ? 0 : dp[p[i]]) + 1;
	}
	int pos = max_element(dp.begin(), dp.end()) - dp.begin();
	vector<int> path;
	while (pos != -1) {
		path.push_back(pos);
		pos = p[pos];
	}
	cout << path.size() << '\n';
	for (int i = path.size() - 1; i >= 0; --i) {
		cout << path[i] + 1 << (i > 0 ? ' ' : '\n');
	}
	return 0;
}