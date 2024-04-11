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
		int pos = 1;
		for(i=0; i<n; i++) {
			int check = 0;
			for(j=i+2; j>=2; j--) {
				if(a[i]%j != 0) {
					check = 1;
					break;
				}
			}
			if(!check) {
				pos = 0;
				break;
			}
		}
		if(pos) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}