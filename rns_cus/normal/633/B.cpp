#include <bits/stdc++.h>
using  namespace std;
#define M 1000010

int a[M], cnt, n;

int main() {
	//freopen("B.in", "r", stdin);
	scanf("%d", &n);

	for (int i = n; i <= 25 * n; i++) {
		int x = i, t = 0;

		while (x) {
			t += (x / 5); x /= 5;
		}

		if (t == n) a[cnt++] = i;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) printf("%d ", a[i]);
}