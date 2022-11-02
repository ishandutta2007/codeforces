#include <bits/stdc++.h>
using namespace std;

int a1, a2, b1, b2, c1, c2;

inline bool parallel() {return a1 * b2 == a2 * b1;}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d %d", &a1, &b1, &c1);
	scanf("%d %d %d", &a2, &b2, &c2);
if (!a1 && !b1 && c1 || !a2 && !b2 && c2) {
puts("0"); return 0;
}
	if (!a1 && !b1) {
		printf("%d\n", c1 ? 0 : -1); return 0;
	}
	else if (!a2 && !b2) {
		printf("%d\n", c2 ? 0 : -1); return 0;
	}
	if (!parallel()) {
		puts("1"); return 0;
	}
	printf("%d\n", (a1 && a1 * c2 == a2 * c1 || b1 && b1 * c2 == b2 * c1) ? -1 : 0);
	return 0;
}