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
		int c = 0;
		for(i=1; i<n-1; i++) {
			if(a[i] > a[i-1] && a[i] > a[i+1]) {
				if(i != n-2) {
					a[i+1] = max(a[i], a[i+2]);
				} else {
					a[i+1] = a[i];
				}
				c++;
			}
		}
		printf("%d\n", c);
		for(i=0; i<n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}