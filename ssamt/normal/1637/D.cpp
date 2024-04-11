#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	int size = 101;
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n], b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		int sum = 0;
		for(i=0; i<n; i++) {
			sum += a[i]+b[i];
		}
		int d[n][size*n];
		for(i=0; i<n; i++) {
			for(j=0; j<size*n; j++) {
				d[i][j] = -1;
			}
		}
		d[0][a[0]] = 0;
		d[0][b[0]] = 1;
		for(i=0; i<n-1; i++) {
			for(j=0; j<size*n; j++) {
				if(d[i][j] != -1) {
					if(j+a[i+1] < size*n) {
						d[i+1][j+a[i+1]] = 0;
						//printf("%d %d %d\n", i+1, j+a[i+1], 0);
					}
					if(j+b[i+1] < size*n) {
						d[i+1][j+b[i+1]] = 1;
						//printf("%d %d %d\n", i+1, j+b[i+1], 1);
					}
				}
			}
		}
		int best = 0;
		for(i=0; i<size*n; i++) {
			if(d[n-1][i] != -1 && abs(sum-2*i) < abs(sum-2*best)) {
				best = i;
			}
		}
		//printf("%d\n", best);
		int choice[n];
		int idx = best;
		for(i=n-1; i>=0; i--) {
			choice[i] = d[i][idx];
			if(choice[i] == 0) {
				idx -= a[i];
			} else {
				idx -= b[i];
			}
		}
		/*for(i=0; i<n; i++) {
			printf("%d ", choice[i]);
		}
		printf("\n");*/
		int sum1 = 0, sum2 = 0;
		int sqsum = 0;
		long long answer = 0;
		for(i=0; i<n; i++) {
			if(choice[i] == 0) {
				sum1 += a[i];
				sum2 += b[i];
			} else {
				sum2 += a[i];
				sum1 += b[i];
			}
			sqsum += a[i]*a[i];
			sqsum += b[i]*b[i];
		}
		answer += (long long)sum1*sum1+(long long)sum2*sum2;
		answer += (n-2)*sqsum;
		printf("%lld\n", answer);
	}
}