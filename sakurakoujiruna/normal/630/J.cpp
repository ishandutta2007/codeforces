#include <iostream>
using namespace std;

typedef long long intl;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	intl n;
	cin >> n;

	int g = 2;
	for(int i = 3; i <= 10; i ++)
		g = g * i / gcd(i, g);
	cout << n / g << '\n';
	return 0;
}