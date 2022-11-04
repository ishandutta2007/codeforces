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
		for(int i = 0; i < n; i ++) {
			scanf("%d", a + i);
			if(a[i] < 0) a[i] = - a[i];
		}
		sort(a, a + n);
		for(int i = 1; i < n; i ++) {
			if(a[i - 1] == a[i]) a[i] = - a[i];
		}
		sort(a, a + n);
		printf("%d\n", unique(a, a + n) - a);
	}
	return 0;
}