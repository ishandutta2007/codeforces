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
		if(n == 3) {
			printf("3 2 1\n");
			printf("1 3 2\n");
			printf("3 1 2\n");
		} else {
			for(i=0; i<n; i++) {
				for(j=0; j<n; j++) {
					printf("%d ", (i+n-j)%n+1);
				}
				printf("\n");
			}
		}
	}
}