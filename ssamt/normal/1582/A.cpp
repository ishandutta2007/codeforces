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
	long long a, b, c;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		long long sum = 1*a+2*b+3*c;
		long long half = sum/2;
		half = max(half-3*c, half%3);
		half = max(half-2*b, half%2);
		half = max(half-1*a, half%1);
		printf("%lld\n", sum-2*(sum/2-half));
	}
}