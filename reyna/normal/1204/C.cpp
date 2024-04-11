
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

const int N = (int) 105, M = 1e6 + 6, mod = (int) 0;
int d[N][N], par[M], dp[M], p[M];
void show(int v) {
	if (v != 0) {
		show(par[v]);	
	}
	cout << p[v] + 1 << ' ';
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		string s;
		cin >> s;
		for (int i = 0; i < n; ++i) {
			d[j][i] = ((s[i] - '0') ^ 1) * (int) 1e9 + 1;	
		}
		d[j][j] = 0;
	}
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	int m;
	cin >> m;
	memset(dp, 63, sizeof dp);
	for (int v = 0; v < m; ++v) cin >> p[v], --p[v];
	dp[0] = 1;
	for (int v = 1; v < m; ++v) {
		for (int u = v - 1; u >= max(0, v - n); --u) {
			if ((v - u) == d[p[u]][p[v]]) {
				if (dp[v] > dp[u] + 1) {
					dp[v] = dp[u] + 1;
					par[v] = u;
				}
			}
		}
	}
	cout << dp[m - 1] << endl;
	show(m - 1);
}