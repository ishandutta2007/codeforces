#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	string cur;

	vector<int> vals;

	for (int i = 0; i < n; i++) {
		cin >> cur;
		int minval = 0;
		int curval = 0;
		for (int j = 0; j < cur.length(); j++) {
			if (cur[j] == '(') {
				curval++;
			}
			else curval--;

			minval = min(minval,curval);
		}

		if (minval < curval && minval < 0) continue;

		vals.push_back(curval);
	}

	int ans = 0;
	multiset<int> seen;

	for (int v : vals) {
		if (seen.find(0-v) != seen.end()) {
			seen.erase(seen.find(0-v));
			ans++;
		}
		else seen.insert(v);
	}

	cout << ans << endl;
	
}