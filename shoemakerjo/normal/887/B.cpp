#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<int> poss;
	int nums[n][6];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> nums[i][j];
		}
	}
	vector<int> vc;
	for (int i = 0; i < n; i++) {
		vc.push_back(i);
	}
	do {
		vector<int> cur;
		cur.push_back(0);
		for (int i = 0; i < n; i++) {
			vector<int> nc;
			for (int j = 0; j < cur.size(); j++) {
				for (int k = 0; k < 6; k++) {
					nc.push_back(10*cur[j] + nums[vc[i]][k]);
					poss.insert(nc.back());
				}
			}
			cur.clear();
			for (int j = 0; j < nc.size(); j++) cur.push_back(nc[j]);
		}

	} while (next_permutation(vc.begin(), vc.end()));
	for (int i = 1; i <= 1000; i++) {
		if (poss.find(i) == poss.end()) {
			cout << i-1 << endl;
			break;
		}
	}
	cin >> n;
}