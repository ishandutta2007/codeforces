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

const int maxN = 1100;
const int maxT = 110;
const int inf = 1000000000;
int n, t;
int a[maxN], b[maxN];
vector < int > p[maxN];

int d[maxT][maxN];
int s[maxT][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		p[t - a[i]].push_back(b[i]);
	}

	for (int i = 0; i <= t; ++i) {
		sort(p[i].rbegin(), p[i].rend());
	}

	for (int i = 0; i <= t; ++i) {
		s[i][0] = 0;
		for (int j = 1; j <= n; ++j) {
			s[i][j] = s[i][j - 1];
			if (j - 1 < p[i].size()) {
				s[i][j] += p[i][j - 1];
			}
		}
	}

	for (int i = 0; i <= t; ++i) {
		for (int j = 0; j <= n; ++j) {
			d[i][j] = -inf;
		}
	}

	d[0][1] = s[0][0];
	d[0][0] = s[0][1];
	for (int i = 0; i + 1 <= t; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (d[i][j] == -inf) {
				continue;
			}
			for (int k = 0; k <= p[i + 1].size() && k <= 2 * j; ++k) {
				int rem = 2 * j - k;
				if (rem > n) {
					rem = n;
				}
				d[i + 1][rem] = max(d[i + 1][rem], d[i][j] + s[i + 1][k]);
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= t; ++i) {
		for (int j = 0; j <= n; ++j) {
			res = max(res, d[i][j]);
		}
	}
	cout << res << endl;

	return 0;
}