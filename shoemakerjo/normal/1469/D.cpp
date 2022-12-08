#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

int n;

void solve() {
	cin >> n;
	set<int> keep;
	int cur = n;
	while (cur > 2) {
		keep.insert(cur);
		cur = round(ceil(sqrt(cur)));
	}
	vector<pii> res;
	for (int i = 3; i <= n; i++) {
		if (keep.count(i) == 0) res.push_back({i, n}); //get it to be a 1
	}
	vector<int> vals;
	for (int vv : keep) vals.push_back(vv);
	reverse(vals.begin(), vals.end());
	for (int i = 0; i < vals.size()-1; i++) {
		res.push_back(pii(vals[i], vals[i+1]));
		res.push_back(pii(vals[i], vals[i+1]));
	}
	res.push_back(pii(vals[vals.size()-1], 2));
	res.push_back(pii(vals[vals.size()-1], 2));

	cout << res.size() << endl;
	for (pii vp : res) {
		cout << vp.first << " " << vp.second << endl;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}