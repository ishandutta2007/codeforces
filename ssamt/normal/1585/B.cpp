#include <stdio.h>
#include <limits.h>
#include <time.h>
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
	int h, i, j;
	int t, n, m, k, q;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int max_val = a[n-1];
		int count = 0;
		for(i=n-2; i>=0; i--) {
			if(a[i] > max_val) {
				max_val = a[i];
				count++;
			}
		}
		printf("%d\n", count);
	}
}