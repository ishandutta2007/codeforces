#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
int n;
int a[maxN];
int d[maxN][2 * maxN];
int p[maxN][2 * maxN];

vector<int> getWays(int n) {
	vector<int> ways;
	char s[5];
	sprintf(s, "%d", n);
	for (int i = 0; i < 4; ++i) {
		for (int j = (i == 0 ? 1 : 0); j <= 9; ++j) {
			int m = 0;
			for (int k = 0; k < 4; ++k) {
				int x = s[k] - '0';
				if (k == i) {
					x = j;
				}
				m = m * 10 + x;
			}
			if (m >= 1000 && m <= 2011) {
				ways.push_back(m);
			}
		}
	}
	sort(ways.begin(), ways.end());
	ways.resize(unique(ways.begin(), ways.end()) - ways.begin());
	return ways;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	d[0][1000] = true;
	for (int i = 0; i < n; ++i) {
		vector < int > ways = getWays(a[i]);
		for (int j = 1000; j <= 2011; ++j) {
			if (!d[i][j]) {
				continue;
			}
			for (int k = 0; k < ways.size(); ++k) {
				if (ways[k] >= j) {
					d[i + 1][ways[k]] = true;
					p[i + 1][ways[k]] = j;
				}
			}
		}
	}

	int res = -1;
	for (int i = 1000; i <= 2011; ++i) {
		if (d[n][i]) {
			res = i;
			break;
		}
	}
	if (res == -1) {
		printf("No solution\n");
		return 0;
	}

	vector < int > q;
	int x = n, y = res;
	while (x > 0) {
		q.push_back(y);
		y = p[x][y];
		--x;
	}
	reverse(q.begin(), q.end());
	for (int i = 0; i < q.size(); ++i) {
		cout << q[i] << endl;
	}

	return 0;
}