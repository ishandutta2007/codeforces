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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const double eps = 1e-50;
const int maxN = 1100;
const double inf = 1e50;
int n, m;
vector < int > a[maxN];
double d[maxN][maxN];
int b[maxN];
double c[maxN][maxN];
bool have[maxN];

double t[maxN][maxN], s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < maxN; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= inf) {
				c[i][j] = inf;
			}
		}
	}
	cin >> n >> m;
	vector < pair < int, int > > x;
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		a[i].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> a[i][j];
			x.push_back(make_pair(a[i][j], i));
		}
	}
	sort(x.rbegin(), x.rend());
	for (int i = 0; i < n; ++i) {
		if (x[i].first != x[n - 1].first) {
			++b[x[i].second];
		}
	}

	int needed = x[n - 1].first;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			if (a[i][j] == needed) {
				have[i] = true;
			}
		}
	}
	d[0][0] = 1.0;
	t[0][0] = 1.0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (d[i][j] < eps) {
				d[i][j] = 0.0;
			}
			if (t[i][j] > inf) {
				t[i][j] = inf;
			}

			int cnt = b[i];
			if (j + cnt <= n) {
				d[i + 1][j + cnt] += d[i][j] / c[a[i].size()][cnt];
				t[i + 1][j + cnt] += t[i][j];
			}
			if (have[i] && j + cnt + 1 <= n) {
				d[i + 1][j + cnt + 1] += d[i][j] / c[a[i].size()][cnt + 1];
				t[i + 1][j + cnt + 1] += t[i][j];
			}
		}
	}

	t[0][0] = 1.0;
	for (int i = 0; i <= n; ++i) {
		s[i] = t[0][i];
		if (i > 0) {
			s[i] += s[i - 1];
		}
	}

	printf("%.10lf\n", d[m][n] / t[m][n]);

	return 0;
}