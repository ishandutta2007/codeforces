#include <bits/stdc++.h>
using namespace std;

int t, s, x;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d %d", &t, &s, &x);
	if (x < t) {
		puts("NO"); return 0;
	}
	x -= t;
    if (x == 1) puts("NO");
    else printf("%s\n", x % s == 0 || x % s == 1 ? "YES" : "NO");
	return 0;
}