#include <bits/stdc++.h>
using namespace std;

int n, m, c;

#define N 1010

int a[N];

int main() {
	scanf("%d %d %d", &n, &m, &c);
	memset(a, -1, sizeof a);
	bool rv = 0;
	for (int step = 1, x; step <= m; step ++) {
		scanf("%d", &x);
		if (x <= c / 2) {
			int i = 1;
			while (i < n && a[i] != -1 && a[i] <= x) i ++;
			a[i] = x;
			printf("%d\n", i);
			fflush(stdout);
		}
		else {
			int i = n;
			while (i > 1 && a[i] != -1 && a[i] >= x) i --;
			a[i] = x;
			printf("%d\n", i);
			fflush(stdout);
		}
	}

	return 0;
}