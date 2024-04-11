#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m, x, y; ll p;
int main() {
	cin >> n >> m >> p >> x >> y; x--, y--;
	vector<int> r;
	if (n == 1) r = { 0 };
	else {
		for (int i = 0; i < n - 1; i++) r.push_back(i);
		for (int i = n - 1; i > 0; i--) r.push_back(i);
	}
	vector<vector<ll> > cnt(n, vector<ll>(m));
	for (int i : r) {
		for (int j = 0; j < m; j++) {
			cnt[i][j] += p / (r.size() * m);
		}
	}
	p %= r.size() * m;
	int c = 0;
	for (int i : r) {
		for (int j = 0; j < m; j++) {
			if (c++ < p) cnt[i][j]++;
		}
	}
	ll p1 = -1LL << 60, p2 = 1LL << 60;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			p1 = max(p1, cnt[i][j]);
			p2 = min(p2, cnt[i][j]);
		}
	}
	cout << p1 << ' ' << p2 << ' ' << cnt[x][y] << endl;
	return 0;
}