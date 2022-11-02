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
	int t, n, m, k, q;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n][5];
		for(i=0; i<n; i++) {
			for(j=0; j<5; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for(i=0; i<5; i++) {
			for(j=i+1; j<5; j++) {
				int count[2] = {};
				int check = true;
				for(l=0; l<n; l++) {
					if(a[l][i] == 0 && a[l][j] == 0) {
						check = false;
						break;
					}
					if(a[l][i] == 1) {
						count[0]++;
					}
					if(a[l][j] == 1) {
						count[1]++;
					}
				}
				if(count[0] < n/2 || count[1] < n/2) {
					check = false;
				}
				if(check) {
					printf("YES\n");
					goto OUT;
				}
			}
		}
		printf("NO\n");
OUT:;
	}
}