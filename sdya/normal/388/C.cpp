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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
vector < int > g[maxN], s[maxN];
int n, l[maxN], r[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		g[i].resize(m);
		s[i].resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> g[i][j];
			s[i][j] = g[i][j];
			if (j > 0) {
				s[i][j] += s[i][j - 1];
			}
		}
		l[i] = 0;
		r[i] = m - 1;
	}

	int total = 0;
	for (int i = 0; i < n; ++i) {
		total += s[i][r[i]];
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		int score = s[i][l[i]];
		++l[i];

		vector < int > t;
		for (int j = 0; j < n; ++j) {
			int m = (r[j] - l[j] + 1) / 2;
			if (m > 0) {
				score += s[j][l[j] + m - 1] - (l[j] == 0 ? 0 : s[j][l[j] - 1]);
			}
			if ((r[j] - l[j] + 1) % 2 == 1) {
				t.push_back(g[j][l[j] + m]);
			}
		}
		sort(t.rbegin(), t.rend());
		for (int j = 1; j < t.size(); j += 2) {
			score += t[j];
		}

		--l[i];
		res = max(res, score);
	}
	cout << res << " " << total - res << endl;

	return 0;
}