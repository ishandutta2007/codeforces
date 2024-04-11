#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main() {
	int h, i, j;
	int t, n, m;
	int idx;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
        scanf("%d", &n);
        for(i=1; 2*i<=n; i*=2);
        printf("%d\n", i-1);
	}
}