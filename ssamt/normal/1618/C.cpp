#include <bits/stdc++.h>

using namespace std;

long long gcd(long long num1, long long num2)//greatest common divisor
{
	if(num1<0)
		return gcd(-num1, num2);
	if(num2<0)
		return gcd(num1, -num2);
	if(num1 == 0)
		return num2;
	if(num2 == 0)
		return num1;
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
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		long long a[n];
		for(i=0; i<n; i++) {
			scanf("%lld", &a[i]);
		}
		long long find = 0;
		for(i=0; i<2; i++) {
			long long g = a[i];
			for(j=i+2; j<n; j+=2) {
				g = gcd(g, a[j]);
			}
			int check = 1;
			for(j=(i+1)%2; j<n; j+=2) {
				if(a[j]%g == 0) {
					check = 0;
				}
			}
			if(check) {
				find = g;
			}
		}
		printf("%lld\n", find);
	}
}