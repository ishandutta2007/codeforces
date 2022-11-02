#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n), recs;
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (mx < a[i]) {
			mx = a[i];
			recs.push_back(i);
		}
	}
	int pos = -1, ans = 0; vector<int> lis;
	for (int i = 0; i < recs.size(); ++i) {
		int cmx = (i == 0 ? 0 : a[recs[i - 1]]);
		int nxt = (i == recs.size() - 1 ? n : recs[i + 1]);
		int incr = -1;
		for (int j = recs[i] + 1; j < nxt; ++j) {
			if (cmx < a[j]) {
				cmx = a[j];
				++incr;
			}
		}
		if (incr == 0) {
			lis.push_back(a[i]);
		}
		if (ans < incr) {
			ans = incr;
			pos = recs[i];
		}
	}
	int val = (pos == -1 ? (lis.size() >= 1 ? *min_element(lis.begin(), lis.end()) : 1 << 30) : a[pos]);
	if (pos == -1) {
		for (int i = 0; i < n; ++i) {
			bool found = false;
			for (int j : recs) {
				if (i == j) {
					found = true;
				}
			}
			if (!found) {
				val = min(val, a[i]);
			}
		}
		if (val == (1 << 30)) val = 1;
	}
	cout << val << '\n';
	return 0;
}