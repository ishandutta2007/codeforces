#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int cmp(const void* num1, const void* num2) {
	int* a = *(int**)num1;
	int* b = *(int**)num2;
	if(a[0] > b[0]) {
		return 1;
	} else if(a[0] < b[0]) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	int h, i, j;
	int n;
	scanf("%d", &n);
	int p[n][3];
	long long answer;
	long long mod = 998244353;
	for(i=0; i<n; i++) {
		for(j=0; j<3; j++) {
			scanf("%d", &p[i][j]);
		}
	}
	int* pos[2*n];
	for(i=0; i<n; i++) {
		pos[2*i] = (int*)malloc(3*sizeof(int));
		pos[2*i][0] = p[i][0];
		pos[2*i][1] = 0;
		pos[2*i][2] = i;
		pos[2*i+1] = (int*)malloc(3*sizeof(int));
		pos[2*i+1][0] = p[i][1];
		pos[2*i+1][1] = 1;
		pos[2*i+1][2] = i;
	}
	qsort(pos, 2*n, sizeof(int*), cmp);
	answer = p[n-1][0]+1;
	long long sum = 0;
	long long jump[n];
	for(i=2*n-1; i>=0; i--) {
		int idx = pos[i][2];
		if(pos[i][1] == 0) {
			jump[idx] = (sum+p[idx][2])%mod;
			answer = (answer+jump[idx]*(p[idx][0]-p[idx][1]))%mod;
			sum = (sum+jump[idx])%mod;
		} else {
			sum = (mod+sum-jump[idx])%mod;
		}
	}
	printf("%lld", answer);
}