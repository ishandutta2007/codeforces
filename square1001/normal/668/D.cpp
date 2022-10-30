#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	vector<int> tp(q), t(q), x(q);
	map<int, vector<int> > d;
	for (int i = 0; i < q; ++i) {
		cin >> tp[i] >> t[i] >> x[i];
		d[x[i]].push_back(i);
	}
	vector<int> ans(q);
	for (pair<int, vector<int> > i : d) {
		vector<int> v = i.second;
		vector<int> ct(v.size());
		for (int j = 0; j < v.size(); ++j) {
			ct[j] = t[v[j]];
		}
		sort(ct.begin(), ct.end()); // it is guaranteed that all t's are distinct
		for (int j = 0; j < v.size(); ++j) {
			t[v[j]] = lower_bound(ct.begin(), ct.end(), t[v[j]]) - ct.begin();
		}
		vector<int> bit(v.size() + 1);
		for (int j = 0; j < v.size(); ++j) {
			if (tp[v[j]] != 3) {
				for (int k = t[v[j]] + 1; k <= v.size(); k += k & (-k)) {
					bit[k] += (tp[v[j]] == 1 ? 1 : -1);
				}
			}
			else {
				for (int k = t[v[j]]; k >= 1; k -= k & (-k)) {
					ans[v[j]] += bit[k];
				}
			}
		}
	}
	for (int i = 0; i < q; ++i) {
		if (tp[i] == 3) {
			cout << ans[i] << '\n';
		}
	}
	return 0;
}