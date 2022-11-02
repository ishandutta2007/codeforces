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
		scanf("%d", &n);
		char a[2][n+1];
		scanf("%s", a[0]);
		scanf("%s", a[1]);
		int pos = 1;
		for(i=0; i<n; i++) {
			if(a[0][i] == '1' && a[1][i] == '1') {
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