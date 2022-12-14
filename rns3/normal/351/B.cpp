#include <bits/stdc++.h>
using namespace std;

#define N 3030

int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j ++) {
		if (a[i] > a[j]) cnt ++;
	}
	if (cnt % 2) {
		printf("%.6lf\n", cnt * 2 - 1.0);
	}
	else printf("%.6lf\n", cnt * 2.0);
	return 0;
}