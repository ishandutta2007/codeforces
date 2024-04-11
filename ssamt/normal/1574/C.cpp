#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int h, i, j;
	int t, n, m;
	int in;
	scanf("%d", &n);
	long long a[n];
	for(i=0; i<n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a+n);
	scanf("%d", &m);
	long long x[m];
	long long y[m];
	for(i=0; i<m; i++) {
		scanf("%lld %lld", &x[i], &y[i]);
	}
	long long sum = 0;
	for(i=0; i<n; i++) {
		sum += a[i];
	}
	for(i=0; i<m; i++) {
		int idx = lower_bound(a, a+n, x[i])-a;
		long long answer = LLONG_MAX;
		long long pos = 0;
		if(idx != n) {
			if(a[idx] < x[i]) {
				pos += x[i]-a[idx];
			}
			if(sum-a[idx] < y[i]) {
				pos += y[i]-(sum-a[idx]);
			}
			answer = min(answer, pos);
		}
		if(idx != 0) {
			pos = 0;
			if(a[idx-1] < x[i]) {
				pos += x[i]-a[idx-1];
			}
			if(sum-a[idx-1] < y[i]) {
				pos += y[i]-(sum-a[idx-1]);
			}
			answer = min(answer, pos);
		}
		printf("%lld\n", answer);
	}
}