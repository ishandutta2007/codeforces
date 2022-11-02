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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 10;
int res[1 << maxN][maxN][2];

int solve(int mask, int bits, int move) {
	if (res[mask][bits][move] != -1) {
		return res[mask][bits][move];
	}

	if (mask == 1 && bits == 3 && move == 1) {
		int cur = 0;
	}

	if (bits == 2) {
		return res[mask][bits][move] = mask;
	}

	if (move == 0) {
		int &value = res[mask][bits][move];
		value = -1;
		for (int i = 0; i < bits; ++i) {
			int nmask = 0;
			for (int j = 0; j < bits; ++j) {
				if (j < i) {
					nmask |= (mask & (1 << j));
				}
				if (j > i) {
					int score = (bool)(mask & (1 << j));
					nmask |= score * (1 << (j - 1));
				}
			}
			value = max(value, solve(nmask, bits - 1, 1 - move));
		}
		return value;
	} else {
		int &value = res[mask][bits][move];
		value = 4;
		for (int i = 0; i < bits; ++i) {
			int nmask = 0;
			for (int j = 0; j < bits; ++j) {
				if (j < i) {
					nmask |= (mask & (1 << j));
				}
				if (j > i) {
					int score = (bool)(mask & (1 << j));
					nmask |= score * (1 << (j - 1));
				}
			}
			value = min(value, solve(nmask, bits - 1, 1 - move));
		}
		return value;
	}
}

void precalc() {
	memset(res, -1, sizeof(res));
	for (int length = 2; length <= 9; ++length) {
		for (int i = 0; i < (1 << length); ++i) {
			int score = solve(i, length, 1);
			int zeroes = 0, ones = 0;
			string ans = "";
			for (int j = length - 1; j >= 0; --j) {
				if (i & (1 << j)) {
					ans += '1';
					++ones;
				} else {
					ans += '0';
					++zeroes;
				}
			}
			int masha = (length - 1) / 2;
			int vova = length - masha - 2;

			int clever = -1;
			if (ones >= masha + 2) {
				clever = 3;
			} else if (zeroes >= vova + 2) {
				clever = 0;
			} else {
				int pos0 = 0, pos1 = 1;
				for (int j = length - 1; j >= 0; --j) {
					if (i & (1 << j)) {
						pos1 = j;
					} else {
						pos0 = j;
					}
				}
				if (pos1 < pos0) {
					clever = 1;
				} else {
					clever = 2;
				}
			}
			if (clever != score) {
				cout << ans << ": " << score << ", " << clever << endl;
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	int cnt0 = 0, cnt1 = 0;
	cnt0 = count(s.begin(), s.end(), '0');
	cnt1 = count(s.begin(), s.end(), '1');
	int n = s.size();

	vector < int > pos;
	int pos0 = -1, pos1 = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			pos.push_back(i);
		}
		if (s[i] == '0') {
			pos0 = i;
		}
		if (s[i] == '1') {
			pos1 = i;
		}
	}

	int m = n - cnt0 - cnt1;
	vector < bool > used(4, false);
	for (int i = 0; i <= m; ++i) {
		int zeroes = cnt0 + i;
		int ones = cnt1 + m - i;

		int x = (n - 1) / 2;
		int y = n - 2 - x;
		if (ones >= x + 2) {
			used[3] = true;
			continue;
		}
		if (zeroes >= y + 2) {
			used[0] = true;
			continue;
		}

		{
			int cpos0 = max((i == 0 ? -1 : pos[i - 1]), pos0);
			int cpos1 = max((i == m ? -1 : pos[m - 1]), pos1);
			if (cpos0 < cpos1) {
				used[1] = true;
			}
		}

		{
			int cpos0 = max((i == 0 ? -1 : pos[m - 1]), pos0);
			int cpos1 = max((i == m ? -1 : pos[m - i - 1]), pos1);
			if (cpos1 < cpos0) {
				used[2] = true;
			}
		}
	}

	for (int i = 0; i < 4; ++i) {
		if (used[i]) {
			int u = (bool)(i & 2);
			int v = (bool)(i & 1);
			cout << u << v << endl;
		}
	}	

	return 0;
}