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
#include <functional>

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k;
	int count;
	int max_count;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		max_count = 0;
		for(i=0; i<n; i++) {
			count = 0;
			for(j=0; j<n; j++) {
				if(a[i] == a[j]) {
					count++;
				}
			}
			max_count = max(max_count, count);
		}
		if(max_count >= n/2) {
			printf("-1\n");
		} else {
			int answer = 0;
			sort(a, a+n);
			for(i=0; i<n; i++) {
				for(j=0; j<n; j++) {
					if(a[i] != a[j]) {
						set<int> div;
						int diff = a[j]-a[i];
						for(k=1; k*k<=diff; k++) {
							if(diff%k == 0) {
								div.insert(k);
								div.insert(diff/k);
							}
						}
						for(int d:div) {
							count = 0;
							for(k=i; k<n; k++) {
								diff = a[k]-a[i];
								if(diff%d == 0) {
									count++;
								}
							}
							if(count >= n/2) {
								answer = max(answer, d);
							}
						}
					}
				}
			}
			printf("%d\n", answer);
		}
	}
}