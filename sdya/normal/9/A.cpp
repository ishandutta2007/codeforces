#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int p = 6 - max(a, b) + 1, q = 6;
	int d = __gcd(p, q);
	p /= d, q /= d;
	printf("%d/%d\n", p, q);
	return 0;
}