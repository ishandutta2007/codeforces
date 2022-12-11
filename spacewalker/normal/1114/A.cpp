#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int x, y, z; scanf("%d %d %d", &x, &y, &z);
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	if (x > a) {printf("NO\n"); return 0;}
	else {
		int nonBlack = (a - x) + b;
		if (y > nonBlack) {printf("NO\n"); return 0;}
		else {
			int rem = (a + b + c) - (x + y);
			if (z > rem) printf("NO\n");
			else printf("YES\n");
		}
	}
	return 0;
}