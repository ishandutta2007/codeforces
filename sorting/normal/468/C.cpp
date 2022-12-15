#include <bits/stdc++.h>

using namespace std;

unsigned long long a;

unsigned long long my_pow(unsigned long long base, unsigned long long exp)
{
	unsigned long long res = 1;

	for(int i = 1; i <= exp; i++)
		res *= base;

	return res;
}

unsigned long long g(unsigned long long x)
{
	unsigned long long res =  x * my_pow(10, x-1);

	res %= a;
	res *= 5;
	res %= a;
	res *= 9;
	res %= a;

	return res;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	

	cin >> a;

	unsigned long long x = g(18);
	x %= a;
	x = a-x;
	unsigned long long t = (x + my_pow(10, 18) - 1 );

	cout << x << " " << t << "\n";

	return 0;
}