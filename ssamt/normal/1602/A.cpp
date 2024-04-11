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
	scanf("%d", &n);
	for(h=0; h<n; h++) {
		char s[101];
		scanf("%s", s);
		int min_idx = 0;
		for(i=1; s[i]; i++) {
			if(s[i] < s[min_idx]) {
				min_idx = i;
			}
		}
		printf("%c", s[min_idx]);
		printf(" ");
		for(i=0; s[i]; i++) {
			if(i != min_idx) {
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}
}