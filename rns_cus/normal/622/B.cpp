#include <bits/stdc++.h>
using namespace std;

int n, m, t;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d:%d %d", &n, &m, &t);
	int ans = n * 60 + m + t;
	ans %= 24 * 60;
	printf("%02d:%02d\n", ans / 60, ans % 60);
	return 0;
}