#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 102;
int t, n, a[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			if (i % 2 == 1) printf("%d ", abs(a[i]));
			else printf("%d ", -abs(a[i]));
		}
		printf("\n");
	}
}