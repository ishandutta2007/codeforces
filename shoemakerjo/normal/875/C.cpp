#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
#define maxn 100001
bool isch[maxn];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<int> changed;

	int n, m;
	cin >> n >> m;

	int l, cur;
	vector<vector<int>> words;
	vector<vector<pii>> cols;
	bool ok[n];
	int maxl = 0;
	for (int i = 0; i < n; i++) {
		ok[i] = false;
	}
	for (int i = 0; i <= m; i++) isch[i] = false;
	for (int i = 0; i <= 100000; i++) {
		vector<pii> b;
		cols.push_back(b);
	}
	for (int i = 0; i < n; i++) {
		vector<int> tempo;
		cin >> l;
		maxl = max(maxl, l);
		for (int j = 0; j < l; j++) {
			cin >> cur;
			tempo.push_back(cur);
			cols[j].push_back(pii(i,cur));
		}
		words.push_back(tempo);
	}
	bool ansok = true;
	for (int q = 0; q < 3; q++) {
		for (int i = 0; i < n; i++) ok[i] = false;
	for (int i = 0; i < maxl; i++) {
		vector<int> change;
	
		for (int j = 0; j < cols[i].size()-1; j++) {
			if (ok[cols[i][j].first]) continue;
			if (cols[i][j].first +1 != cols[i][j+1].first) continue;
			if (isch[cols[i][j+1].second]) {
				change.push_back(j);
			}
			else {
				if ((cols[i][j+1].second < cols[i][j].second && !isch[cols[i][j].second])) {
					change.push_back(j);
				}
				// else if (cols[i][j].second < cols[i][j+1].second) {
				// 	ok[cols[i][j].first] = true;
				// }
			}
		}
		set<int> proc;
		// cout << "i: " << change.size() << endl;
		for (int j = change.size()-1; j >= 0; j--) {
			if (proc.count(change[j]) > 0) continue;
			// cout << "j: " << j << endl;
			int spot = change[j];
			// ok[cols[i][spot].first] = true;
			while (spot >= 0 && cols[i][spot].first+1 == cols[i][spot+1].first && !ok[cols[i][spot].first]) {
				if (cols[i][spot].second != cols[i][spot+1].second) {
					ok[cols[i][spot].first] = true;
				}
				// if (isch[cols[i][spot]].second && cols[i][spot].second <= cols[i][spot+1].second) break;
				proc.insert(spot);
				// cout << "here: " << cols[i][spot].second << endl;
				isch[cols[i][spot].second] = true;
				// cout << "here" << endl;
				spot--;

			}
		}
		for (int j = 0; j < cols[i].size()-1; j++) {
			if (ok[cols[i][j].first]) continue;
			if (cols[i][j].first +1 != cols[i][j+1].first) continue;
			if (cols[i][j].second != cols[i][j+1].second) {
				ok[cols[i][j].first] = true;
			}
		}
	} }

	vector<int> ans;
	bool isok = true;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < words[i].size(); j++) {
			if (j >= words[i+1].size()) {
				isok = false;
				break;
			}
			if (isch[words[i][j]] && !isch[words[i+1][j]]) {
				break;
			}
			if (isch[words[i+1][j]] && !isch[words[i][j]]) {
				isok = false;
				break;
			}
			if (words[i][j] < words[i+1][j]) {
				break;
			}
			if (words[i][j] > words[i+1][j]) {
				isok = false;
				break;
			}
		}
	}
	//
	if (!isok) {
		cout << "No" << endl;
		cin >> n;
		return 0;
	}

	cout << "Yes" << endl;
	for (int i = 0; i <= m; i++) {
		if (isch[i]) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		if (i > 0) cout << " ";
		cout << ans[i];
	}
	// cin >> n;

}