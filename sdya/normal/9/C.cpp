#include <iostream>

using namespace std;

long long value(long long n)
{
	long long a[20], k = 0;
	while (n)
		k ++, a[k] = n % 2LL, n /= 2LL;
	long long res = 0LL;
	for (int i = k; i >= 1; i --)
		res = res * 10LL + a[i];
	return res;
}

int main()
{
	long long n;
	cin >> n;
	for (long long i = 1; i <= 10000; i ++)
		if (value(i) > n)
		{
			cout << i - 1 << endl;
			return 0;
		}
	return 0;
}