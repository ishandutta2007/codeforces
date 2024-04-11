#include <bits/stdc++.h>

using namespace std;

int ask(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int d;
	scanf("%d", &d);
	return d;
}

int main() {
//	freopen("in.txt", "r", stdin);
	const int e = 1e9;
	int lu = ask(1, 1), ld = ask(e, 1), ru = ask(1, e), rd = ask(e, e);
	int l = ((1 + lu) + (e - ld)) / 2, r = ((1 + ru) + (e - rd)) / 2;
	int u = ((1 + lu) + (e - ru)) / 2, d = ((1 + ld) + (e - rd)) / 2;
	int dl = ask(l, 1), dr = ask(r, e), du = ask(1, u), dd = ask(e, d);
	printf("! %d %d %d %d\n", 1 + du, 1 + dl, e - dd, e - dr);
	fflush(stdout);
	return 0;
}