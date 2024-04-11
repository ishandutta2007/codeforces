#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

long long res[N], n;

long long fastPow(long long base, long long exp)
{
	if(base == 0)
		return 0;

	if(exp == 0)
		return 1;

	long long res = 1;

	if(exp % 2 == 1)
		res = base;

	long long tmp = fastPow(base, exp / 2);

	res *= tmp;
	res %= n;

	res *= tmp;
	res %= n;

	return res;
}

int main ()
{
	cin >> n;

	if(n == 4)
	{
		cout << "YES\n1\n3\n2\n4\n";

		return 0;
	}

	for(int i = 2; i*i <= n; i++)
		if(n % i == 0)
		{
			cout << "NO\n";

			return 0;
		}

	cout << "YES\n";

	res[0] = 1;
	
	for(int i = 1; i < n; i++)
	{
		res[i] = (fastPow(max(i-1, 1), n - 2) * i) % n;

		while(res[i] < 0)
			res[i] += n;
	}

	res[n] = n;

	for(int i = 1; i <= n; i++)
		cout << res[i] << "\n";

	return 0;
}