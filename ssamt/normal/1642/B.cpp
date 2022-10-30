#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		int count = 1;
		for(i=1; i<n; i++) {
			if(a[i-1] != a[i]) {
				count++;
			}
		}
		for(i=1; i<=n; i++) {
			printf("%d ", max(count, i));
		}
		printf("\n");
	}
}