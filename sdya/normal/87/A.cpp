#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

long long a, b, c;
long long d;

long long gcd(long long a, long long b)
{
	if (a == 0LL || b == 0LL) return a + b;
	if (a > b) return gcd(a % b, b);
	return gcd(b % a, a);
}

long long x[2100000];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> a >> b;
	d = gcd(a, b);
	c = (a / d) * b;

	long long u = a, v = b;
	int k = 0;
	while (u < c || v < c)
		if (u < v) k ++, x[k] = u, u += a; else k ++, x[k] = v, v += b;

	k ++, x[k] = c;
	long long s1 = 0, s2 = 0;
	for (int i = 1; i <= k; i ++)
		if (x[i] % a == 0 && x[i] % b == 0)
		{
			if (a > b) s1 += x[i] - x[i - 1]; else s2 += x[i] - x[i - 1];
		} else
			if (x[i] % a == 0)
			{
				s1 += x[i] - x[i - 1];
			} else
			if (x[i] % b == 0)
			{
				s2 += x[i] - x[i - 1];
			}
	if (s1 > s2)
		printf("Dasha\n"); else
		if (s1 < s2)
			printf("Masha\n"); else
			printf("Equal\n");
	return 0;
}