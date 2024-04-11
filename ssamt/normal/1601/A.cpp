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
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int count[30] = {};
		for(i=0; i<n; i++) {
			for(j=0; j<30; j++) {
				if(a[i]&(1<<j)) {
					count[j]++;
				}
			}
		}
		for(i=1; i<=n; i++) {
			int check = 1;
			for(j=0; j<30; j++) {
				if(count[j]%i != 0) {
					check = 0;
				}
			}
			if(check) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
}