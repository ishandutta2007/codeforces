#include <bits/stdc++.h>
using namespace std;

const int inf = 1e8;

struct pnt {
	int x, y;
	pnt(int xx = 0, int yy = 0) {
		x = xx, y = yy;
	}
	pnt operator = (const pnt b) {
		x = b.x, y = b.y;
	}
	bool operator == (const pnt &b) const {
		return x == b.x && y == b.y;
	}
	bool operator < (const pnt &b) const {
		return x != b.x ? x < b.x : y < b.y;
	}
	void print() {
		printf("%d %d\n", x, y);
	}
} A[5], O[5], p[5];

pnt rot(pnt A, pnt O) {
	return pnt(O.x - (A.y - O.y), O.y + (A.x - O.x));
}

long long dist(pnt a, pnt b) {
	return 1ll * (a.x - b.x) * (a.x - b.x) + 1ll * (a.y - b.y) * (a.y - b.y);
}

long long d[7];

bool is_square() {
	for (int i = 1; i <= 4; i ++) {
		for (int j = i + 1; j <= 4; j ++) {
			if (p[i] == p[j]) return 0;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 4; i ++) {
		for (int j = i + 1; j <= 4; j ++) d[++cnt] = dist(p[i], p[j]);
	}
	sort(d + 1, d + 7);
	return d[1] == d[4] && d[5] == 2 * d[1] && d[6] == 2 * d[1];
}

int main() {
//	freopen("c.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t --) {
		for (int i = 1; i <= 4; i ++) scanf("%d %d %d %d", &A[i].x, &A[i].y, &O[i].x, &O[i].y);
		int ans = 1000;
		for (int i = 1; i <= 4; i ++) {
			A[1] = rot(A[1], O[1]);
			for (int j = 1; j <= 4; j ++) {
				A[2] = rot(A[2], O[2]);
				for (int k = 1; k <= 4; k ++) {
					A[3] = rot(A[3], O[3]);
					for (int l = 1; l <= 4; l ++) {
						A[4] = rot(A[4], O[4]);
						for (int x = 1; x <= 4; x ++) p[x] = A[x];
						if (is_square()) ans = min(ans, i % 4 + j % 4 + k % 4 + l % 4);
					}
				}
			}
		}
		if (ans == 1000) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}