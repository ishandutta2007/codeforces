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
	int t, n, k;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	int m[512] = {};
	for(i=1; i<512; i++) {
		m[i] = -1;
	}
	for(i=0; i<n; i++) {
		for(j=0; j<512; j++) {
			if(a[i] > m[j] && m[j] != -1) {
				if(m[j^a[i]] == -1) {
					m[j^a[i]] = a[i];
				} else {
					m[j^a[i]] = min(m[j^a[i]], a[i]);
				}
			}
		}
	}
	int count = 0;
	for(i=0; i<512; i++) {
		if(m[i] != -1) {
			count++;
		}
	}
	printf("%d\n", count);
	for(i=0; i<512; i++) {
		if(m[i] != -1) {
			printf("%d ", i);
		}
	}
	printf("\n");
}