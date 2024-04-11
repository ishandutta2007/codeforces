#include <stdio.h>
#include <math.h>
#define ll long long

using namespace std;

double sqr(double x) 
{
	return x * x;
}

bool isSqr(double n) 
{
	return sqr(ceil(sqrt(n))) == n;
	
	ll L = 0;
	ll R = 10000;
	while (R - L > 1) 
	{
		ll M = (R + L) / 2;
		if (M * M < n)
			L = M;
		else 
			R = M;
	}
	return n == R * R;
}

int main() 
{
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int a = 1; a <= n; ++a)
		for (int b = a; b <= n && (a * a + b * b <= n * n); ++b)
			if (isSqr(a * a + b * b)) ++cnt;
	printf("%d", cnt);
}