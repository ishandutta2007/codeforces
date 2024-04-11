#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(m);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	for (int &x : c) cin >> x;

	int okPos = -1;
	for (int i = 0; i < n; i++)
		if (b[i] == c[m - 1] && (a[i] != b[i] || okPos == -1))
			okPos = i;	
	if (okPos == -1) {
		cout << "NO\n";
		return;
	}

	vector<vector<int>> v(n + 1);
	int bad = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i] && i != okPos) {
			v[b[i]].push_back(i);
			bad++;
		}
	vector<int> ans = {okPos};

	for (int i = m - 2; i >= 0; i--) {
		if (v[c[i]].empty()) { ans.push_back(okPos); continue; }
		int ind = v[c[i]].back();
		v[c[i]].pop_back();
		ans.push_back(ind);
		a[ind] = b[ind];
		bad--;
	}

	if (bad > 0) {
		cout << "NO\n";
		return;
	}


	reverse(ans.begin(), ans.end());
	cout << "YES\n";
	for (int x : ans) cout << x + 1 << " ";
	cout << "\n";
}

int main() {
	int t = 1;
#ifdef SERT
	t = 3;
#endif
	cin >> t;
	while (t--)
		solve();
}