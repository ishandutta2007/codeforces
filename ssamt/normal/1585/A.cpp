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
		int height = 1;
		int dead = 0;
		for(i=0; i<n; i++) {
			if(i > 0) {
				if(a[i] == 1 && a[i-1] == 1) {
					height += 5;
				} else if(a[i] == 1 && a[i-1] == 0) {
					height += 1;
				} else if(a[i] == 0 && a[i-1] == 0) {
					dead = 1;
				}
			} else {
				if(a[i] == 1) {
					height += 1;
				}
			}
		}
		if(dead) {
			printf("%d\n", -1);
		} else {
			printf("%d\n", height);
		}
	}
}