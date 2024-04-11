#include <set>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> ax(n), ay(n), bx(m), by(m);
	for (int i = 0; i < n; ++i) cin >> ax[i] >> ay[i];
	for (int i = 0; i < m; ++i) cin >> bx[i] >> by[i];
	vector<set<int> > ad(n), bd(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!((ax[i] == bx[j] && ay[i] == by[j]) || (ax[i] == by[j] && ay[i] == bx[j]))) {
				if (ax[i] == bx[j]) {
					ad[i].insert(ax[i]);
					bd[j].insert(bx[j]);
				}
				if (ax[i] == by[j]) {
					ad[i].insert(ax[i]);
					bd[j].insert(by[j]);
				}
				if (ay[i] == bx[j]) {
					ad[i].insert(ay[i]);
					bd[j].insert(bx[j]);
				}
				if (ay[i] == by[j]) {
					ad[i].insert(ay[i]);
					bd[j].insert(by[j]);
				}
			}
		}
	}
	int las = -1; bool zero = true;
	set<int> fin;
	for (int i = 0; i < n; ++i) {
		if (ad[i].size() >= 2) zero = false;
		fin.insert(ad[i].begin(), ad[i].end());
	}
	for (int i = 0; i < m; ++i) {
		if (bd[i].size() >= 2) zero = false;
	}
	if (zero) cout << (fin.size() == 1 ? *fin.begin() : 0) << endl;
	else cout << -1 << endl;
	return 0;
}