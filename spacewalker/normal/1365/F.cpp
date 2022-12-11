#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> getYeetList(vector<int> &arr) {
	vector<pair<int, int>> ans;
	int n = arr.size();
	for (int i = 0; i < n - 1 - i; ++i) {
		int x = arr[i], y = arr[n-1-i];
		if (x > y) swap(x, y);
		ans.emplace_back(x, y);
	}
	sort(begin(ans), end(ans));
	return ans;
}

bool solve() {
	int n; scanf("%d", &n);
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	if (n % 2 == 1 && a[n/2] != b[n/2]) return false;
	return getYeetList(a) == getYeetList(b);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) printf("%s\n", solve() ? "Yes" : "No");
	return 0;
}