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

string a, b;
int n, m;
const int maxN = 110;
const long long inf = 1000000000000000000LL;

pair < int, int > p[maxN][maxN][maxN];
long long d[maxN][maxN][maxN];

void precalc() {
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			d[0][i][j] = inf;
			p[0][i][j] = make_pair(-1, -1);
			char c = b[(j + 1) % b.size()];
			for (int k = i + 1; k <= i + a.size(); ++k) {
				if (a[k % a.size()] == c) {
					p[0][i][j] = make_pair(k % a.size(), (j + 1) % b.size());
					if (k < a.size()) {
						d[0][i][j] = 0;
					} else {
						d[0][i][j] = 1;
					}
					break;
				}
			}
		}
	}

	for (int t = 1; t < maxN; ++t) {
		for (int i = 0; i < a.size(); ++i) {
			for (int j = 0; j < b.size(); ++j) {
				pair < int, int > current = p[t - 1][i][j];
				if (current.first == -1) {
					p[t][i][j] = p[t - 1][i][j];
					d[t][i][j] = inf;
					continue;
				}

				p[t][i][j] = p[t - 1][current.first][current.second];
				d[t][i][j] = min(inf, d[t - 1][i][j] + d[t - 1][current.first][current.second]);
			}
		}
	}
}

bool isFit(long long length) {
	if (length == 0) {
		return true;
	}
	--length;
	int x = -1, y = -1;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == b[0]) {
			x = i;
			y = 0;
			break;
		}
	}
	if (x == -1) {
		return false;
	}

	long long res = 0;
	for (long long i = 0; i < 60; ++i) {
		if (length & (1LL << i)) {
			pair < int, int > current = p[i][x][y];
			if (current.first == -1) {
				return false;
			}
			res += d[i][x][y];
			x = current.first;
			y = current.second;
		}
	}
	return res < (long long)(n);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	cin >> a >> b;

	precalc();

	long long l = 0, r = 1000000000LL;
	while (r - l > 1LL) {
		long long middle = (l + r) / 2;
		if (isFit(middle * (long long)(m) * (long long)(b.size()))) {
			l = middle;
		} else {
			r = middle;
		}
	}

	long long res = l;
	if (isFit(r * (long long)(m) * (long long)(b.size()))) {
		res = r;
	}
	cout << res << endl;

	return 0;
}