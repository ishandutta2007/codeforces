#include <bits/stdc++.h>

using namespace std;

#define tii tuple<int, int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<tii> vals;
	int n;
	cin >> n;
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		vals.push_back(make_tuple(l, 0-r, i)); //if tie, sort starting on furthest r
	}
	sort(vals.begin(), vals.end());
	int maxr = -2;
	int mind = -2;
	int ans1 = -2, ans2 = -2;
	int ind;
	for (int i = 0; i < n; i++) {
		l = get<0>(vals[i]);
		r = 0-get<1>(vals[i]);
		ind = get<2>(vals[i]);
		if (maxr >= r) {
			ans1 = ind;
			ans2 = mind;
		}
		if (r > maxr) {
			maxr = r;
			mind = ind;
		}
	}

	cout << ans1+1 << " " << ans2+1 << endl;
	cin >> n;


}