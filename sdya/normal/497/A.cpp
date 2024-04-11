#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n, m;
vector < string > s;

void solve(int l, int r, int index, vector < bool > &deleted) {
	if (l == r || index == m) {
		return ;
	}

	string t;
	for (int i = l; i <= r; ++i) {
		t += s[i][index];
	}

	bool isgood = true;
	for (int i = 1; i < t.size(); ++i) {
		if (t[i] < t[i - 1]) {
			isgood = false;
		}
	}
	if (!isgood) {
		deleted[index] = true;
		solve(l, r, index + 1, deleted);
		return;
	}

	int start = l;
	for (int i = l + 1; i <= r + 1; ++i) {
		if (i == r + 1 || s[i][index] > s[i - 1][index]) {
			solve(start, i - 1, index + 1, deleted);
			start = i;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	s.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	int res = 0;
	while (true) {
		int m = s[0].size();
		vector < bool > deleted(m, false);
		bool updates = false;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					if (s[i][k] > s[j][k]) {
						deleted[k] = true;
						updates = true;
					} else if (s[i][k] < s[j][k]) {
						break;
					}
				}
			}
		}
		if (!updates) {
			break;
		}

		res += count(deleted.begin(), deleted.end(), true);
		for (int i = 0; i < n; ++i) {
			string t = "";
			for (int j = 0; j < m; ++j) {
				if (!deleted[j]) {
					t += s[i][j];
				}
			}
			s[i] = t;
		}
	}

	cout << res << endl;
	

	return 0;
}