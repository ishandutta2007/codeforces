#include <vector>
#include <iostream>
using namespace std;
long long dx[] = { 1, 0, -1, 0 };
long long dy[] = { 0, 1, 0, -1 };
int n, a, b; long long x[33], y[33]; vector<int> G[33];
void build(int pos, int pre, int d, int prevd) {
	vector<int> valid;
	for (int i = 0; i < 4; i++) {
		if ((i + 2) % 4 != prevd) valid.push_back(i);
	}
	int cnt = 0;
	for (int i : G[pos]) {
		if (i == pre) continue;
		x[i] = x[pos] + (dx[valid[cnt]] << (n - d));
		y[i] = y[pos] + (dy[valid[cnt]] << (n - d));
		build(i, pos, d + 1, valid[cnt++]);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b; a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (G[i].size() >= 5) flag = false;
	}
	if (!flag) cout << "NO" << endl;
	else {
		build(0, -1, 0, -1);
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << x[i] << ' ' << y[i] << endl;
		}
	}
	return 0;
}