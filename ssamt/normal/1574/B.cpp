#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int h, i, j;
	int t, a, b, c, m;
	int in;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d %d %d", &a, &b, &c, &m);
		if(m > a-1+b-1+c-1) {
			printf("NO\n");
		} else {
			int maxval = max(a, max(b, c));
			if(m < maxval-(a+b+c-maxval+1)) {
				printf("NO\n");
			} else {
				printf("YES\n");
			}
		}
	}
	
}