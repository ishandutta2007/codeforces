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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector < string > s(n);

	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	string candidates = "RGBYW12345";
	map < char, int > pos;
	for (int i = 0; i < candidates.size(); ++i) {
		pos[candidates[i]] = i;
	}

	int m = 10;
	int res = 8;
	for (int mask = 0; mask < (1 << m); ++mask) {
		int bits = 0;
		for (int i = 0; i < m; ++i) {
			if (mask & (1 << i)) {
				++bits;
			}
		}
		if (bits >= res) {
			continue;
		}

		vector < bool > used(n, false);
		for (int i = 0; i < n; ++i) {
			int u = pos[s[i][0]];
			int v = pos[s[i][1]];
			if ((mask & (1 << u)) && (mask & (1 << v))) {
				used[i] = true;
			}
		}

		while (true) {
			bool updates = false;
			for (int i = 0; i < m; ++i) {
				if (mask & (1 << i)) {
					set < string > t;
					for (int j = 0; j < n; ++j) {
						if (candidates[i] == s[j][i / 5] && !used[j]) {
							t.insert(s[j]);
						}
					}
					if (t.size() <= 1) {
						for (set < string > ::iterator it = t.begin(); it != t.end(); ++it) {
							for (int j = 0; j < n; ++j) {
								if (s[j] == *it && !used[j]) {
									used[j] = true;
									updates = true;
								}
							}
						}
					}
				}
			}
			if (!updates) {
				break;
			}
		}
		set < string > t;
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				t.insert(s[i]);
			}
		}
		
		if (t.size() <= 1) {
			res = min(res, bits);
		}
	}

	cout << res << endl;


	return 0;
}