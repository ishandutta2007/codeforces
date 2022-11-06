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

void comp_dfs(vector<vi> &gr, int v, vector<int> &comp, int col) {
	if (comp[v] != -1) return;
	comp[v] = col;
	for (auto w : gr[v]) comp_dfs(gr, w, comp, col);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tests;
	cin >> tests;

	for (int test = 0; test < tests; test++) {
		int n, m;
		cin >> n >> m;

		vector<vi> table(n, vi(m));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) cin >> table[i][j];

		vector<int> dp(1 << n);

		int pw3 = 1;
		for (int i = 0; i < n; i++) pw3 *= 3;

		for (int i = 0; i < m; i++) {
			vector<int> ndp = dp;
			for (int sf = 0; sf < n; sf++) {
				for (int mask = 0; mask < pw3; mask++) {
					int x = mask;
					int msk1 = 0;
					int msk2 = 0;
					int rem = 0;
					for (int j = 0; j < n; j++) {
						msk1 <<= 1;
						msk2 <<= 1;
						if (x % 3 > 0) msk1++;
						if (x % 3 > 1) msk2++;
						if (x % 3 == 1) rem += table[(sf + j) % n][i];
						x /= 3;
					}
					ndp[msk1] = max(ndp[msk1], dp[msk2] + rem);
				}
			}
			dp = ndp;
		}

		cout << dp.back() << endl;
	}

	return 0;
}