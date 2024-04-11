#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a; map<int, int> p, dp; map<int, bool> vis;
int solve(int bit) {
	if (bit <= 1) return 0;
	if (vis[bit]) return dp[bit];
	set<int> s;
	for (int i = 1; i < 30; i++) {
		int r = (bit & ((1 << i) - 1)) | (bit >> i);
		if (r != bit) s.insert(solve(r));
	}
	int ret = 0;
	while (s.count(ret)) ret++;
	vis[bit] = true; dp[bit] = ret;
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		map<int, int> q;
		for (int j = 2; j * j <= a; j++) {
			while (a % j == 0) q[j]++, a /= j;
		}
		if (a >= 2) q[a]++;
		for (pair<int, int> i : q) p[i.first] |= 1 << i.second;
	}
	int ret = 0;
	for (pair<int, int> i : p) ret ^= solve(i.second);
	cout << (ret ? "Mojtaba" : "Arpa") << endl;
	return 0;
}