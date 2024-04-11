#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l, r;
	cin >> n;
	vector<int> vals;
	set<int> seen;
	vector<pii> spots;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		if (seen.count(l-1) == 0) {
			seen.insert(l-1);
			vals.push_back(l-1);
		}
		if (seen.count(l) == 0) {
			seen.insert(l);
			vals.push_back(l);
		}
		if (seen.count(r) == 0) {
			seen.insert(r);
			vals.push_back(r);
		}
		spots.push_back(pii(l, r));
	}
	sort(vals.begin(), vals.end());
	map<int, int> mp;
	for (int i = 0; i < vals.size(); i++) {
		mp[vals[i]] = i;
	}
	int diff[vals.size()+1];
	fill(diff, diff+vals.size()+1, 0);
	for (int i = 0; i < n; i++) {
		l = spots[i].first;
		r = spots[i].second;
		diff[mp[l]]++;
		diff[mp[r]+1]--;
	}
	int pref[vals.size()+10];
	int cd = diff[0];
	if (cd == 1) {
		pref[0] = 1;
	}
	else pref[0] = 0;
	for (int i = 1; i < vals.size(); i++) {
		// cout << "i   " << i << " " << vals[i] << endl;
		cd += diff[i];
		pref[i] = pref[i-1];
		if (cd == 1) {
			pref[i]++;
		}
	}
	bool found = false;
	for (int i = 0; i < n; i++) {
		l = spots[i].first;
		r = spots[i].second;
		if (pref[mp[r]] - pref[mp[l]-1] == 0) {
			cout << i+1 << endl;
			found = true;
			break;
		}
	}
	if (!found) cout << -1 << endl;
	cin >> n;

}