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

bool used[2][210][110][60];
string s;
int n;

void dfs(int dir, int pos, int filled, int changes) {
	if (used[dir][pos][filled][changes]) {
		return;
	}
	used[dir][pos][filled][changes] = true;

	int add = (dir == 0 ? -1 : 1);
	if (filled == s.size()) {
		return;
	}

	if (s[filled] == 'T') {
		dfs(1 - dir, pos, filled + 1, changes);
	} else {
		dfs(dir, pos + add, filled + 1, changes);
	}

	if (changes + 1 <= n) {
		if (s[filled] == 'F') {
			dfs(1 - dir, pos, filled + 1, changes + 1);
		} else {
			dfs(dir, pos + add, filled + 1, changes + 1);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> s;
	cin >> n;

	dfs(0, 105, 0, 0);

	int res = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 210; ++j) {
			for (int k = n; k >= 0; k -= 2) {
				if (used[i][j][s.size()][k]) {
					res = max(res, abs(105 - j));
				}
			}
		}
	}
	cout << res << endl;

	return 0;
}