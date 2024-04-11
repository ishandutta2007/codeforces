#include <bits/stdc++.h>
using namespace std;

struct pnt {
	int x, y;
	pnt operator = (const pnt &B) {
		x = B.x;
		y = B.y;
	}
	pnt operator + (const pnt &B) {
		pnt C;
		C.x = x + B.x;
		C.y = y + B.y;
		return C;
	}
} p[5], q[5], d[5];

int dist2(pnt A, pnt B) {
	return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

bool right(pnt A, pnt B, pnt C) {
	int a = dist2(B, C), b = dist2(C, A), c = dist2(A, B);
	if (!a || !b || !c) return 0;
	if (a + b == c || a + c == b || b + c == a) return 1;
	return 0;
}

bool almost() {
	for (int i = 0; i < 3; i ++) {
		q[(i+1)%3] = p[(i+1)%3], q[(i+2)%3] = p[(i+2)%3];
		for (int j = 0; j < 4; j ++) {
			q[i] = p[i] + d[j];
			if (right(q[0], q[1], q[2])) return 1;
		}
	}
	return 0;
}

int main() {
//	freopen("a.in", "r", stdin);
	d[0].x = 0, d[0].y = 1;
	d[1].x = 0, d[1].y = -1;
	d[2].x = 1, d[2].y = 0;
	d[3].x = -1, d[3].y = 0;
	for (int i = 0; i < 3; i ++) scanf("%d %d", &p[i].x, &p[i].y);
	if (right(p[0], p[1], p[2])) puts("RIGHT");
	else if (almost()) puts("ALMOST");
	else puts("NEITHER");
	return 0;
}