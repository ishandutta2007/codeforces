#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int pow_mod(int a, int k, int mod) {
	if(k == 0) {
		return 1;
	}
	int sub = pow_mod(a, k/2, mod);
	if(k%2 == 0) {
		return ((long long)sub*sub)%mod;
	} else {
		return (((long long)sub*sub)%mod*a)%mod;
	}
}

int main() {
	int h, i, j, k;
	int t, n;
	int mod = 1000000007;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		int b[n];
		int idx[n+1];
		int check[n];
		int count = 0;
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			idx[a[i]] = i;
		}
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		for(i=0; i<n; i++) {
			check[i] = 0;
		}
		for(i=0; i<n; i++) {
			if(!check[i]) {
				for(j=i; idx[b[j]]!=i; j=idx[b[j]]) {
					check[j] = 1;
				}
				check[j] = 1;
				count++;
			}
		}
		printf("%d\n", pow_mod(2, count, mod));
	}
}