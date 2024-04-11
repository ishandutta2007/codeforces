#include <bits/stdc++.h>
using namespace std;

int calc(int a, int b) {
	if (!b) return 0;
	return a / b + calc(b, a % b);
}

int main() {
//	freopen("a.in", "r", stdin);
	int t, a, b;
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &a, &b);
		if (b > a) swap(a, b);
		printf("%d\n", calc(a, b));
	}
	return 0;
}