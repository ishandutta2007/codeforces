#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
string s1, s2, v;

map < string, int > prefixes;

int nt[maxN][26];

int dp[maxN][maxN][maxN];

struct State {
	int x, y, z;
	State() {
	}
	State(int x, int y, int z) : x(x), y(y), z(z) {
	}
};
State p[maxN][maxN][maxN];

string build(int n, int m, int k) {
	if (n == 0 && m == 0) {
		return "";
	}

	int nn = p[n][m][k].x;
	int nm = p[n][m][k].y;
	int nk = p[n][m][k].z;

	if (dp[nn][nm][nk] + 1 == dp[n][m][k]) {
		return build(nn, nm, nk) + string(1, s1[nn]);
	}
	return build(nn, nm, nk);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> s1 >> s2 >> v;
	for (int i = 0; i <= v.size(); ++i) {
		prefixes[v.substr(0, i)] = i;
	}

	for (int i = 0; i <= v.size(); ++i) {
		for (int j = 0; j < 26; ++j) {
			string t = v.substr(0, i);
			t += 'A' + j;

			for (int k = t.size(); k >= 0; --k) {
				string p = (k == 0 ? "" : t.substr(t.size() - k, k));
				if (prefixes.count(p)) {
					nt[i][j] = prefixes[p];
					break;
				}
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	int n = s1.size(), m = s2.size();
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k < maxN; ++k) {
				if (dp[i][j][k] == -1) {
					continue;
				}
				if (i < n && dp[i + 1][j][k] < dp[i][j][k]) {
					dp[i + 1][j][k] = dp[i][j][k];
					p[i + 1][j][k] = State(i, j, k);
				}
				if (j < m && dp[i][j + 1][k] < dp[i][j][k]) {
					dp[i][j + 1][k] = dp[i][j][k];
					p[i][j + 1][k] = State(i, j, k);
				}
				if (i < n && j < m && s1[i] == s2[j]) {
					int nk = nt[k][s1[i] - 'A'];
					if (nk == v.size()) {
						continue;
					}

					if (dp[i + 1][j + 1][nk] < dp[i][j][k] + 1) {
						dp[i + 1][j + 1][nk] = dp[i][j][k] + 1;
						p[i + 1][j + 1][nk] = State(i, j, k);
					}
				}
			}
		}
	}

	int k = -1;
	int res = -1;
	for (int i = 0; i < maxN; ++i) {
		if (dp[n][m][i] > res) {
			res = dp[n][m][i];
			k = i;
		}
	}


	if (res == 0) {
		cout << "0" << endl;
	} else {
		cout << build(n, m, k) << endl;
	}


	return 0;
}