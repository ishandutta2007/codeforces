#include <bits/stdc++.h>

using namespace std;

int n, c, X, Y;
int x[4], y[4], xx[4], yy[4];

int _abs(int x) { return x < 0 ? (-x) : x; }

bool ok(int x, int y) { return 1<=x && 1<=y && x<=n && y<=n; }

bool okx(int id) { return ok(x[id], y[id]); }
bool o(int i) {
	int j = (i + 3) % 4;
	return x[i] != xx[j] || y[i] != yy[j];
}

int run() {
	if(c == 1) return 0;
	int cur = 1, rt = 0;
	for(int i = 0; i < 4; i ++) {
		x[i] = xx[i] = X;
		y[i] = yy[i] = Y;
	}
	while(1) {
		rt ++;
		if(okx(0)) {
			if(ok(x[0], y[0] + 1)) y[0] ++; else x[0] --;
			if(ok(xx[0] - 1, yy[0])) xx[0] --; else yy[0] ++;
		}
		if(okx(1)) {
			if(ok(x[1] - 1, y[1])) x[1] --; else y[1] --;
			if(ok(xx[1], yy[1] - 1)) yy[1] --; else xx[1] --;
		}
		if(okx(2)) {
			if(ok(x[2], y[2] - 1)) y[2] --; else x[2] ++;
			if(ok(xx[2] + 1, yy[2])) xx[2] ++; else yy[2] --;
		}
		if(okx(3)) {
			if(ok(x[3] + 1, y[3])) x[3] ++; else y[3] ++;
			if(ok(xx[3], yy[3] + 1)) yy[3] ++; else xx[3] ++;
		}
		if(okx(0)) {
            cur += _abs(x[0] - xx[0]);
			if(o(0)) cur ++;
		}
		if(okx(1)) {
            cur += _abs(x[1] - xx[1]);
			if(o(1)) cur ++;
		}
		if(okx(2)) {
            cur += _abs(x[2] - xx[2]);
			if(o(2)) cur ++;
		}
		if(okx(3)) {
            cur += _abs(x[3] - xx[3]);
			if(o(3)) cur ++;
		}
		if(cur >= c) break;
	}
	return rt;
}

int main() {
	scanf("%d%d%d%d", &n, &X, &Y, &c);
	printf("%d\n", run());
	return 0;
}