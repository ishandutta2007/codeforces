#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[200009]; bool used[200009]; string s, t;
bool solve(int x) {
	fill(used, used + n, true);
	for (int i = 0; i < x; i++) used[a[i]] = false;
	int cur = 0;
	for (int i = 0; i < n && cur < m; i++) {
		if (used[i] && s[i] == t[cur]) cur++;
	}
	return cur == m;
}
int main() {
	cin >> s >> t; n = s.size(); m = t.size();
	for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
	int l = 0, r = n;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (solve(m)) l = m;
		else r = m;
	}
	cout << l << endl;
	return 0;
}