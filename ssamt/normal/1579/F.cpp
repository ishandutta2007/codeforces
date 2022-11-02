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

long long gcd(long long num1, long long num2)//greatest common divisor
{
	if(num1 == 0)
		return num2;
	if(num2 == 0)
		return num1;
	if(num1<0)
		return gcd(-num1, num2);
	if(num2<0)
		return gcd(num1, -num2);
	while(num1%num2!=0 && num2%num1!=0)
	{
		if(num1>num2)
			num1 %= num2;
		else
			num2 %= num1;
	}
	return (num1<num2)?num1:num2;
}

int main() {
	int h, i, j, k, l;
	int t, n, m, d;
	int max_a = 1000;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &d);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int g = gcd(n, d);
		int longest = 0;
		for(i=0; i<g; i++) {
			int loop = 0;
			int count = 0;
			for(j=i; loop<2; j=(j+d)%n) {
				if(a[j]) {
					count++;
					longest = max(longest, count);
				} else {
					count = 0;
				}
				if((j+d)%n == i) {
					loop++;
				}
			}
		}
		if(longest >= n/g) {
			printf("-1\n");
		} else {
			printf("%d\n", longest);
		}
	}
}