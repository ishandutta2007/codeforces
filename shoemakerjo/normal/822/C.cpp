#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int ans = 2000000001;
	map<int, int> min_cost; //first index is duration, second is cost
	int l, r, cost;
	vector<tuple<int, int, int>> trips;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> l >> r >> cost;
		tuple<int, int, int> cur = make_tuple(l,r,cost);
		trips.push_back(cur);
		v.push_back(l);

	}
	sort(trips.begin(), trips.end());
	sort (v.begin(), v.end());
	map<int, vector<pair<int, int>>> updates;

	for (int i = 0; i < n; i++) {
		l = get<0>(trips[i]);
		r = get<1>(trips[i]);
		cost = get<2>(trips[i]);
		// cout << "i: " << i << " " << l << " " << r << " " << cost << endl;

		if (updates.count(l) > 0) {
			// cout << "here" << endl;
			for (int j = 0; j < updates[l].size(); j++) {
				int cdur = (updates[l][j]).first;
				int ccost = (updates[l][j]).second;
				// cout << "wow " << cdur << " " << ccost << endl;
				if (min_cost.count(cdur) == 0) {
					min_cost[cdur] = ccost;
				}
				else min_cost[cdur] = min(min_cost[cdur], ccost);
			}
			updates[l].clear();
		}
		int dur = r-l+1;
		if (min_cost.count(x-dur) > 0) {
			ans = min(ans, cost+min_cost[x-dur]);
		}
		int nextind = upper_bound(v.begin(), v.end(), r) - v.begin();
		if (nextind == v.size()) continue;
		if (updates.count(v[nextind]) > 0) {
			// cout << "werid" << endl;
			pair<int, int> p = make_pair(dur, cost);
			updates[v[nextind]].push_back(p);
		}
		else {
			// cout << "real: "<< v[nextind] << endl;
			vector<pair<int, int>> vp;
			pair<int, int> p = make_pair(dur, cost);
			vp.push_back(p);
			updates[v[nextind]] = vp;
		}
	}
	if (ans == 2000000001) cout << -1 << endl;
	else cout << ans << endl;
	// cin >> n;

}