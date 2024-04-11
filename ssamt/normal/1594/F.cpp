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
	long long s, t, n, m, k;
	scanf("%lld", &t);
	for(h=0; h<t; h++) {
		scanf("%lld %lld %lld", &s, &n, &k);
		long long b = ((s/k+2)/2)*(s%k+1);
		b += ((s/k+1)/2)*(k-(s%k+1));
		if(b < n+1 || s == k) {
			printf("YES\n");
		} else{
			printf("NO\n");
		}
	}
}