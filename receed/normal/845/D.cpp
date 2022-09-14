#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t, sp, s, no = 0, ans = 0, inf = 1e9;
	cin >> n;
	vector<int> lim;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == 3 || t == 1)
			cin >> s;
		if (t == 4)
			no = 0;
		else if (t == 6)
			no++;
		else if (t == 2) {
			ans += no;
			no = 0;
		}
		else if (t == 3) {
			if (sp <= s)
				lim.push_back(s);
			else
				ans++;
		}
		else if (t == 5)
			lim.clear();
		else if (t == 1) {
			sp = s;
			while (!lim.empty() && lim.back() < sp) {
				ans++;
				lim.pop_back();
			}
		}
	}
	cout << ans;
}