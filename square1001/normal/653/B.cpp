#include <string>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m; string a[44], b[44];
int solve(int depth, string cur) {
	if (depth == 0) return 1;
	int ret = 0;
	for (int i = 0; i < m; i++) {
		if (cur[0] == b[i][0]) {
			ret += solve(depth - 1, a[i] + cur.substr(1));
		}
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
	cout << solve(n - 1, "a") << endl;
	return 0;
}