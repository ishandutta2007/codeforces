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
#include <ctime>
#include <random>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

using namespace std;

mt19937 rng(228);

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

void comp_dfs(vector<vi> &gr, int v, vector<int> &comp, int col) {
	if (comp[v] != -1) return;
	comp[v] = col;
	for (auto w : gr[v]) comp_dfs(gr, w, comp, col);
}

const int N = 1 << 12;

int dp[N], ndp[N], sfdp[N], md[25];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tests;
	cin >> tests;

	time_t start = clock();

	for (int test = 0; test < tests; test++) {
		int n, m;
		cin >> n >> m;

		vector<vi> table(m, vi(n));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) cin >> table[j][i];

		vector<pii> bobby;
		for (int i = 0; i < m; i++) {
			int mx = 0;
			for (int j = 0; j < n; j++) mx = max(mx, table[i][j]);
			bobby.eb(mx, i);
		}

		sort(all(bobby));
		reverse(all(bobby));

		for (int mask = 0; mask < (1 << n); mask++) {
			dp[mask] = 0;
			ndp[mask] = 0;
		}

		for (int i = 0; i < 2 * n; i++) md[i] = i % n;

		int SX = 1 << n;

		for (int j = 0; j < min(m, n); j++) {
			for (int sf = 0; sf < n; sf++) {
				for (int mask = 0; mask < SX; mask++) {
					sfdp[mask] = dp[mask];
					for (int i = 0; i < n; i++) {
						if (mask & (1 << i)) sfdp[mask] = max(sfdp[mask], sfdp[mask ^ (1 << i)] + table[bobby[j].second][md[sf + i]]);
					}
					if (ndp[mask] < sfdp[mask]) ndp[mask] = sfdp[mask];
				}
			}
			for (int mask = 0; mask < SX; mask++) {
				dp[mask] = ndp[mask];
			}
		}

		cout << dp[SX - 1] << endl;
	}

	//cout << (ld)(clock() - start) / CLOCKS_PER_SEC << " s" << endl;

	return 0;
}