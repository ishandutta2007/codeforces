#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, a[100009], b[100009];
bool solve(int x) {
	vector<int> vis(m, -1), inv(x, -1);
	for (int i = 0; i < x; i++) {
		if (a[i] > 0) vis[a[i] - 1] = i;
	}
	for (int i = 0; i < m; i++) {
		if (vis[i] == -1) return false;
		inv[vis[i]] = i;
	}
	int sum = 0;
	for (int i = 0; i < x; i++) {
		if (inv[i] == -1) sum++;
		else {
			sum -= b[inv[i]];
			if (sum < 0) return false;
		}
	}
	return true;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	int l = 0, r = n;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (solve(mid)) r = mid;
		else l = mid;
	}
	if (!solve(n)) cout << -1 << endl;
	else cout << r << endl;
	return 0;
}