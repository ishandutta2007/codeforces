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

	intl acc = 0;
	for(int k = 1; k < (1 << 9); k ++)
	{
		int cnt = __builtin_popcount(k);
		int l = 1;
		for(int i = 0; i < 9; i ++)
			if((k >> i) & 1)
				l = l * (i + 2) / gcd(l, i + 2);
		if(cnt & 1)
			acc += n / l;
		else
			acc -= n / l;
	}
	cout << n - acc << '\n';
	return 0;
}