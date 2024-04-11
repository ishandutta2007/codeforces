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

using namespace std;

int main() {
	int h, i, j, l;
	int t, m, k;
	long long n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%lld", &n);
		printf("%lld %lld\n", -n+1, n);
	}
}