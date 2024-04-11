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
		scanf("%d %d", &n, &k);
		if(n%2 == 0) {
			printf("YES\n");
			for(i=0; i<n/2; i++) {
				for(j=0; j<k; j++) {
					printf("%d ", 2*k*i+2*j+1);
				}
				printf("\n");
				for(j=0; j<k; j++) {
					printf("%d ", 2*k*i+2*j+2);
				}
				printf("\n");
			}
		} else {
			if(k == 1) {
				printf("YES\n");
				for(i=0; i<n; i++) {
					printf("%d\n", i+1);
				}
			} else {
				printf("NO\n");
			}
		}
	}
}