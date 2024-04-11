#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

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
	int h, i, j, k;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int even = 0;
		for(i=0; i<n; i++) {
			if(a[i]%2 == 0) {
				even++;
			}
		}
		int answer = 0;
		for(i=0; i<n; i++) {
			for(j=i+1; j<n; j++) {
				if(a[i]%2 == 1 && a[j]%2 == 1) {
					if(gcd(a[i], a[j]) > 1) {
						answer++;
					}
				}
			}
		}
		printf("%d\n", (n-1+n-even)*even/2+answer);
	}
}