#include<bits/stdc++.h>
using namespace std;
int a[111];
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i ++) scanf("%d", a + i);
		if(n <= 2) {
			puts("0");
			continue;
		}
		int ans = n;
		for(int i = 0; i < n; i ++) {
			for(int j = i + 1; j < n; j ++) {
				int tmp = 0;
				for(int k = 0; k < n; k ++) if(k != i && k != j && (a[j] - a[i]) * (k - i) != (a[k] - a[i]) * (j - i)) tmp ++;
				if(tmp < ans) ans = tmp;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}