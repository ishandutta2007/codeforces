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
	int h, i, j, l;
	int t, n, s, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &s);
		if(n%2 == 0) {
			printf("%d\n", s/(n/2+1));
		} else {
			printf("%d\n", s/(n/2+1));
		}
	}
}