#include <bits/stdc++.h>

using namespace std;

int table[200000][18];

int main() {
	int n, m;
	cin >> n >> m;
	int numbit[30];
	for (int i =0; i < 30; i++) {
		numbit[i] = 0;
	}
	int vals[n+1];
	vector<vector<int>> add;
	vector<vector<int>> rem;
	vector<pair<pair<int, int>, int>> qus;
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		add.push_back(b);
		vector<int> b2;
		rem.push_back(b2);
	}
	int l, r, q;
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> q;
		add[l].push_back(q);
		rem[r].push_back(q);
		qus.push_back(pair<pair<int, int>, int>(pair<int, int>(l, r), q));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < add[i].size(); j++) {
			int cur = add[i][j];
			for (int k = 0; k < 30; k++) {
				if (cur & 1 << k) {
					numbit[k]++;
				}
			}
		}
		int curv = 0;
		for (int j = 0; j < 30; j++) {
			if (numbit[j] > 0) curv += 1 << j;
		}
		vals[i] =  curv;
		table[i][0] = curv;
		for (int j = 0; j < rem[i].size(); j++) {
			int cur = rem[i][j];
			for (int k = 0; k < 30; k++) {
				if (cur & 1 << k) {
					numbit[k]--;
				}
			}
		}
	}
	int pow = 0;
	int pval = 1;
	while (2*pval <= n) {
		pow++;
		pval*=2;
	}
	for (int j = 1; j <= pow; j++) {
		for (int i = 1; i <= n - (1<<j)+1; i++) {
			table[i][j] = table[i][j-1] &
				table[i+(1 << (j-1))][j-1];
		}
	}
	bool ok = true;
	for (int i = 0; i < m; i++) {
		int l = qus[i].first.first;
		int r = qus[i].first.second;
		int q = qus[i].second;
		int ans = table[l][0];
		for (int j = pow; j >= 0; j--) {
			if (l + (1 << j) - 1 <= r) {
				ans = ans & table[l][j];
				l+=1 << j;
			}
		}
		if (ans != q) {
			ok = false;
		}
	}
	if (ok) {
		cout << "YES\n";
		for (int i = 1; i <= n; i++) {
			if (i > 1) cout << " ";
			cout << vals[i];
		}
		cout << endl;
	}
	else cout << "NO\n";
	cin >> n;
}