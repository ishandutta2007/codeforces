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
	int u, v;
	int in;
	scanf("%d", &n);
	int size = 1000000;
	int a[size+1] = {};
	for(i=0; i<n; i++) {
		scanf("%d", &in);
		a[in] = 1;
	}
	int b[size+1] = {};
	for(i=1; i<=size; i++) {
		for(j=1; i*j<=size; j++) {
			if(a[i*j]) {
				b[i] = gcd(b[i], j);
			}
			if(b[i] == 1) {
				break;
			}
		}
	}
	int count = 0;
	for(i=1; i<=size; i++) {
		if(b[i] == 1) {
			count++;
		}
	}
	printf("%d\n", count-n);
}