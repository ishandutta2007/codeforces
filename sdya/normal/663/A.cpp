#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	getline(cin, s);
	int m = s.size();

	vector < int > signs;
	int sign = 1;
	for (int i = 0; i < m; ++i) {
		if (s[i] == '-') {
			sign = -1;
		} else if (s[i] == '+') {
			sign = 1;
		} else if (s[i] == '?') {
			signs.push_back(sign);
		}
	}

	int pos = find(s.begin(), s.end(), '=') - s.begin();
	int n = 0;
	for (int i = pos + 2; i < m; ++i) {
		n = n * 10 + (s[i] - '0');
	}

	int u = 0, v = 0;
	for (int i = 0; i < signs.size(); ++i) {
		if (signs[i] == 1) {
			++u;
		} else {
			++v;
		}
	}

	int l = u - v * n;
	int r = n * u - v;

	if (l <= n && n <= r) {
		printf("Possible\n");
		vector < int > res(signs.size());
		for (int i = 0; i < signs.size(); ++i) {
			if (signs[i] == 1) {
				res[i] = 1;
			} else {
				res[i] = n;
			}
		}

		int s = l;
		for (int i = 0; i < signs.size() && s != n; ++i) {
			int diff = n - s;
			if (signs[i] == 1) {
				res[i] = min(1 + diff, n);
				s += res[i] - 1;
			} else {
				res[i] = max(1, n - diff);
				s += n - res[i];
			}
		}

		for (int i = 0; i < signs.size(); ++i) {
			if (i != 0) {
				printf("%c ", (signs[i] == 1 ? '+' : '-'));
			}
			printf("%d ", res[i]);
		}
		printf("= %d\n", n);
	} else {
		printf("Impossible\n");
	}

	return 0;
}