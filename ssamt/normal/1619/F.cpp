#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d %d", &n, &m, &k);
		for(i=0; i<k; i++) {
			for(j=0; j<n%m; j++) {
				printf("%d ", n/m+1);
				for(l=0; l<n/m+1; l++) {
					printf("%d ", (n%m*(n/m+1)*i+(n/m+1)*j+l)%n+1);
				}
				printf("\n");
			}
			for(j=0; j<m-n%m; j++) {
				printf("%d ", n/m);
				for(l=0; l<n/m; l++) {
					printf("%d ", (n%m*(n/m+1)*(i+1)+(n/m)*j+l)%n+1);
				}
				printf("\n");
			}
		}
		printf("\n");
	}
}