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

struct pt {
	long long x, y;
	pt() {}
	pt(long long x, long long y) : x(x), y(y) {}
};

inline long long area (pt a, pt b, pt c) {
	long long value = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (value > 0) {
		return 1;
	}
	if (value < 0) {
		return -1;
	}
	return 0;
}

inline bool intersect_1 (long long a, long long b, long long c, long long d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}

bool intersect (pt a, pt b, pt c, pt d) {
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * area(a,b,d) <= 0
		&& area(c,d,a) * area(c,d,b) <= 0;
}

const int maxN = 210;
const long long P = 1000000007LL;

int n;
long long x[maxN], y[maxN];

bool valid[maxN][maxN];

long long d[maxN][maxN];

long long calc(int x, int y) {
	if (d[x][y] != -1) {
		return d[x][y];
	}
	if (y - x <= 1) {
		return d[x][y] = 1;
	}

	long long res = 0;
	vector < long long > p(y - x + 1, 0);
	p[1] = 1;
	for (int i = 2; i < y - x + 1; ++i) {
		if (!valid[x][x + i]) {
			continue;
		}
		for (int j = 0; j < i; ++j) {
			if (p[j] == 0) {
				continue;
			}
			if (!valid[x + i][x + j]) {
				continue;
			}
			p[i] += p[j] * calc(j + x, i + x);
			p[i] %= P;
		}
	}
	return d[x][y] = p[y - x];
}

void gen() {
	int n = 200;
	printf("%d\n", n);
	int x = 0, y = 0;
	int dx = 1, dy = 2;
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", x, y);
		x += dx;
		y += dy;
		++dy;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		x[i] *= 2;
		y[i] *= 2;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (j == i + 1 || (i == 0 && j == n - 1)) {
				valid[i][j] = valid[j][i] = true;
				continue;
			}
			bool good = true;
			for (int k = 0; k < n; ++k) {
				int u = k;
				int v = (k == n - 1 ? 0 : (k + 1));
				if (u == i || u == j || v == i || v == j) {
					continue;
				}
				if (intersect(pt(x[i], y[i]), pt(x[j], y[j]), pt(x[u], y[u]), pt(x[v], y[v]))) {
					good = false;
					break;
				}
			}
			if (!good) {
				continue;
			}
			for (int k = 0; k < n; ++k) {
				int u = k;
				if (u == i || u == j) {
					continue;
				}
				if (intersect(pt(x[i], y[i]), pt(x[j], y[j]), pt(x[u], y[u]), pt(x[u], y[u]))) {
					good = false;
					break;
				}
			}
			long long A = y[i] - y[j];
			long long B = x[j] - x[i];
			long long C = x[i] * y[j] - x[j] * y[i];
			int pos = 0, neg = 0;
			for (int k = 0; k < n; ++k) {
				long long value = A * x[k] + B * y[k] + C;
				if (value > 0) {
					++pos;
				}
				if (value < 0) {
					++neg;
				}
			}
			if (pos == 0 || neg == 0) {
				good = false;
			}
			if (!good) {
				continue;
			}

			long long cx = (x[i] + x[j]) / 2;
			long long cy = (y[i] + y[j]) / 2;

			long long dx = 1000000000;
			long long dy = 1000000001;

			int cnt = 0;
			for (int k = 0; k < n; ++k) {
				int u = k;
				int v = (k == n - 1 ? 0 : (k + 1));
				if (intersect(pt(cx, cy), pt(cx + dx, cy + dy), pt(x[u], y[u]), pt(x[v], y[v]))) {
					++cnt;
				}
				if (intersect(pt(cx, cy), pt(cx + dx, cy + dy), pt(x[u], y[u]), pt(x[u], y[u]))) {
					--cnt;
				}
			}
			if (cnt % 2 == 0) {
				good = false;
			}
			valid[i][j] = valid[j][i] = good;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			d[i][j] = -1;
		}
	}

	vector < long long > p(n, 0);
	p[1] = 1;
	for (int i = 2; i < n; ++i) {
		if (!valid[0][i]) {
			continue;
		}
		for (int j = 0; j < i; ++j) {
			if (p[j] == 0) {
				continue;
			}
			if (!valid[i][j]) {
				continue;
			}
			p[i] += p[j] * calc(j, i);
			p[i] %= P;
		}
	}
	cout << p[n - 1] << endl;

	//cerr << clock() << endl;

	return 0;
}