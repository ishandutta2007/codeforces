#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main() {
	int h, i, j;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		std::vector<int> d;
		while(n > 0) {
			d.push_back(n%10);
			n /= 10;
		}
		if(d.size()%2 == 1) {
			d.push_back(0);
		}
		int a[2] = {};
		for(i=d.size()-2; i>=0; i-=2) {
			for(j=0; j<2; j++) {
				a[j] *= 10;
				a[j] += d[i+j];
			}
		}
		printf("%d\n", (a[0]+1)*(a[1]+1)-2);
	}
}