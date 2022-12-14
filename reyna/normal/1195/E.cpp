
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 3005, L = 12, mod = (int) 0;
int s[N];
void solve(int n, int m, int k, int a[N][N], int res[N][N]) {
	for (int row = 0; row < n; ++row) {
		int h = 0, t = 0;
		for (int j = 0; j < m; ++j) {
			while (t > h && a[row][s[t - 1]] > a[row][j]) --t;
			s[t++] = j;
			while (h < t && s[h] <= j - k) ++h;
			if (j - k + 1 >= 0) {
				res[row][j - k + 1] = a[row][s[h]];
			}
		}
	}
}
int width[N], a[N][N], c[N][N], b[N][N], res[N][N], g[N*N];
int main() {
	for (int j = 2; j < N; ++j) width[j] = width[j >> 1] + 1;
	int n, m, ka, kb;
	cin >> n >> m >> ka >> kb;
	cin >> g[0];
	int px, py, pz;
	cin >> px >> py >> pz;
	for (int j = 1; j < n * m; ++j)
		g[j] = (g[j - 1] * (LL) px + py) % pz;
	for (int j = 0; j < n * m; ++j)
		a[j / m][j % m] = g[j];
	solve(n, m, kb, a, c);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m - kb + 1; ++j)
			b[j][i] = c[i][j];
	solve(m - kb + 1, n, ka, b, res);
	long long sum = 0;
	for (int i = 0; i < m - kb + 1; ++i)
		for (int j = 0; j < n - ka + 1; ++j)
			sum += res[i][j];
	cout << sum << endl;
}