#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, inv = 0;
	string s;
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] != 'R') continue;
		for (int j = i + 1; j < n; j++) {
			if (s[j] == 'L') inv++;
		}
	}

	if (k > inv) {
		cout << "-1\n";
		return 0;
	}

	vector<vector<int>> ans;

	queue<int> ind;
	for (int i = 0; i + 1 < n; i++) {
		if (s[i] == 'R' && s[i + 1] == 'L') {
			ind.push(i);
		}
	}

	vector<int> uu(n, -1);
	int kk = 34;

	for (int it = k - 1; it >= 0; it--) {
		kk++;
		ans.emplace_back();
		int mx_it = ind.size();
		for (int i = 0; i < mx_it && inv > it; i++) {
			int v = ind.front();
			ind.pop();
			if (s[v] != 'R' || s[v + 1] != 'L') continue;
			if (uu[v] == kk || uu[v + 1] == kk) continue;
			inv--;
			uu[v] = uu[v + 1] = kk;
			ans.back().push_back(v + 1);
			swap(s[v], s[v + 1]);
			if (v > 0) ind.push(v - 1);
			if (v + 1 < n) ind.push(v + 1);
		}
	}

	if (inv > 0) {
		cout << "-1\n";
		return 0;
	}


	// cout << ans.size() << "\n";
	for (const auto &r : ans) {
		cout << r.size();
		for (int x : r) cout << " " << x;
		cout << "\n";
	}
}