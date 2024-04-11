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
	int h, i, j;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int g = a[0];
		int max = a[0];
		for(i=1; i<n; i++) {
			g = gcd(g, a[i]);
			max = std::max(max, a[i]);
		}
		int zero = 0;
		int neg = 0;
		for(i=0; i<n; i++) {
			if(a[i] == 0) {
				zero = 1;
			}
			if(a[i] < 0) {
				neg = 1;
			}
		}
		int k = max/g;
		if(zero) {
			k++;
		}
		if(neg || k > 300) {
			printf("NO\n");
		} else if(k <= 300) {
			printf("YES\n");
			printf("%d\n", k);
			if(zero) {
				k--;
				printf("0 ");
			}
			for(i=1; i<=k; i++) {
				printf("%d ", g*i);
			}
			printf("\n");
		}
	}
}