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
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		int b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		int m[n];
		m[0] = b[0];
		for(i=1; i<n; i++) {
			m[i] = max(m[i-1], b[i]);
		}
		int answer = 2*n;
		for(i=0; i<n; i++) {
			int idx = lower_bound(m, m+n, a[i])-m;
			answer = min(answer, i+idx);
		}
		printf("%d\n", answer);
	}
}