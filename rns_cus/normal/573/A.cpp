#include <bits/stdc++.h>

using namespace std;

#define N 100010

int sto[N];

main() {
//	freopen("A.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		int x;
		scanf("%d", &x);
		while (x % 2 == 0) x /= 2;
		while (x % 3 == 0) x /= 3;
		sto[i] = x;
	}
	sort(sto + 1, sto + n + 1);
	puts(sto[1] == sto[n] ? "Yes" : "No");
}