//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n, a[51];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		int mi = 0x3f3f3f3f;
		for(int i=2;i<=n;i++) {
			mi = min(mi, a[i]-a[i-1]);
		}
		printf("%d\n", mi);
	}
	return 0;
}