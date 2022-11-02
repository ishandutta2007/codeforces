#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = (1 << 30);
int n, p[300009]; string s[300009];
int solve(int l, int r) {
	vector<int> vr = { l }, vb = { l };
	for (int i = l + 1; i <= r; ++i) {
		if (s[i] == "R") vr.push_back(i);
		if (s[i] == "B") vb.push_back(i);
	}
	vr.push_back(r);
	vb.push_back(r);
	int mr = 0, mb = 0;
	for (int i = 1; i < vr.size(); ++i) mr = max(mr, p[vr[i]] - p[vr[i - 1]]);
	for (int i = 1; i < vb.size(); ++i) mb = max(mb, p[vb[i]] - p[vb[i - 1]]);
	return min(2LL * (p[r] - p[l]), 3LL * (p[r] - p[l]) - mr - mb);
}
int main() {
	cin >> n;
	vector<int> g;
	for (int i = 0; i < n; ++i) {
		cin >> p[i] >> s[i];
		if (s[i] == "G") g.push_back(i);
	}
	int firstr = inf, lastr = -inf;
	int firstb = inf, lastb = -inf;
	for (int i = 0; i < n; ++i) {
		if (s[i] == "R") {
			firstr = min(firstr, i);
			lastr = max(lastr, i);
		}
		if (s[i] == "B") {
			firstb = min(firstb, i);
			lastb = max(lastb, i);
		}
	}
	if (g.empty()) {
		cout << (firstr != inf ? p[lastr] - p[firstr] : 0) + (firstb != inf ? p[lastb] - p[firstb] : 0) << '\n';
	}
	else {
		int sum = (firstr < g.front() ? p[g.front()] - p[firstr] : 0) + (firstb < g.front() ? p[g.front()] - p[firstb] : 0) + (lastr > g.back() ? p[lastr] - p[g.back()] : 0) + (lastb > g.back() ? p[lastb] - p[g.back()] : 0);
		for (int i = 1; i < g.size(); ++i) {
			sum += solve(g[i - 1], g[i]);
		}
		cout << sum << '\n';
	}
	return 0;
}