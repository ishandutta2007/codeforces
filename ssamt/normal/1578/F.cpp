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

long long ipow(int base, int pow)
{
	int i;
	long long answer = 1;
	for(i=0; i<pow; i++)
		answer *= base;
	return answer;
}

int main() {
	int h, i, j, l;
	int t, n, m, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		int zero = 0, one = 0;
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			scanf("%d", &k);
			if(k == 0) {
				zero++;
			} else if(k == 1) {
				one++;
			}
		}
		printf("%lld\n", ipow(2, zero)*one);
	}
}