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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int inf = 1000000;

void mul(int a[5][5], int b[5][5], int c[5][5]) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			c[i][j] = -inf;
			for (int k = 0; k < 5; ++k) {
				c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
			}
		}
	}
}

void mul(int a[5], int b[5][5], int c[5]) {
	for (int i = 0; i < 5; ++i) {
		c[i] = -inf;
		for (int j = 0; j < 5; ++j) {
			c[i] = max(c[i], a[j] + b[j][i]);
		}
	}
}

const int maxN = 210000;

int n, m;
char s[maxN];

int p[maxN][5][5];

int t[4 * maxN][5][5];

void build(int i, int l, int r) {
	if (l == r) {
		for (int x = 0; x < 5; ++x) {
			for (int y = 0; y < 5; ++y) {
				t[i][x][y] = p[l][x][y];
			}
		}
		return ;
	}
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	mul(t[2 * i], t[2 * i + 1], t[i]);
}

void get(int i, int l, int r, int cl, int cr, int d[5]) {
	if (l == cl && r == cr) {
		int c[5];
		mul(d, t[i], c);
		for (int j = 0; j < 5; ++j) {
			d[j] = c[j];
		}
		return ;
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, d);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr, d);
	}

	get(2 * i, l, (l + r) / 2, cl, (l + r) / 2, d);
	get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, d);
}

void prepare() {
	for (int i = 0; i < n; ++i) {
		for (int x = 0; x < 5; ++x) {
			for (int y = 0; y < 5; ++y) {
				p[i][x][y] = -inf;
			}
		}
		{
			int added = (s[i] == '2' ? 0 : 1);
			p[i][0][0] = added;

			if (added == 0) {
				p[i][0][1] = 1;
			}
		}

		{
			int added = (s[i] == '0' ? 0 : 1);
			p[i][1][1] = added;

			if (s[i] == '0') {
				p[i][1][2] = 1;
			}
		}

		{
			int added = (s[i] == '1' ? 0 : 1);
			p[i][2][2] = added;
			
			if (s[i] == '1') {
				p[i][2][3] = 1;
			}
		}

		{
			int added = (s[i] == '7' || s[i] == '6' ? 0 : 1);
			p[i][3][3] = added;

			if (s[i] == '7') {
				p[i][3][4] = 1;
			}
		}

		{
			int added = (s[i] == '6' ? 0 : 1);
			p[i][4][4] = added;
		}
	}
	build(1, 0, n - 1);
}

int solve(int l, int r) {
	int d[5] = {0, -inf, -inf, -inf, -inf};

	get(1, 0, n - 1, l, r, d);

	if (d[4] < 0) {
		return -1;
	}

	return r - l + 1 - d[4];
}

void gen() {
	int n = 200000;
	printf("%d 0\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%c", rand() % 10 + '0');
	}
	printf("\n");
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();
	//return 0;

	scanf("%d%d", &n, &m);
	scanf("%s", &s);

	prepare();
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", solve(l - 1, r - 1));
	}

	//cerr << clock() << endl;


	return 0;
}