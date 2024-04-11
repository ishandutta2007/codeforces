// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = 1e5 + 5, mod = 0;

int dp[N][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = (int) s.size();
	dp[n - 2][0] = 1;
	dp[n - 3][1] = 1;
	for (int i = n - 4; i >= 0; --i) {
		rep(j, 2)
			rep(k, 2) {
				if (j != k) {
					dp[i][j] |= dp[i + 2 + j][k];
				} else {
					if (j == 0)
						if (s[i] != s[i + 2] || s[i + 1] != s[i + 3])
							dp[i][j] |= dp[i + 2][k];
					if (j == 1)
						if (i + 5 < n && (s[i] != s[i + 3] || s[i + 1] != s[i + 4] || s[i + 2] != s[i + 5]))
							dp[i][j] |= dp[i + 3][k];
				}
			}
	}
	vector<string> v;
	rep(i, n) {
		if (i >= 5) {
			string t = "";
			if (dp[i][0]) {
				t += s[i];
				t += s[i + 1];
				v.push_back(t);
			}
			t = "";
			if (dp[i][1]) {
				t += s[i];
				t += s[i + 1];
				t += s[i + 2];
				v.push_back(t);
			}
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	cout << v.size() << '\n';
	for (auto s : v)
		cout << s << '\n';
	return 0;
}