#include <stdio.h>
#include <stdlib.h>
#include <vector>

int mu(int n) {
	int count = 0;
	int div;
	for(div=2; div*div<=n; div++) {
		if(n%div == 0) {
			count++;
			n /= div;
			if(n%div == 0) {
				return 0;
			}
		}
	}
	if(n != 1) {
		count++;
	}
	if(count%2 == 0) {
		return 1;
	} else {
		return -1;
	}
}

int main() {
	int h, i, j, k;
	int n, m;
	scanf("%d %d", &n, &m);
	int l[n];
	int r[n];
	long long d[n][m+1];
	long long sum[m+1];
	long long answer = 0;
	long long mod = 998244353;
	for(i=0; i<n; i++) {
		scanf("%d %d", &l[i], &r[i]);
	}
	for(i=1; i<=m; i++) {
		int muval = mu(i);
		if(muval != 0) {
			for(j=0; j<=m/i; j++) {
				if((l[0]-1)/i+1 <= j && j <= r[0]/i) {
					d[0][j] = 1;
				} else {
					d[0][j] = 0;
				}
			}
			for(j=1; j<n; j++) {
				sum[0] = d[j-1][0];
				for(k=1; k<=m/i; k++) {
					sum[k] = (sum[k-1]+d[j-1][k])%mod;
				}
				for(k=0; k<=m/i; k++) {
					long long left, right;
					if(k-r[j]/i <= 0) {
						left = 0;
					} else {
						left = sum[k-r[j]/i-1];
					}
					if(k-((l[j]-1)/i+1) <= 0) {
						right = 0;
					} else {
						right = sum[k-((l[j]-1)/i+1)];
					}
					d[j][k] = (mod+right-left)%mod;
				}
			}
			long long total = 0;
			for(j=0; j<=m/i; j++) {
				total = (total+d[n-1][j])%mod;
			}
			if(muval == 1) {
				answer = (answer+total)%mod;
			} else {
				answer = (mod+answer-total)%mod;
			}
		}
	}
	printf("%lld", answer);
}