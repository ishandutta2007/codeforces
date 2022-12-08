#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	string s, t;
	cin >> s >> t;
	vector<int> pos;
	int pref[n+10];
	fill(pref, pref+n+10, 0);
	for (int i = 0; i < n; i++) {
		// cout << "match atL: "
		if (i != 0) pref[i] = pref[i-1];
		if (i + m-1 >= n) continue;
		bool match = true;
		for (int j = 0; j < m; j++) {
			if (t[j] != s[i+j]) {
				match = false;
				break;
			}
		}
		if (match) pref[i]++;
	}
	int l, r;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		r--; l--;
		if (r-l+1 < m) {
			cout << 0 << '\n';
			continue;
		}
		//last matching position is l-m+1
		int nums = pref[r-m+1];
		if (l != 0) nums -= pref[l-1];
		cout << nums << '\n';
	}
	cout.flush();
	
}