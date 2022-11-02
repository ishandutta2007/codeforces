#include <bits/stdc++.h>
using namespace std;

bool leap(int x) {
	if (x % 400 == 0) return 1;
	if (x % 100 == 0) return 0;
	return x % 4 == 0;
}

int x, y;

bool same(int i) {
	if (x) return 0;
	return (leap(y) && leap(i)) || (!leap(y) && !leap(i));
}

int calc() {
	x = 0;
	for (int i = y + 1; i <= y + 1000000; i ++) {
		if (leap(i - 1)) x = (x + 2) % 7;
		else x = (x + 1) % 7;
		if (same(i)) return i;
	}
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &y);
	printf("%d\n", calc());
	return 0;
}