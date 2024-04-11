#include <bits/stdc++.h>
using namespace std;

int T, n, a[55];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		bool _ = true;
		for(int i=2;i<=n;i++) {
			if(a[i] - a[i-1] > 1) {
				puts("NO");
				_ = false;
				break;
			}
		}
		if(_) puts("YES");
	}
	return 0;
}