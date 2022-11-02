#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a; bool used[200009];
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int inv(int x, int m) {
	return x >= 2 ? m - 1LL * inv(m % x, x) * m / x : 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	fill(used, used + m, true);
	for (int i = 0; i < n; i++) cin >> a, used[a] = false;
	vector<int> d;
	for (int i = 1; i <= m; i++) {
		if (m % i == 0) d.push_back(i);
	}
	vector<vector<int> > w(d.size());
	for (int i = 0; i < m; i++) {
		if (!used[i]) continue;
		int ptr = -1;
		for (int j = 0; j < d.size(); j++) {
			if (i % d[j] == 0) ptr = j;
		}
		w[ptr].push_back(i);
	}
	vector<int> dp(d.size());
	for (int i = 0; i < d.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (d[i] % d[j] == 0) dp[i] = max(dp[i], dp[j]);
		}
		dp[i] += w[i].size();
	}
	vector<int> path = { (int)d.size() - 1 };
	int pos = d.size() - 1;
	while (pos != 0) {
		int ptr = -1;
		for (int i = 0; i < pos; i++) {
			if (d[pos] % d[i] == 0 && (ptr == -1 || dp[ptr] < dp[i])) {
				ptr = i;
			}
		}
		path.push_back(ptr);
		pos = ptr;
	}
	vector<int> seq = { 1 };
	for (int i = path.size() - 1; i >= 0; i--) {
		seq.insert(seq.end(), w[path[i]].begin(), w[path[i]].end());
	}
	cout << seq.size() - 1 << endl;
	for (int i = 1; i < seq.size(); i++) {
		int g = gcd(seq[i - 1], m);
		cout << 1LL * inv(seq[i - 1] / g, m / g) * seq[i] / g % m << ' ';
	}
	return 0;
}