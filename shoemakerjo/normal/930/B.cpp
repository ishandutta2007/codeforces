#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int n;
	cin >> s;
	n = s.length();
	int ct[26];
	vector<vector<int>> sp(26);
	fill(ct, ct+26, 0);
	for (int i = 0; i < n; i++) {
		ct[s[i]-'a']++;
		sp[s[i]-'a'].push_back(i);
	}
	double ans = 0.0;
	for (int i = 0; i < 26; i++) {
		if (ct[i] == 0) continue;
		int bes = 0;
		double prob = (ct[i]+0.0)/(n+0.0);

		for (int j = 1; j <= n-1; j++) {
			int vals[26];
			fill(vals, vals+26, 0);
			for (int k = 0; k < sp[i].size(); k++) {
				int cur = sp[i][k];
				int nx = (cur+j)%n;
				vals[s[nx]-'a']++;
			}
			int cval = 0;
			for (int k = 0; k < 26; k++) {
				if (vals[k] == 1) cval++;
			}
			bes = max(bes, cval);
		}
		ans += prob*(bes+0.0)/(ct[i]+0.0);
	}

	cout << fixed << setprecision(15);
	cout << ans << endl;
	cin >> n;
}