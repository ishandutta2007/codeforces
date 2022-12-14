#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

typedef double DB;

const int N = 1010;

struct pt {
	int x, y;
}a[N];
DB ans;
int n;

DB calc(pt b, pt a, pt c) {
	DB A = b.y - c.y, B = c.x - b.x;
	DB C = -A * b.x - B * b.y;
	return (A * a.x + B * a.y + C) / sqrt(A * A + B * B) / 2.;
}

int main() {
	n = rd();
	ans = 1e18;
	for (int i = 1; i <= n; i ++) a[i].x = rd(), a[i].y = rd();
	a[n + 1] = a[1], a[n + 2] = a[2];
	for (int i = 1; i <= n; i ++) 
		ans = min(ans, calc(a[i], a[i + 1], a[i + 2]));
	printf("%.10lf", ans);
	return 0;
}