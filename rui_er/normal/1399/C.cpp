#include <bits/stdc++.h>
using namespace std;

int T, n, w[55], bk[55], book[55];

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(bk, 0, sizeof(bk));
		memset(book, 0, sizeof(book));
		scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			scanf("%d", &w[i]);
			++bk[w[i]];
		}
		int ans = 0;
		for(int k=2;k<=2*n;k++) {
			for(int i=1;i<=n;i++) book[i] = bk[i];
			int s = 0;
			for(int i=1;i<=n;i++) {
				if(k - i <= 0 || k - i > n) continue;
				if(i == k - i){
					int _ = book[i] / 2;
					s += _;
					book[i] -= 2 * _;
				}
				else {
					int _ = min(book[i], book[k-i]);
					s += _;
					book[i] -= _;
					book[k-i] -= _;
				}
			}
			ans = max(ans, s);
		}
		printf("%d\n", ans);
	}
	return 0;
}