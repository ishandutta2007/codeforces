#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		if(n >= 2*k-1) {
			for(i=0; i<n; i++) {
				for(j=0; j<n; j++) {
					if(i == j && i%2 == 0 && i <= 2*k-2) {
						printf("R");
					} else {
						printf(".");
					}
				}
				printf("\n");
			}
		} else {
			printf("-1\n");
		}
	}
}