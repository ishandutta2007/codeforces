// In the name of God

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

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = (int) 1e3 + 3, mod = 0;

int mark[N], p[N], p2[N];
int mat[N][N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	if (n <= 4) {
		cout << -1;
		return 0;
	}
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	mark[a] = mark[b] = mark[c] = mark[d] = 1;
	int pt = 0;
	p[pt++] = a;
	p[pt++] = c;
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		p[pt++] = i;
	}
	p[pt++] = d;
	p[pt++] = b;
	int res = 0;
	for (int i = 0; i < n - 1; ++i)
		mat[p[i]][p[i + 1]] = 1;
	pt = 0;
	p2[pt++] = c;
	p2[pt++] = a;
	for (int i = 2; i < n - 2; ++i)
		p2[pt++] = p[i];
	p2[pt++] = b;
	p2[pt++] = d;
//	mark[p[2]] = 1;
//	if (n != 5) {
//		p2[pt++] = p[3];
//		mark[p[3]] = 1;
//	} else {
//		p2[pt++] = d;
//	}
//	for (int i = 4; i < n - 1; ++i) {
//		p2[pt++] = p[i];
//	}
	for (int i = 0; i < n - 1; ++i)
		mat[p2[i]][p2[i + 1]] = 1;
	rep(i, n) {
		rep(j, n)
			if (i < j)
				res += mat[i][j] | mat[j][i];
		if (mat[i][i]) {
			cout << -1;
			return 0;
		}
	}
	if (mat[a][b] || mat[b][a] || mat[c][d] || mat[d][c]) {
		cout << -1;
		return 0;
	}
	if (k >= n + 1) {
		rep(i, n) cout << p[i] << ' ';
		cout << endl;
		rep(i, n) cout << p2[i] << ' ';
	} else {
		cout << -1;
	}

	return 0;
}