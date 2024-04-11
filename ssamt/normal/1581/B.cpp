#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k;
	scanf("%d", &t);
	for(i=0; i<t; i++) {
		scanf("%d %d %d", &n, &m, &k);
		bool answer;
		if(n == 1) {
			answer = (0 <= k-2 && m == 0);
		} else {
			if(0 >= k-2) {
				answer = false;
			} else if(1 == k-2) {
				answer = (m == (long long)n*(n-1)/2);
			} else if(2 <= k-2) {
				answer = ((long long)n*(n-1)/2 >= m && m >= n-1);
			}
		}
		if(answer) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}