#include <cstdio>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

int query(int x1, int y1, int x2, int y2){
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int t;
	scanf("%d", &t);
	return t;
}

PII split(int n, int m){
	int r = 1;
	for (int step = 1 << 15; step; step >>= 1)
		if (r + step <= n && query(1, 1, r + step, m) == 0)
			r += step;
	r += query(1, 1, r, m) == 0;
	if (r < n && query(1, 1, r, m) == query(r + 1, 1, n, m))
		return PII(0, r);
	r = 1;
	for (int step = 1 << 15; step; step >>= 1)
		if (r + step <= m && query(1, 1, n, r + step) == 0)
			r += step;
	r += query(1, 1, n, r) == 0;
	return PII(1, r);
}

void getRect(int x1, int y1, int x2, int y2, int x[], int y[]){
	for (int step = 1 << 15; step; step >>= 1)
		if (x1 + step <= x2 && query(x1 + step, y1, x2, y2) == 1)
			x1 += step;
	for (int step = 1 << 15; step; step >>= 1)
		if (x1 + step <= x2 && query(x1, y1, x2 - step, y2) == 1)
			x2 -= step;
	for (int step = 1 << 15; step; step >>= 1)
		if (y1 + step <= y2 && query(x1, y1 + step, x2, y2) == 1)
			y1 += step;
	for (int step = 1 << 15; step; step >>= 1)
		if (y1 + step <= y2 && query(x1, y1, x2, y2 - step) == 1)
			y2 -= step;
	x[0] = x1, y[0] = y1;
	x[1] = x2, y[1] = y2;
}

int main(){
	int n;
	scanf("%d", &n);
	PII res = split(n, n);
	int x[4], y[4], r = res.nd;
	if (res.st == 0){
		getRect(1, 1, r, n, x, y);
		getRect(r + 1, 1, n, n, x + 2, y + 2);
	}
	else{
		getRect(1, 1, n, r, x, y);
		getRect(1, r + 1, n, n, x + 2, y + 2);
	}
	putchar('!');
	for (int i = 0; i < 4; ++i)
		printf(" %d %d", x[i], y[i]);
	puts("");
	fflush(stdout);
	return 0;
}