#include <bits/stdc++.h>
using namespace std;
#define M 100100

int n;
int m;
int b[M], a[M];

int main() {
	//freopen("A2.in", "r", stdin);
	scanf("%d", &n);
	scanf("%d", &m);
	for (int x, i = 0; i < n; i++) {
		x = 2 * n + 1 + 2 * i;
		if (x <= m) printf("%d ", x);
		x = 1 + 2 * i;
		if (x <= m) printf("%d ", x);
		x = 2 * n + 2 + 2 * i;
		if (x <= m) printf("%d ", x);
		x = 2 + 2 * i;
		if (x <= m) printf("%d ", x);
	}
	return 0;
}