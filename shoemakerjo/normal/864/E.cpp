#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
	int n;
	cin >> n;
	int tt[n], dt[n], pt[n], t[n], d[n], p[n], ind[n];
	vector<pii> times;
	for (int i = 0; i < n; i++) {
		cin >> tt[i] >> dt[i] >> pt[i];
		times.push_back(pii(dt[i], i));
	}
	sort(times.begin(), times.end());
	for (int i = 0; i < n; i++) {
		int index = times[i].second;
		t[i] = tt[index];
		d[i] = dt[index];
		p[i] = pt[index];
		ind[i] = index+1;
	}
	int dp[2001];
	vector<vector<int>> anses;
	for (int i = 0; i <= 2000; i++) {
		vector<int> b;
		anses.push_back(b);
		dp[i] = -1;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = d[i]-1; j >= 0; j--) {
			if (j - t[i] >= 0 && dp[j-t[i]] != -1) {
				if (dp[j-t[i]] + p[i] > dp[j]) {
					dp[j] = dp[j-t[i]] +p[i];
					anses[j].clear();
					for (int k = 0; k < anses[j-t[i]].size(); k++) {
						anses[j].push_back(anses[j-t[i]][k]);
					}
					anses[j].push_back(ind[i]);
					
				}
			}
		}
	}
	vector<int> ans;
	int big = 0;
	int aspot = -1;
	for (int i = 1; i <= 2000; i++) {
		if (dp[i] > big) {
			big = dp[i];
			aspot = i;
		}
	}
	cout << big << '\n';
	if (aspot == -1) {
		cout << 0 << endl;
	}
	else {
		cout << anses[aspot].size() << '\n';
		for (int i = 0; i < anses[aspot].size(); i++) {
			if (i > 0) cout << " ";
			cout << anses[aspot][i];
		}
		cout << '\n';
	}
	
	// cin >> n;

}