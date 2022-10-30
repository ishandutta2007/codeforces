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
		scanf("%d %d", &n, &q);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int answer = 0;
		int b[n] = {};
		int c = 0;
		for(i=n-1; c<q && i>=0; i--) {
			if(a[i] > c) {
				c++;
			}
			b[i] = 1;
		}
		answer = n-1-i;
		for(; i>=0; i--) {
			if(a[i] <= q) {
				answer++;
				b[i] = 1;
			}
		}
		for(i=0; i<n; i++) {
			printf("%d", b[i]);
		}
		printf("\n");
	}
}