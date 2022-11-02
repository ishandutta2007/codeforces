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
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if(b == 1) {
			printf("NO\n");
		} else {
			printf("YES\n");
			printf("%lld %lld %lld\n", a, a*(2*b-1), a*2*b);
		}
	}
}