#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<string> name(n), sur(n);
	vector<int> nn(26, 0), s(26, 0);
	for (int i = 0; i < n; i++) {
		cin >> name[i];
		nn[name[i][0] - 'A']++;
	}
	for (int i = 0; i < n; i++) {
		cin >> sur[i];
		s[sur[i][0] - 'A']++;
	}
	sort(name.begin(), name.end());
	sort(sur.begin(), sur.end());

	vector<bool> u(n, false);


	for (int i = 0; i < n; i++) {
		if (i > 0) cout << ", ";
		cout << name[i] << " ";
		int f = name[i][0] - 'A';

		int bst = -1;
		for (int j = 0; j < n && bst == -1; j++) {
			int ff = sur[j][0] - 'A';
			if (s[ff] > nn[ff] && !u[j]) {
				bst = j;
			}
		}

		int my = -1;
		for (int j = 0; j < n && my == -1; j++) {
			if (sur[j][0] == name[i][0] && !u[j]) {
				my = j;
			}
		}
		
		int kk = -1;
		if (my == -1 || (bst != -1 && nn[f] > s[f] && sur[bst] < sur[my]))
			kk = bst;
		else
			kk = my;

		u[kk] = true;
		nn[f]--;
		s[sur[kk][0] - 'A']--;
		cout << sur[kk];
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 3;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}