#include <stdio.h>
#include <stdlib.h>

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
	int i, j;
	int t;
	int n;
	int x, y;
	int max;
	long long m;
	long long mt;
	scanf("%d", &t);
	for(i=0; i<t; i++) {
		scanf("%d", &n);
		long long a[n];
		for(j=0; j<n; j++) {
			scanf("%lld", &a[j]);
		}
		max = 0;
		x = 0;
		y = 1;
		m = 0;
		while(y < n || y-x > max) {
			if(m != 1) {
				if(y-x > max) {
					max = y-x;
				}
				m = gcd(m, llabs(a[y]-a[x]));
				if(y == n) {
					break;
				}
				y++;
			} else {
				mt = 0;
				for(j=y-2; j>x; j--) {
					if(gcd(mt, a[y-1]-a[j]) == 1) {
						break;
					}
					mt = gcd(mt, llabs(a[y-1]-a[j]));
				}
				x = j+1;
				m = mt;
			}
		}
		printf("%d\n", max);
	}
}