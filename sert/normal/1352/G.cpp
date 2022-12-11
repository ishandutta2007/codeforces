#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v4 = {1,3,0,2};
	vector<int> v5 = {0,2,4,1,3};
	vector<int> v6 = {0,2,4,1,3,5};
	vector<int> v7 = {0,2,4,1,5,3,6};
	vector<int> v11 = {0,2,4,1,3,5,7,9,6,8,10};
	if (n < 4) {
		cout << "-1\n";
		return;
	}
	if (n == 6) {
		for (int i = 0; i < n; i++) cout << v6[i] + 1 << " ";
		cout << "\n";
		return;
	}
	if (n == 7) {
		for (int i = 0; i < n; i++) cout << v7[i] + 1 << " ";
		cout << "\n";
		return;
	}
	if (n == 11) {
		for (int i = 0; i < n; i++) cout << v11[i] + 1 << " ";
		cout << "\n";
		return;
	}

	int cur = 0;
	while ((n - cur) % 4) {
		for (int i = 0; i < 5; i++) cout << cur + v5[i] + 1 << " ";
		cur += 5;
	}
	while (cur < n) {
		for (int i = 0; i < 4; i++) cout << cur + v4[i] + 1 << " ";
		cur += 4;
	}
	cout << "\n";
}

void init() {
	for (int len = 4; len <= 11; len++) {
		if (len != 5 && len != 4 && len != 7 && len != 11 && len != 6) continue;
		vector<int> v;
		for (int i = 0; i < len; i++) v.push_back(i + 1);
		while (true) {
			bool ok = true;
			for (int i = 1; i < len; i++) if (abs(v[i] - v[i - 1]) < 2 || abs(v[i] - v[i - 1]) > 4) ok = false;
			if (ok) {
				cout << "vector<int> v" << len << " = {";
				for (int i = 0; i < len; i++) cout << v[i] - 1 << ",";
				cout << "};" << endl;
				break;
			}
			if (!next_permutation(v.begin(), v.end())) break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	// init();
	// return 0;
	cin >> t;
	while (t--) {
		solve();
	}
}