#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main() {
	int h, i, j, l, r;
	int t, n, m, k;
	long long p;
	int num = 100;
	scanf("%d %d %d %lld", &n, &m, &k, &p);
	long long mem[n+1][m+1][k+1]; //n, m ,k
	long long comb[n+1][n+1];
	long long fac[n+1];
	fac[0] = 1;
	for(i=1; i<=n; i++) {
		fac[i] = (fac[i-1]*i)%p;
	}
	long long sum = 0;
	for(i=0; i<=n; i++) {
		comb[i][0] = 1;
		for(j=1; j<i; j++) {
			comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%p;
		}
		comb[i][i] = 1;
	}
	if(k > n) {
		mem[n][m][k] = 0;
	} else if(m > n) {
		mem[n][m][k] = 0;
	} else if(m+k > n+1) {
		mem[n][m][k] = 0;
	} else {
		for(i=0; i<=n; i++) {
			for(j=0; j<=m; j++) {
				for(l=0; l<=k; l++) {
					if(i == 0) {
						if(l == 0) {
							mem[i][j][l] = 1;
						} else {
							mem[i][j][l] = 0;
						}
					} else if(j == 0) {
						if(l == 0) {
							mem[i][j][l] = (mem[i-1][j][l]*i)%p;
						} else {
							mem[i][j][l] = 0;
						}
					} else if(l > i) {
						mem[i][j][l] = 0;
					} else if(j > i) {
						if(l == 0) {
							mem[i][j][l] = mem[i][0][0];
						} else {
							mem[i][j][l] = 0;
						}
					} else if(j+l > i+1) {
						mem[i][j][l] = 0;
					} else {
						mem[i][j][l] = 0;
						for(h=1; h<=i; h++) {
							sum = 0;
							if(j == 1) {
								for(r=0; 2*r<l-1; r++) {
									if(mem[h-1][j-1][r] && mem[i-h][j-1][l-r-1]) {
										sum += (mem[h-1][j-1][r]*mem[i-h][j-1][l-r-1])<<1;
										sum %= p;
									}
								}
								if((l-1)%2 == 0) {
									if(mem[h-1][j-1][r] && mem[i-h][j-1][l-r-1]) {
										sum += (mem[h-1][j-1][r]*mem[i-h][j-1][l-r-1]);
										sum %= p;
									}
								}
							} else {
								for(r=0; 2*r<l; r++) {
									if(mem[h-1][j-1][r] && mem[i-h][j-1][l-r]) {
										sum += (mem[h-1][j-1][r]*mem[i-h][j-1][l-r])<<1;
										sum %= p;
									}
								}
								if(l%2 == 0) {
									if(mem[h-1][j-1][r] && mem[i-h][j-1][l-r]) {
										sum += (mem[h-1][j-1][r]*mem[i-h][j-1][l-r]);
										sum %= p;
									}
								}
							}
							mem[i][j][l] += sum*comb[i-1][h-1];
							mem[i][j][l] %= p;
						}
					}
					//printf("%d %d %d %lld\n", i, j, l, mem[i][j][l]);
					//printf("%d", (mem[i][j][l]>0));
				}
				//printf("\n");
			}
			//printf("\n");
		}
	}
	printf("%lld\n", mem[n][m][k]);
}