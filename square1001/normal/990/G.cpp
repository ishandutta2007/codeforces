#include <vector>
#include <iostream>
using namespace std;
const int vallim = 200000;
int n, a[200009]; long long ans[200009]; bool inc[200009], vis[200009]; vector<int> g[200009], v[200009];
pair<long long, int> calc(int pos, int pre) {
	vis[pos] = true;
	long long sumsqr = 0, cursum = 0; int nodes = 1;
	for (int i : g[pos]) {
		if (i == pre || vis[i] || !inc[i]) continue;
		pair<long long, int> res = calc(i, pos);
		cursum += res.first;
		nodes += res.second;
		sumsqr += 1LL * res.second * res.second;
	}
	cursum += (1LL * (nodes - 1) * (nodes - 1) - sumsqr) / 2 + nodes;
	return make_pair(cursum, nodes);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 1; j * j <= a[i]; ++j) {
			if (a[i] % j == 0) {
				v[j].push_back(i);
				if (j * j != a[i]) v[a[i] / j].push_back(i);
			}
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		int vx, vy;
		cin >> vx >> vy; --vx, --vy;
		g[vx].push_back(vy);
		g[vy].push_back(vx);
	}
	for (int i = 1; i <= vallim; ++i) {
		for (int j : v[i]) inc[j] = true;
		for (int j : v[i]) {
			if (!vis[j]) {
				ans[i] += calc(j, -1).first;
			}
		}
		for (int j : v[i]) inc[j] = vis[j] = false;
	}
	for (int i = vallim; i >= 1; --i) {
		for (int j = i * 2; j <= vallim; j += i) {
			ans[i] -= ans[j];
		}
	}
	for (int i = 1; i <= vallim; ++i) {
		if (ans[i] != 0) {
			cout << i << ' ' << ans[i] << '\n';
		}
	}
	return 0;
}