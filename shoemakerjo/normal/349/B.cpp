#include <bits/stdc++.h>

using namespace std;

int main() {
	int v;
	cin >> v;
	int vals[10];

	for (int i = 1; i <= 9; i++) {
		cin >> vals[i];
	}
	int minval = vals[1];
	int minnum = 1;
	for (int i = 2; i <= 9; i++) {
		if (vals[i] <= minval) {
			minval = vals[i];
			minnum = i;
		}
	}
	vector<int> ans;
	int ct = v/minval;
	for (int i = 1; i <= ct; i++) {
		ans.push_back(minnum);
		v-=minval;
	}
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 9; j > minnum; j--) {
			if (vals[j] - minval <= v) {
				v -= (vals[j]-minval);
				ans[i] = j;
				break;
			}
		}
	}
	if (ans.size() == 0) cout << -1 << endl;
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
		}
		cout << endl;
	}
	cin >> ct;
}