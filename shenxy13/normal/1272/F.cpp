#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> state;
string s, t;
int dptable[201][201][201];
state nxt[201][201][201];
int dp(int i, int j, int k) {
	if (dptable[i][j][k] != -1) return dptable[i][j][k];
	if (i == s.size() && j == t.size() && k == 0) return dptable[i][j][k] = 0;
	if (i == s.size() && j == t.size()) {
		nxt[i][j][k] = state(ii(i, j), k - 1);
		return dptable[i][j][k] = dp(i, j, k - 1) + 1;
	}
	if (i == s.size()) {
		if (t[j] == '(') {
			nxt[i][j][k] = state(ii(i, j + 1), k + 1);
			return dptable[i][j][k] = dp(i, j + 1, k + 1) + 1;
		} else {
			if (k == 0) {
				nxt[i][j][k] = state(ii(i, j), k + 1);
				return dptable[i][j][k] = dp(i, j, k + 1) + 1;
			} else {
				nxt[i][j][k] = state(ii(i, j + 1), k - 1);
				return dptable[i][j][k] = dp(i, j + 1, k - 1) + 1;
			}
		}
	}
	if (j == t.size()) {
		if (s[i] == '(') {
			nxt[i][j][k] = state(ii(i + 1, j), k + 1);
			return dptable[i][j][k] = dp(i + 1, j, k + 1) + 1;
		} else {
			if (k == 0) {
				nxt[i][j][k] = state(ii(i, j), k + 1);
				return dptable[i][j][k] = dp(i, j, k + 1) + 1;
			} else {
				nxt[i][j][k] = state(ii(i + 1, j), k - 1);
				return dptable[i][j][k] = dp(i + 1, j, k - 1) + 1;
			}
		}
	}
	if (s[i] == t[j]) {
		if (s[i] == '(') {
			nxt[i][j][k] = state(ii(i + 1, j + 1), k + 1);
			return dptable[i][j][k] = dp(i + 1, j + 1, k + 1) + 1;
		} else {
			if (k == 0) {
				nxt[i][j][k] = state(ii(i, j), k + 1);
				return dptable[i][j][k] = dp(i, j, k + 1) + 1;
			} else {
				nxt[i][j][k] = state(ii(i + 1, j + 1), k - 1);
				return dptable[i][j][k] = dp(i + 1, j + 1, k - 1) + 1;
			}
		}
	}
	if (s[i] == '(') {
		if (k == 0) {
			nxt[i][j][k] = state(ii(i + 1, j), k + 1);
			return dptable[i][j][k] = dp(i + 1, j, k + 1) + 1;
		} else {
			int goup = dp(i + 1, j, k + 1), godown = dp(i, j + 1, k - 1);
			if (goup < godown) nxt[i][j][k] = state(ii(i + 1, j), k + 1);
			else nxt[i][j][k] = state(ii(i, j + 1), k - 1);
			return dptable[i][j][k] = min(goup, godown) + 1;
		}
	} else {
		if (k == 0) {
			nxt[i][j][k] = state(ii(i, j + 1), k + 1);
			return dptable[i][j][k] = dp(i, j + 1, k + 1) + 1;
		} else {
			int goup = dp(i, j + 1, k + 1), godown = dp(i + 1, j, k - 1);
			if (goup < godown) nxt[i][j][k] = state(ii(i, j + 1), k + 1);
			else nxt[i][j][k] = state(ii(i + 1, j), k - 1);
			return dptable[i][j][k] = min(goup, godown) + 1;
		}
	}
}
int main() {
	memset(dptable, -1, sizeof dptable);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s >> t;
	dp(0, 0, 0);
	int ti, tj, tk;
	for (int i = 0, j = 0, k = 0; i != s.size() || j != t.size() || k != 0; i = ti, j = tj, k = tk) {
		ti = nxt[i][j][k].first.first, tj = nxt[i][j][k].first.second, tk = nxt[i][j][k].second;
		if (tk > k) cout << '(';
		else cout << ')';
	}
	return 0;
}