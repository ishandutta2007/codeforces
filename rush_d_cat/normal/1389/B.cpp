#include <bits/stdc++.h>
using namespace std;
int t, n, k, z;
const int N = 100000 + 10;
int a[N];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d%d", &n, &k, &z);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		int sum = a[1], mx = 0, ans = 0;
		for (int i = 2; i <= n; i ++) {
			int r1 = i - 1;
			int rem = k - r1;
			mx = max(mx, a[i-1] + a[i]);

			sum += a[i];

			int tmp = sum;
			if (rem >= 0) {
				if (rem % 2 == 0) {
					tmp += (mx * min(rem / 2, z));	
				} else {
					tmp += (mx * min(rem / 2, z));
					if (rem / 2 < z) tmp += a[i-1];
				}
				ans = max(ans, tmp);
			}
			
			//printf("i = %d, tmp = %d\n", i, tmp);
		}
		printf("%d\n", ans);
	}
}