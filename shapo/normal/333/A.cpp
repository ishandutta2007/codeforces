#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

long long n;

long long ans(long long x)
{
	return (x / 3) + 1;
}

int main()
{
	cin >> n;
	while (n % 3 == 0)
	{
		n /= 3;
	}
	cout << n / 3 + 1 << endl;
	return 0;
}