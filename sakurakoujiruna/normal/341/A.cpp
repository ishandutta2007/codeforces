#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100011;
typedef long long intl;

intl gcd(intl a, intl b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

intl a[N];

int main()
{
	ios :: sync_with_stdio(false);

	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	intl den = n;
	intl num = 0;
	/*
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			if(i != j)
				num += abs(a[i] - a[j]);
	*/
	sort(a, a + n);
	intl sum = 0;
	for(int i = 0; i < n; i ++)
	{
		num += 2 * (a[i] * i - sum);
		sum += a[i];
	}

	for(int i = 0; i < n; i ++)
		num += a[i];

	intl g = gcd(num, den);
	num /= g;
	den /= g;

	cout << num << ' ' << den << '\n';

	return 0;
}