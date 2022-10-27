#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, a[N];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int c[102] = {0};
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]); c[a[i]] ++;
		}

		int ans = 0;
		for (int i = 0;; i ++) {
			if (c[i] > 0) {
				-- c[i];
			} else {
				ans += i; break;
			}
		}
		for (int i = 0;; i ++) {
			if (c[i] > 0) {
				-- c[i];
			} else {
				ans += i; break;
			}
		}
		printf("%d\n", ans);
	}	
}