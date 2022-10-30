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
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		int a[n], b[m];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; i<m; i++) {
			scanf("%d", &b[i]);
		}
		int g = b[0];
		for(i=1; i<m; i++) {
			g = gcd(g, b[i]);
		}
		int count[g] = {};
		int min_neg[g];
		for(i=0; i<g; i++) {
			min_neg[i] = INT_MAX;
		}
		for(i=0; i<n; i++) {
			if(a[i] < 0) {
				count[i%g]++;
			}
			min_neg[i%g] = min(min_neg[i%g], abs(a[i]));
		}
		long long par[2] = {};
		for(i=0; i<g; i++) {
			par[count[i]%2] += min_neg[i];
		}
		long long sum = 0;
		for(i=0; i<n; i++) {
			sum += abs(a[i]);
		}
		long long answer = sum-2*min(par[0], par[1]);
		printf("%lld\n", answer);
	}
}