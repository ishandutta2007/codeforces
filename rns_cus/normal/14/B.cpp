#include <bits/stdc++.h>
using namespace std;

int n, x, a, b;

int main() {
	scanf("%d %d", &n, &x);
	int mn = 0, mx = 1000;
	while (n --) {
		scanf("%d %d", &a, &b);
		if (a > b) swap(a, b);
		mx = min(mx, b), mn = max(mn, a);
	}
	printf("%d\n", mn > mx ? -1 : mn <= x && x <= mx ? 0 : x < mn ? mn - x : x - mx);
	return 0;
}