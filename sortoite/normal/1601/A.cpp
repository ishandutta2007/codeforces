#include <bits/stdc++.h>

using namespace std;
int cnt[40];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int T; cin >> T;
	while(T --) {
		int n; scanf("%d", &n);
		int m = 31;
		memset(cnt, 0, sizeof cnt);
		for(int i = 0; i < n; i ++) {
			int a; scanf("%d", &a);
			for(int j = 0; j < m; j ++) {
				if(a & 1) cnt[j] ++;
				a >>= 1;
			}
		}
		for(int i = 1; i <= n; i ++) {
			int ok = true;
			for(int j = 0; j < m; j ++) if(cnt[j] % i) {
				ok = false;
				break;
			}
			if(ok) printf("%d ", i);
		}
		puts("");
	}
	return 0;
}