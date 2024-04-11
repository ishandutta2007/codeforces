#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		if(a[0] == n) {
			for(i=n-1; i>=1; i--) {
				printf("%d ", a[i]);
			}
			printf("%d\n", n);
		} else if(a[n-1] == n) {
			for(i=n-2; i>=0; i--) {
				printf("%d ", a[i]);
			}
			printf("%d\n", n);
		} else {
			printf("-1\n");
		}
	}
}