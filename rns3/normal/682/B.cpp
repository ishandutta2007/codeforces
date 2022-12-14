#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, a[N];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int j = 1;
	for (int i = 1; i <= n + 1; i ++) {
		if (j == n + 1) {
			printf("%d\n", i); return 0;
		}
        j = lower_bound(a + j, a + n + 1, i) - a;
        if (j == n + 1) {
			printf("%d\n", i); return 0;
        }
        j ++;
	}
	return 0;
}