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
	double x, y;
	pt() {
	}
	pt(double x, double y) : x(x), y(y) {
	}
};

inline double area (pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1 (double a, double b, double c, double d) {
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

const int maxN = 25;
const int maxK = 8;

const double ang = 0.289348919;
const double dX = cos(ang);
const double dY = sin(ang);

struct DObject {
	int x, y;
	int mode;
	int cost;
	DObject(int x, int y, int mode, int cost) : x(x), y(y), mode(mode), cost(cost) {
	}
};

char s[maxN][maxN];
vector < DObject > items;
int n, m;
int p[maxN];

int d[maxN][maxN][1 << maxK];

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool isValid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && (s[x][y] == '.' || s[x][y] == 'S');
}

void calc(int x, int y, int mask) {
	memset(d, -1, sizeof(d));
	d[x][y][mask] = 0;

	queue < pair < pair < int, int >, int > > q;
	q.push(make_pair(make_pair(x, y), mask));
	while (!q.empty()) {
		pair < pair < int, int >, int > p = q.front();
		q.pop();
		int x = p.first.first;
		int y = p.first.second;
		int mask = p.second;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!isValid(nx, ny)) {
				continue;
			}

			int nmask = mask;
			pt A(x, y);
			pt B(nx, ny);
			for (int j = 0; j < items.size(); ++j) {
				pt C(items[j].x, items[j].y);
				pt D((double)(items[j].x) + 1000.0 * dX, (double)(items[j].y) + 1000.0 * dY);
				if (intersect(A, B, C, D)) {
					nmask ^= (1 << j);
				}
			}

			if (d[nx][ny][nmask] == -1) {
				d[nx][ny][nmask] = d[x][y][mask] + 1;
				q.push(make_pair(make_pair(nx, ny), nmask));
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
		for (int j = 0; j < m; ++j) {
			if (s[i][j] >= '1' && s[i][j] <= '9') {
				++cnt;
			}
		}
	}
	for (int i = 0; i < cnt; ++i) {
		scanf("%d", &p[i]);
	}

	int x, y;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] >= '1' && s[i][j] <= '9') {
				items.push_back(DObject(i, j, 0, p[s[i][j] - '1']));
			} else if (s[i][j] == 'B') {
				items.push_back(DObject(i, j, 1, 0));
			} else if (s[i][j] == 'S') {
				x = i;
				y = j;
			}
		}
	}
	int t = items.size();

	calc(x, y, 0);
	int res = 0;
	for (int i = 0; i < (1 << t); ++i) {
		if (d[x][y][i] == -1) {
			continue;
		}
		bool ok = true;
		int cost = 0;
		for (int j = 0; j < t; ++j) {
			if (i & (1 << j)) {
				if (items[j].mode == 1) {
					ok = false;
				}
				cost += items[j].cost;
			}
		}
		if (ok) {
			res = max(res, cost - d[x][y][i]);
		}
	}
	printf("%d\n", res);
	return 0;
}