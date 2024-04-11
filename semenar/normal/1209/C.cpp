#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tests;
	cin >> tests;

	for (int test = 0; test < tests; test++) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		vector<int> mnum(n, 10);
		mnum[0] = s[0] - '0';
		for (int i = 1; i < n; i++) mnum[i] = max(mnum[i - 1], s[i] - '0');
		
		vector<int> bnum(n);
		bnum[n - 1] = s[n - 1] - '0';
		for (int i = n - 2; i >= 0; i--) bnum[i] = min(bnum[i + 1], s[i] - '0');

		vector<bool> okay(10, true);
		for (int i = 0; i < n; i++) {
			if (bnum[i] < s[i] - '0') for (int j = s[i] - '0' + 1; j < 10; j++) okay[j] = false;
			if (mnum[i] > s[i] - '0') for (int j = 0; j < s[i] - '0'; j++) okay[j] = false;
		}

		vector<int> last_num(10, -1);
		bool good = false;

		for (int i = 0; i < n; i++) {
			int ps = s[i] - '0';
			if (okay[ps]) {
				if (bnum[i] >= ps && (last_num[ps] == -1 || mnum[last_num[ps]] <= ps)) {
					for (int j = 0; j < n; j++) {
						if (s[j] > s[i]) cout << 2;
						else if (s[j] < s[i]) cout << 1;
						else if (j < i) cout << 2;
						else cout << 1;
					}
					cout << endl;
					good = true;
					break;
				}
				last_num[ps] = i;
			}
		}
		if (!good) cout << "-" << endl;
	}

	return 0;
}