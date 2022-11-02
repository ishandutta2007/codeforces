#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &k);
		int x[k];
		for(i=0; i<k; i++) {
			scanf("%d", &x[i]);
		}
		sort(x, x+k);
		int sum = 0;
		for(i=k-1; i>=0 && sum<n; i--) {
			sum += n-x[i];
		}
		if(sum < n) {
			printf("%d\n", k);
		} else {
			printf("%d\n", k-(i+2));
		}
	}
}